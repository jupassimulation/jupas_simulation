#include "student.h"
student::student(int Id,studentquality sq, studentpre *p):id(Id),sp(p){
    sq.sq(quality);
    std::cout<<"this is a stu "<<id<<std::endl;
}

student::student(const student& A):quality(A.quality),preference(A.preference),id(A.id),sp(A.sp){
}

void student::set_preference(const vector<department>& departments){
    sp->sp(quality,departments,preference);
    rank.resize(preference.size()+1);
    for(int i=0;i<preference.size();i++){
        rank[preference[i]]=i;
    }
}

/*void student::set_preference_func(void Preference_func(const vector<int>&,const vector<department>&,vector<int> &)){
    preference_func=Preference_func;
}*/

int student::get_quality(int ind)const{
    return quality[ind];
}

int student::get_id()const{
    return id;
}

student::~student(){
    delete sp;
}
