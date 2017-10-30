#include "department.h"
#include "preference.h"
#include "student.h"

#include <cstring>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

using namespace std;

int students_size;
int departments_size;
int quality_size = 5;

vector<student> students;
vector<department> departments;

ifstream fin_stu("data/input/student.txt");
ifstream fin_dept("data/input/department.txt");

void init(){
    if(!DEBUG){
        fin_stu >> students_size;
        fin_dept >> departments_size;
    }
    else{
        students_size=6;
        departments_size=3;
    }
    
    
    students.push_back(student(0));
    departments.push_back(department(0,0x7fffffff,vector<int>(5,0),vector<double>(5,0)));
    for(int id=1;id<=students_size;id++){
        students.push_back(student(id));
    }
    int tmp;
    vector<int> co(5);
    vector<double> ce(5);
    for(int id=1;id<=departments_size;id++){
        if(!DEBUG)fin_dept >> tmp;
        else tmp=2;
        for(int i=0;i<5;i++){
            co[i]=rand()%6;
            ce[i]=(rand()%1000)/1000.0;
        }
        departments.push_back(department(id,tmp,co,ce));
        //cout << id << endl;
    }
    for(int id=1;id<=students_size;id++){
        students[id].set_preference(departments);
    }
    for(int id=1;id<=departments_size;id++){
        departments[id].set_preference(students);
    }
}

//int s_programs[students_size];;
vector< vector<int>::iterator > pointer;
void G_S(/*vector<student> students, vector<department> departments*/){
    //    int total_capacity = 0;
    //    for (int i = 0; i < departments_size; i++) {
    //        total_capacity += departments_cap[i];
    //    }
    //    int free_count = departments_size;
    
    //    memset(s_programs,0,sizeof(s_programs));
    pointer.resize(departments_size+1);
    for(int i=0;i<departments_size+1;i++)
        pointer[i]=departments[i].preference.begin();
    while (true) {
        vector<department>::iterator d = departments.end();
        for (vector<department>::iterator it = departments.begin()+1 ; it != departments.end(); ++it) {
            if (it->capacity > 0 && pointer[it->id] != d->preference.end()) {
                d = it;
                break;
            }
        }
        if (d==departments.end()) return;
#define it (pointer[d->id])
        for (; it != d->preference.end() && d->capacity > 0; ++it) {
            if (students[*it].assign == 0) {
                students[*it].assign = d->id;
                d->capacity--;
            }
            else if (students[*it].prefer(d->id)) {
                departments[students[*it].assign].capacity++;
                students[*it].assign = d->id;
                d->capacity--;
            }
        }
#undef it
    }
}

int main(){
    srand(time(0));
    init();
    cout<<"hello"<<endl;
    G_S();
    for(int i=1;i<=students_size;i++){
        cout<<students[i].id<<'\t'<<students[i].assign<<endl;
    }
    for(int i=0;i<departments_size;i++){
        cout << endl;
        cout<<departments[i].id<< '\t' <<departments[i].capacity<<endl;
    }
    cout<<endl;
}
