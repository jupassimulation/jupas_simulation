#ifndef DEPARTMENT_H_
#define DEPARTMENT_H_


#include "header.h"
#include "student.h"
#include "preference.h"
#include <vector>

using std::vector;

class department{
public:
    int id;
    int capacity;
    vector<int> preference; 
    departmentpre *dp;
    
    department(int Id,int cap,vector<int> cutoff,vector<double> coef,int pre_req=20);
    department(const department &);
    void set_preference(const vector<student>&);
    ~department();
    //void set_preference_func(void Preference_func(const vector<student>&,vector<int> &));
};

/*
 class department{
 int id;
 int capacity;
 vector<int> preference;
 departmentpre *dp;
 public:
 department(int Id,int cap,departmentpre *p=new departmentpre);
 department(const department &);
 void set_preference(const vector<student>&);
 ~department();
 //void set_preference_func(void Preference_func(const vector<student>&,vector<int> &));
 };
*/

#endif
