#include "department.h"
#include "preference.h"
#include "student.h"

#include <cstring>
#include <iostream>

using namespace std;

const int students_size=100;
const int departments_size=10;
const int departments_cap=10; // may be a vector

vector<student> students;
vector<department> departments;
studentquality *sq=new studentquality;
studentpre *sp=new studentpre;
departmentpre *dp=new departmentpre;

void init(){
    for(int id=1;id<=students_size;id++){
        students.push_back(student(id));
    }

    for(int id=1;id<=departments_size;id++){
        departments.push_back(department(id,departments_cap));
        //cout << id << endl;
    }
    for(int id=1;id<=students_size;id++){
        students[id-1].set_preference(departments);
    }
    for(int id=1;id<=departments_size;id++){
        departments[id-1].set_preference(students);
    }    
}

int s_programs[students_size];
vector<int>::iterator pointer[departments_size];
void G_S(/*vector<student> students, vector<department> departments*/){
    int freeCount = students_size;
    memset(s_programs,0,sizeof(s_programs));
    for(int i=0;i<departments_size;i++)pointer[i]=departments[i].preference.begin();
    while (freeCount > 0) {
        vector<department>::iterator d;
        for (vector<department>::iterator it = departments.begin() ; it != departments.end(); ++it) {
            if (it->capacity > 0) {
                d = it;
                break;
            }
        }
        #define it (pointer[d->id-1])
        for (; it != d->preference.end(); ++it) {
            
            if (s_programs[*it-1] == 0) {
                s_programs[*it-1] = d->id;
                d->capacity--;
                freeCount--;
                if (d->capacity == 0) {
                    break;
                }
            }
            else {
                if (students[*it-1].rank[d->id]<students[*it-1].rank[s_programs[*it-1]]){
                    departments[s_programs[*it-1]-1].capacity++;
                    s_programs[*it-1] = d->id;
                    d->capacity--;
                    if (d->capacity == 0) {
                        break;
                    }
                }
            }
        }
        #undef it
    }
}

int main(){
    init();
    cout<<"hello"<<endl;
    G_S();
    for(int i=0;i<students_size;i++){
        cout<<s_programs[i]<<' ';
    }
    for(int i=0;i<departments_size;i++){
        cout << endl;
        cout<<departments[i].id<< ' ' <<departments[i].capacity<<' ';
    }
    cout<<endl;
}
