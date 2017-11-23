#ifndef HEADER_H_
#define HEADER_H_


extern int DEBUG;

struct studentpre;
struct studentquality;
struct departmentcmp;
struct departmentpre;

class department;
class student;

    void result_student_pre();
    void result_student_matching();
    void result_department_pre();
void result_dept_empty();
void process_arg(int argc,char ** argv);
#include <iostream>
#include <cstdio>

#endif
