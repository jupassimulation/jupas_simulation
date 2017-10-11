#include "department.h"
department::department(int Id,int cap,departmentpre *p):capacity(cap),id(Id),dp(p){
}

department::department(const department& A):preference(A.preference),id(A.id),capacity(A.capacity),dp(A.dp){
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
