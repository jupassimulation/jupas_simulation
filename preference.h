#ifndef PREFERENCE_H_
#define PREFERENCE_H_

#include "header.h"
#include <vector>

using std::vector;

struct studentpre{
    virtual void sp(const vector<int>&,const vector<department>&,vector<int> &);
};

struct studentquality{
    virtual void sq(vector<int>&);
};

struct departmentcmp{
    vector<int> cutoff;
    vector<double> coef;
    int pre_req;
    departmentcmp(vector<int> co,vector<double> ce,int r);
    virtual bool operator()(const student&,const student&);
};

struct departmentpre{
    int id;
    vector<int> cutoff;
    vector<double> coef;
    int pre_req;
    departmentcmp *cmp;
    departmentpre(int i,vector<int> co,vector<double> ce,int r=20);
    departmentpre(const departmentpre &);
    virtual void dp(const vector<student>&,vector<int> &);
    virtual ~departmentpre();
};

#endif
