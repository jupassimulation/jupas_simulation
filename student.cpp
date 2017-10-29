#include "student.h"
student::student(int Id,studentquality sq):id(Id){
    sq.sq(quality);
    sp=new studentpre;
    assign=0;
    std::cout<<"this is a stu "<<id<<std::endl;
}

student::student(const student& A):quality(A.quality),preference(A.preference),id(A.id){
    sp=new studentpre(*A.sp);
}

student& student::operator=(const student& A){
    quality=A.quality,preference=A.preference; id=(A.id);
    delete sp;    
    sp=new studentpre(*A.sp);
    return *this;
}

void student::set_preference(const vector<department>& departments){
    std::cout<<"setting stu pre for stu "<<id<<std::endl;
    sp->sp(quality,departments,preference);
    std::cout<<"setting stu ran for stu "<<id<<std::endl;
    rank.resize(preference.size()+1);
    for(int i=0;i<preference.size();i++){
        rank[preference[i]]=i;
    }
    std::cout<<"finished for stu "<<id<<std::endl;
}

int student::onpre(int a){
    for(int i=0;i<preference.size();i++){
        if(preference[i]==a) return i;
    }
    return -1;
}

bool student::prefer(int new_assign){
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
