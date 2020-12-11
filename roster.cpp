#include <string>
#include <iostream>
#include "roster.h"

using namespace std;

Roster::Roster() {
	this->lastIndex = -1;
	this->classRoster = nullptr;
}

Roster::Roster(int class_size) {
    this->class_size = class_size;
	this->lastIndex = -1;
	this->classRoster = new Student * [class_size];
}

Roster::~Roster() {
    for (int i = 0; i < class_size; i++) {
        delete this->classRoster[i];
    }
    delete this;
}

void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram) {
    int days_arr[3] = {daysInCourse1, daysInCourse2, daysInCourse3};

    classRoster[++lastIndex] = new Student(studentID, firstName, lastName, emailAddress, age, days_arr, degreeProgram);
}

void Roster::remove(string studentID) {
    bool student_found = false;

    for (int i=0; i<=this->lastIndex;i++) {
        if (this->classRoster[i]->getID() == studentID) {
            student_found = true;
            delete this->classRoster[i];
            this->classRoster[i] = this->classRoster[lastIndex];
            lastIndex--;
        }
    }

    if (!student_found) {
        cout << "Student ID " << studentID << " was not found.";
    }

}

void Roster::printAll() {
    for (int i=0; i<= this->lastIndex; i++) {
        this->classRoster[i]->print();
    }
}

void Roster::printStudent(string studentID) {
    bool student_found = false;

    for (int i=0; i<=this->lastIndex;i++) {
        if (this->classRoster[i]->getID() == studentID) {
            student_found = true;
            this->classRoster[i]->print();
        }
    }

    if (!student_found) {
        cout << "Student ID " << studentID << " was not found.";
    }
}

void Roster::printAverageDaysInCourse(string studentID) {
    bool student_found = false;

    for (int i=0; i<=this->lastIndex;i++) {
        if (this->classRoster[i]->getID() == studentID) {
            student_found = true;
            int* avg_days = classRoster[i]->getDaysToComplete();
            cout << "Student " << studentID << " took, on average, " << (avg_days[0] + avg_days[1] + avg_days[2]) / 3 << " days to complete courses." << endl;
        }
    }

    if (!student_found) {
        cout << "Student ID " << studentID << " was not found.";
    }
}

void Roster::printInvalidEmails() {
    bool invalid_email_found = false;

    for (int i=0; i<=this->lastIndex;i++) {
        string email = this->classRoster[i]->getEmail();
        if ((email.find('@') == string::npos) || (email.find('.') == string::npos) || (email.find(' ') != string::npos)) {

            invalid_email_found = true;

            cout << "Student " << this->classRoster[i]->getID() << " has an invalid email: " << this->classRoster[i]->getEmail() << endl;
        }
    }

    if (!invalid_email_found) {
        cout << "No invalid student emails were found." << endl;
    }
}

void Roster::printByDegreeProgram(DegreeProgram degree) {
    for (int i=0; i<=this->lastIndex;i++) {
        if (this->classRoster[i]->getDegree() == degree) {
            this->classRoster[i]->print();
        }
    }
}