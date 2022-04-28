#include <iostream>
#include <unordered_map>
#include <vector>
#include "section.h"
#include "student.h"
#include "instructor.h"
#include "term.h"


class college {
    // class and prototype functions for the college class
    unordered_map<string, Student*> studentList;
    unordered_map<string, Section*> courseList;
public:
    unordered_map<string, Instructor*> instructorList;
    unordered_map<string, Term*> termList;

public:
    college() {};

    student* get_student(string emplId);
    section* get_section(string class_id);
    instructor* get_instructor(string ins_id);
    term* get_term(string term_id);

    void addStudent(string emplId, string courseNo, string grade);
    void addInstructor(string ins_id, string courseNo);
    void schedule_course(string course, section* sect);
    void schedule_term(string term_id, term* term);
    void testPrint();
    void insPrint();
    vector<string> getIns(vector<string>);
    int insPassrate();

    unordered_map<string, student*>* get_students();
    unordered_map<string, section*>* get_courses();
    unordered_map<string, instructor*>* get_instructors();
    unordered_map<string, term*>* get_terms();

};