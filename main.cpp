#include "department.h"
#include "preference.h"
#include "student.h"

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
    }
}

void G_S(vector<student> students, vector<department> departments){
    int s_programs[students_size] = {};
    int freeCount = departments_size;

    while (freeCount > 0) {
        vector<department>::iterator d;
        for (vector<department>::iterator it = departments.begin() ; it != departments.end(); ++it) {
            if (it->capacity > 0) {
                d = it;
                break;
            }
        }
        
        for (vector<int>::iterator it = d->preference.begin() ; it != d->preference.end(); ++it) {
            
            if (s_programs[*it-1] == 0) {
                s_programs[*it-1] = d->id;
                d->capacity--;
                if (d->capacity == 0) {
                    freeCount--;
                    break;
                }
            }
            else {
                if ((find(students[*it-1].preference.begin(),students[*it-1].preference.end(),d->id)-students[*it-1].preference.begin())<(find(students[*it-1].preference.begin(),students[*it-1].preference.end(),s_programs)-students[*it-1].preference.begin())) {
                    s_programs[*it-1] = d->id;
                    d->capacity--;
                    if (d->capacity == 0) {
                        freeCount--;
                        break;
                    }
                }
            }
        }
    }
}

int main(){
    init();

}
