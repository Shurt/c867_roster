#include <string>
#include <iostream>
#include "student.h"

using namespace std;

class Roster {
    protected:
        int lastIndex = -1;
        
    public:
        Student** classRoster;
        int class_size;
        Roster();
        Roster(int class_size);
        ~Roster();
        void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram);

        void remove(string studentID);

        void printAll();

        void printStudent(string studentID);

        void printAverageDaysInCourse(string studentID);

        void printInvalidEmails();

        void printByDegreeProgram(DegreeProgram degreeProgram);


};