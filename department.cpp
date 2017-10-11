#include "department.h"

department::department(int Id,int cap,departmentpre *p):capacity(cap),id(Id),dp(p){    
    std::cout<<"this is a dept "<<id<<" "<<cap<<std::endl;
}

department::department(const department& A):preference(A.preference),id(A.id),capacity(A.capacity){
    dp=new departmentpre;*dp=(*A.dp);
}

void department::set_preference(const vector<student>& students){
    dp->dp(students,preference);
}

department::~department(){
    delete dp;
}
/*
void department::set_preference_func(void Preference_func(const vector<student>&,vector<int> &)){
    preference_func=Preference_func;
}*/
