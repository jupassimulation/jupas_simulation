#include "student.h"
student::student(int Id,studentquality sq, studentpre *p):id(Id),sp(p){
    sq.sq(quality);
}

student::student(const student& A):quality(A.quality),preference(A.preference),id(A.id),sp(A.sp){
}

void student::set_preference(const vector<department>& departments){
    sp->sp(quality,departments,preference);
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
