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
    for(int i=0;i<quality_size;i++)qua.push_back(rand()%5+3);
}

void departmentpre::dp(const vector<student> &stu,vector<int> &qua){
    std::cout<<"dept pre here"<<std::endl;
    vector<student> students;
    bool check;
    for(int i=1;i<stu.size();i++){
        check=1;
        if( stu[i].onpre(id)<0 || stu[i].onpre(id)>=pre_req)continue;
        std::cout<<"--student "<<i<<std::endl;
        for(int j=0;j<cutoff.size();j++){
            std::cout<<"----"<<stu[i].quality[j]<<" "<<cutoff[j]<<' '<<std::endl;

        }
        for(int j=0;j<cutoff.size()&&check;j++){
            if(stu[i].quality[j]<cutoff[j])check=0;
        }
        if(check)students.push_back(stu[i]);
    }
    std::cout<<"checking finished, "<<students.size()<<" left"<<std::endl;    
    if(students.size()==0){
        qua.clear();
        return;
    }
    sort(students.begin(),students.end(),*cmp);
    qua.resize(stu.size());
    for(int i=0;i<stu.size();i++)qua[i]=students[i].id;
}

departmentpre::departmentpre(int i,vector<int> co,vector<double> ce,int r):id(i),cutoff(co),coef(ce),pre_req(r)
{
    cmp=new departmentcmp(co,ce,r);
}

departmentpre::departmentpre(const departmentpre &A):id(A.id),cutoff(A.cutoff),coef(A.coef),pre_req(A.pre_req){
    cmp=new departmentcmp(*A.cmp);
}
departmentpre::~departmentpre(){delete cmp;}



departmentcmp::departmentcmp(vector<int> co,vector<double> ce,int r):cutoff(co),coef(ce),pre_req(r){
}


bool departmentcmp::operator()(const student &A,const student& B){
    double a=0,b=0;
    for(int i=0;i<coef.size();i++){
        a+=coef[i]*A.quality[i];
        b+=coef[i]*B.quality[i];
    }
    return a>b;
}
