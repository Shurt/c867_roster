// Implement functions here
#include "student.h"

// Initialize the class with empty variables
Student::Student() {
    student_ID = "";
    first_name = "";
    last_name = "";
    email_addr = "";
    age = 0;
    days_to_complete_program[3] = { };
    degree = NONE;
}

Student::Student(string student_ID_num, string student_first, string student_last, string student_email, int student_age, int* student_daysToComplete, DegreeProgram student_degreeProgram) {
    student_ID = student_ID_num;
    first_name = student_first;
    last_name = student_last;
    email_addr = student_email;
    age = student_age;
    days_to_complete_program[0] = student_daysToComplete[0];
    days_to_complete_program[1] = student_daysToComplete[1];
    days_to_complete_program[2] = student_daysToComplete[2];
    degree = student_degreeProgram;
}

// Grouping 'Setter' methods here:
void Student::setID(string student_ID_num) {
     student_ID = student_ID_num;
}
void Student::setFirst(string student_first) {
    first_name = student_first;
}
void Student::setLast(string student_last) {
    last_name = student_last;
}
void Student::setEmailAddr(string student_email) {
    email_addr = student_email;
}
void Student::setStudentAge(int student_age) {
    age = student_age;
}
void Student::setDaysToComplete(int student_daysToComplete_1, int student_daysToComplete_2, int student_daysToComplete_3) {
    days_to_complete_program[0] = student_daysToComplete_1;
    days_to_complete_program[1] = student_daysToComplete_2;
    days_to_complete_program[2] = student_daysToComplete_3;
}
void Student::setDegree(DegreeProgram student_degreeProgram) {
    degree = student_degreeProgram;
}

// And the 'Getter' methods here:
string Student::getID() {
    return student_ID;
}
string Student::getFirst() {
    return first_name;
}
string Student::getLast() {
    return last_name;
}
string Student::getEmail() {
    return email_addr;
}
int Student::getAge() {
    return age;
}
int* Student::getDaysToComplete() {
    return days_to_complete_program;
}
DegreeProgram Student::getDegree() {
    return degree;
}

void Student::print() {
    cout << this ->getID() << '\t';
    cout << this ->getFirst() << '\t';
    cout << this ->getLast() << '\t';
    cout << this ->getEmail() << '\t';
    cout << this ->getAge() << '\t';
    cout << this ->getDaysToComplete()[0] << ',';
    cout << this ->getDaysToComplete()[1] << ',';
    cout << this ->getDaysToComplete()[2] << '\t';
    cout << textDegrees[this ->getDegree()] << '\n';
}