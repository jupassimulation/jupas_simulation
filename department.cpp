#include "department.h"

department::department(int Id,int cap,vector<int> cutoff,vector<double> coef,int pre_req):capacity(cap),id(Id){
    dp = new departmentpre(Id,cutoff,coef,pre_req);
    std::cout<<"this is a dept "<<id<<" "<<cap<<std::endl;
}

department::department(const department& A):preference(A.preference),id(A.id),capacity(A.capacity){    
    std::cout<<"copying dept "<<id<<std::endl;
    dp=new departmentpre(*A.dp);
    std::cout<<"copy dept finished "<<id<<std::endl;
}

void department::set_preference(const vector<student>& students){
    std::cout<<"setting pre for dept "<<id<<std::endl;
    dp->dp(students,preference);
    std::cout<<"finished setting pre for dept "<<id<<std::endl;
}

department::~department(){
    delete dp;
}
/*
void department::set_preference_func(void Preference_func(const vector<student>&,vector<int> &)){
    preference_func=Preference_func;
}*/
