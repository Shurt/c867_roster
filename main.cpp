/*

Author: Kyle Kuypers
Student ID: 000432742
Course: C867 - 

*/

#include <iostream>
#include <vector>
#include <string>
#include <sstream>

#include "roster.h"

using namespace std;

int main() {
    cout << "Scripting and Programming - Applications - C867" << endl;
    cout << "Coded in C++" << endl;
    cout << "Name: Kyle Kuypers" << endl;
    cout << "Student ID: 000432742" << endl;
    cout << endl;
    cout << endl;

    Roster class_roster(5);

    const string studentData[] = {"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY", "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK", "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE", "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY", "A5,Kyle,Kuypers,kkuyper@wgu.edu,30,5,10,15,SOFTWARE"};

    cout << "Adding students to the roster..." << endl;
    for (string student : studentData) {
        stringstream s_student(student);
        vector<string> result;
        while (s_student.good()) {
            string sub;
            getline(s_student, sub, ',');
            result.push_back(sub);
        }

        DegreeProgram degree;

        if (result[8] == "SECURITY") {
            degree = SECURITY;
        } else if (result[8] == "NETWORK") {
            degree = NETWORK;
        } else if (result[8] == "SOFTWARE") {
            degree = SOFTWARE;
        } else {
            degree = NONE;
        }


        class_roster.add(result[0], result[1], result[2], result[3], stoi(result[4]), stoi(result[5]), stoi(result[6]), stoi(result[7]), degree);

        cout << result[1] << " " << result[2] << " has been added to the roster." << endl;
    }
    cout << endl;
    cout << "All students: " << endl;
    class_roster.printAll();
    cout << endl;

    cout << "Invalid emails: " << endl;
    class_roster.printInvalidEmails();
    cout << endl;

    cout << "Printing average days in course: " << endl;
    for (int i=0;i<class_roster.class_size;i++) {
        class_roster.printAverageDaysInCourse(class_roster.classRoster[i]->getID());
    }
    cout << endl;

    cout << "These students are in the Software program: " << endl;
    class_roster.printByDegreeProgram(SOFTWARE);
    cout << endl;

    cout << "Removing student ID A3: " << endl;
    class_roster.printStudent("A3");
    class_roster.remove("A3");

    cout << endl;
    cout << "Re-printing all students: " << endl;
    class_roster.printAll();
    cout << endl;

    cout << "Removing student ID A3 (again): " << endl;
    class_roster.remove("A3");
    cout << endl;
    cout << endl;

    return 0;

}