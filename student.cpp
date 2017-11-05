#include "student.h"
student::student(int Id,studentquality sq):id(Id){
    sq.sq(quality);
    sp=new studentpre;
    assign=0;
//    std::cout<<"this is a stu "<<id<<std::endl;
}

student::student(const student& A):quality(A.quality),preference(A.preference),id(A.id),assign(A.assign){
    sp=new studentpre(*A.sp);
}

student& student::operator=(const student& A){
    quality=A.quality,preference=A.preference; id=(A.id);
    assign=A.assign;
    delete sp;
    sp=new studentpre(*A.sp);
    return *this;
}

void student::set_preference(const vector<department>& departments){
    std::cout<<"setting stu pre for stu "<<id<<std::endl;
    sp->sp(quality,departments,preference);
    for(int i=0;i<preference.size();i++)std::cout<<preference[i]<<' ';std::cout<<std::endl;
}

int student::onpre(int a) const{
    for(int i=0;i<preference.size();i++){
        if(preference[i]==a) return i;
    }
    return -1;
}

bool student::prefer(int new_assign)const{
    if(onpre(new_assign)<0)return 0;
    if(onpre(assign)<0) return 1;
    return onpre(new_assign)<onpre(assign);
}

/*void student::set_preference_func(void Preference_func(const vector<int>&,const vector<department>&,vector<int> &)){
    preference_func=Preference_func;
}*/
/*
int student::get_quality(int ind)const{
    return quality[ind];
}

int student::get_id()const{
    return id;
}
*/
student::~student(){
    delete sp;
}
