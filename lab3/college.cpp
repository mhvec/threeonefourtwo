#include <fstream>
#include <sstream>
#include <map>
#include "college.h"
//Aggergation File

void college::addStudent(string emplId, string courseNo, string grade) {
    //only unique students are added, otherwise they only have a new course added to them
    if (!studentList.count(emplId)) {
        Student* s = new Student(emplId, courseNo, grade);
        studentList[emplId] = s;
    } else {
        studentList[emplId]->add_course(courseNo, grade);
    }
}

void college::addInstructor(string insId, string courseNo){
    //only unique instructors are added, otherwise they only have a new course added to them
    if(insId.find("I",0) == 0) {
        if (!instructorList.count(insId)) {
            Instructor *s = new Instructor(insId, courseNo);
            instructorList[insId] = s;
        } else {
            instructorList[insId]->add_course(courseNo);
        }
    }
}

void college::testPrint() {
    for (auto& x : studentList)
        cout << x.first  << " " << endl;
}

void college::insPrint() {
    for (auto& x : instructorList){
        cout << x.first  << " " << endl;
    }
}

