#include "preference.h"
#include <cstdlib>
#include <ctime>
#include <algorithm>

using std::random_shuffle;

void studentpre::sp(const vector<int>& quality,const vector<department>& departments,vector<int> &pre){
    pre.resize(departments.size());
    for(int i=0;i<pre.size();i++)pre[i]=i+1;
    random_shuffle(pre.begin(),pre.end());
}

void studentquality::sq(vector<int> &qua){
    qua.push_back(rand()%1000);    
}

void departmentpre::dp(const vector<student> &stu,vector<int> &qua){
    vector<student> students=stu;
    sort(students.begin(),students.end(),*cmp);
    qua.resize(stu.size());
    for(int i=0;i<stu.size();i++)qua[i]=students[i].get_id();
}

departmentpre::departmentpre(departmentcmp *c):cmp(c){}
departmentpre::~departmentpre(){delete cmp;}

bool departmentcmp::operator()(const student &A,const student& B){
    return A.get_quality(0)>B.get_quality(0);
}
