#ifndef STUDENT_H_
#define STUDENT_H_

#include "header.h"
#include "department.h"
#include "preference.h"
#include <vector>

using std::vector;

class student{
public:
    int id;
    vector<int> quality;
    vector<int> preference;
    vector<int> rank;
    studentpre *sp;

    student(int Id,studentquality sq=studentquality(),studentpre *p=new studentpre);
    student(const student &);
    ~student();
    void set_preference(const vector<department>&);
    //void set_preference_func(studentpre *p);
    int get_quality(int) const;
    int get_id()const;
};
/*
 class student{
 int id;
 vector<int> quality;
 vector<int> preference;
 studentpre *sp;
 public:
 student(int Id,studentquality sq=studentquality(),studentpre *p=new studentpre);
 student(const student &);
 ~student();
 void set_preference(const vector<department>&);
 //void set_preference_func(studentpre *p);
 int get_quality(int) const;
 int get_id()const;
 };
 */

#endif
