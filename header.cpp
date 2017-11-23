#include "header.h"
#include "student.h"
#include "department.h"

#include <bits/stdc++.h>

int DEBUG=0;
extern int students_size;
extern int departments_size;
extern int quality_size;
extern int pena,preferreq;
extern std::vector<double> pre_dis[20];

extern std::vector<student> students;
extern std::vector<department> departments;
extern std::ifstream fin_pre,fin_dept;

void result_student_pre(){
    using namespace std;
    ofstream s_out("output/student_pre.csv",ios_base::app);
    for(int i=1,j;i<=students_size;i++){
        for(j=0;j<students[i].preference.size();j++)
            s_out<<students[i].preference[j]<<(j<19?",":"\n");
        for(;j<20;j++) s_out<<"0"<<(j<19?",":"\n");
    }
    s_out<<endl;
    s_out.close();
}

void result_student_matching(){
    using namespace std;
    ofstream s_out("output/student_matching.csv",ios_base::app);
    for(int i=1;i<=students_size;i++){
        s_out<<students[i].assign<<endl;
    }
    s_out<<endl;
    s_out.close();
}

void result_department_pre(){
    using namespace std;
    ofstream s_out("output/department_pre.csv",ios_base::app);
    for(int i=1,j;i<=departments_size;i++){
        for(j=0;j<departments[i].preference.size()-1;j++)
            s_out<<departments[i].preference[j]<<',';
        s_out<<departments[i].preference[j]<<endl;
    }
    s_out<<endl;
    s_out.close();
}

#include <string>
void process_arg(int argc,char ** argv){
    using std::string;
    for(int i=1;i<argc;i++){
        if(string(argv[i]).find("deptsize=")==0){
            sscanf(argv[i]+9,"%d",&departments_size);
            printf("setting departments_size=%d...\n",departments_size);
        }
        if(string(argv[i]).find("stusize=")==0){
            sscanf(argv[i]+8,"%d",&students_size);
            printf("setting students_size=%d...\n",students_size);
        }
        if(string(argv[i]).find("preferdistri=")==0){
            fin_pre.close();
            fin_pre.open(argv[i]+13);
            printf("opening distribution file \"%s\"\n",argv[i]+13);
        }
        if(string(argv[i]).find("deptcap=")==0){
            fin_dept.close();
            fin_dept.open(argv[i]+8);
            printf("opening dept file \"%s\"\n",argv[i]+8);
        }
        if(string(argv[i]).find("cutoff_p=")==0){
            sscanf(argv[i]+9,"%d",&preferreq);
            printf("setting dept 1 cutoff of preference list to be %d\n",preferreq);
        }
        if(string(argv[i]).find("penalty=")==0){
            sscanf(argv[i]+8,"%d",&pena);
            printf("setting dept 1 to have a penalty of %d on ranking if stu do not choose it as their first choice",pena);
        }
    }
}
