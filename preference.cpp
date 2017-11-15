#include "preference.h"
#include "student.h"
#include "department.h"
#include <cstdlib>
#include <ctime>
#include <algorithm>

#include <vector>

using std::random_shuffle;

extern int quality_size;
extern int students_size;
extern int distri_total;
extern int departments_size;
extern vector<double> pre_dis[20];//prefix sum

void studentpre::sp(const vector<int>& quality,const vector<department>& departments,vector<int> &pre){
    int rand_lim=distri_total;
    bool flag=true;
    int index;double tmp;
    pre.resize(0);
    for(int i=0;i<20;){
        flag=true;
        tmp=(rand()%(rand_lim*100))/100.0;
        index=upper_bound(pre_dis[i].begin(),pre_dis[i].end(),tmp)-pre_dis[i].begin();
//        printf("tmp = %.2lf, index= %d \n",tmp,index);
        if(index>departments_size){
            break;
        }
        for(int j=0;j<pre.size()&&flag;j++){
            if(pre[j]==index)flag=false;
        }
        if(!flag){
//            printf("dumped dept %d\n",index);
            continue;
        }
//        printf("added dept %d on %d\n",index,i);
        pre.push_back(index);
        rand_lim=(int)(pre_dis[i][pre_dis[i].size()-2]+1e-5);        
        i++;
    }
}

void studentquality::sq(vector<int> &qua){
    for(int i=0;i<quality_size;i++)qua.push_back(rand()%5+3);
}

void departmentpre::dp(const vector<student> &stu,vector<int> &qua){
//std::cout<<"dept pre here"<<std::endl;
    vector<student> students;
    bool check;
    for(int i=1;i<stu.size();i++){
        check=1;
        if( stu[i].onpre(id)<0 || stu[i].onpre(id)>=pre_req)continue;
//std::cout<<"--student "<<i<<std::endl;
        for(int j=0;j<cutoff.size();j++){
//std::cout<<"----"<<stu[i].quality[j]<<" "<<cutoff[j]<<' '<<std::endl;

        }
        for(int j=0;j<cutoff.size()&&check;j++){
            if(stu[i].quality[j]<cutoff[j])check=0;
        }
        if(check)students.push_back(stu[i]);
    }
//std::cout<<"checking finished, "<<students.size()<<" left"<<std::endl;    
    if(students.size()==0){
        qua.clear();
        return;
    }
    vector<bool> checked(students_size,false);
    sort(students.begin(),students.end(),*cmp);
    qua.resize(students.size());
    for(int i=0;i<students.size();){
        if(!checked[students[i].id] && students[i].onpre(id)!=0){
            checked[students[i].id]=true;
            if(penalty>0)std::cout<<"moving student "<<students[i].id<<" to "<<penalty<< " lower"<<std::endl;
            for(int j=1;j<penalty&&i+j<students.size();j++){
                std::swap(students[i+j-1],students[i+j]);
            }
            continue;
        }
        i++;
    }
    for(int i=0;i<students.size();i++)qua[i]=students[i].id;
}

departmentpre::departmentpre(int i,vector<int> co,vector<double> ce,int r,int pen):id(i),cutoff(co),coef(ce),pre_req(r),penalty(pen)
{
    cmp=new departmentcmp(co,ce,r);
}

departmentpre::departmentpre(const departmentpre &A):id(A.id),cutoff(A.cutoff),coef(A.coef),pre_req(A.pre_req),penalty(A.penalty){
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
