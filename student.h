#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <iostream>
#include "degree.h"

using namespace std;

class Student {
    public:
        // Constructor for the Student class.
        Student();
        Student(string student_ID_num, string student_first, string student_last, string student_email, int student_age, int*student_daysToComplete,  DegreeProgram student_degreeProgram);

        // 'Getter' methods:
        string getID();
        string getFirst();
        string getLast();
        string getEmail();
        int getAge();
        int* getDaysToComplete();
        DegreeProgram getDegree();

        // 'Setters' methods:
        void setID(string student_ID_num);
        void setFirst(string student_first);
        void setLast(string student_last);
        void setEmailAddr(string student_email);
        void setStudentAge(int student_age);
        void setDaysToComplete(int student_daysToComplete_1, int student_daysToComplete_2, int student_daysToComplete_3);
        void setDegree(DegreeProgram student_degree);

        void print();
        string textDegrees[4] = {"SECURITY", "NETWORK", "SOFTWARE", "NONE"};

        const int course_completion = 3;

    protected:
        string student_ID;
        string first_name;
        string last_name;
        string email_addr;
        int age;
        int days_to_complete_program[3];
        DegreeProgram degree;
};

#endif