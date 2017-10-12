#include "preference.h"
#include "student.h"
#include "department.h"
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
    std::cout<<"dp running "<<std::endl;
    vector<student> students=stu;
    std::cout<<"checking sort"<<std::endl;
    for(int i=0;i<students.size();i++){
        std::cout<<students[i].id<<' '<<students[i].quality[0]<<std::endl;
    }
    std::cout<<"chk fished "<<std::endl;
    sort(students.begin(),students.end(),*cmp);
    std::cout<<"sort finished"<<std::endl;
    qua.resize(stu.size());
    for(int i=0;i<stu.size();i++)qua[i]=students[i].get_id();
    std::cout<<"dp ended "<<std::endl;
}

departmentpre::departmentpre(departmentcmp *c):cmp(c){std::cout<<"dp here"<<std::endl;}
departmentpre::departmentpre(const departmentpre &A){    
    std::cout<<"copy dp begin"<<std::endl;
    cmp=new departmentcmp(*A.cmp);
    std::cout<<"copy dp finished"<<std::endl;
}
departmentpre::~departmentpre(){delete cmp;}

bool departmentcmp::operator()(const student &A,const student& B){
    std::cout<<A.id<<' '<<B.id<<std::endl;
    return A.get_quality(0)>B.get_quality(0);
}
