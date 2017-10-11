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
    virtual bool operator()(const student&,const student&);
};

struct departmentpre{
    departmentcmp *cmp;
    departmentpre(departmentcmp *c=new departmentcmp);
    virtual void dp(const vector<student>&,vector<int> &);
    virtual ~departmentpre();
};

#endif
