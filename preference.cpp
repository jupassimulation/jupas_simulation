#include "preference.h"
#include "student.h"
#include "department.h"
#include <cstdlib>
#include <ctime>
#include <algorithm>


using std::random_shuffle;

extern int quality_size;

void studentpre::sp(const vector<int>& quality,const vector<department>& departments,vector<int> &pre){
    pre.resize(departments.size());
    for(int i=0;i<pre.size();i++)pre[i]=i+1;
    random_shuffle(pre.begin(),pre.end());
    pre.resize(20);
}

void studentquality::sq(vector<int> &qua){
    for(int i=0;i<quality_size;i++)qua.push_back(rand()%2+6);
}

void departmentpre::dp(const vector<student> &stu,vector<int> &qua){
    vector<student> students;
    bool check;
    for(int i=0;i<stu.size();i++){
        check=1;
        if( stu[i].onpre(id)<0 || stu[i].onpre(id)>=pre_req)continue;
        for(int j=0;j<cutoff.size()&&check;j++){
            if(stu[i].preference[j]<cutoff[j])check=0;
        }
        if(check)students.push_back(stu[i]);
    }
    sort(students.begin(),students.end(),*cmp);
    qua.resize(stu.size());
    for(int i=0;i<stu.size();i++)qua[i]=students[i].id;
}

departmentpre::departmentpre(int i,vector<int> co,vector<double> ce,int r):id(i),cutoff(co),coef(ce),pre_req(r)
{
    cmp=new departmentcmp(co,ce,r);
}

departmentpre::departmentpre(const departmentpre &A){
    cmp=new departmentcmp(*A.cmp);
}
departmentpre::~departmentpre(){delete cmp;}



departmentcmp::departmentcmp(vector<int> co,vector<double> ce,int r),cutoff(co),coef(ce),pre_req(r){
}


bool departmentcmp::operator()(const student &A,const student& B){
    double a=0,b=0;
    for(int i=0;i<coef.size();i++){
        a+=coef[i]*A.quality[i];
        b+=coef[i]*B.quality[i];
    }
    return a>b;
}
