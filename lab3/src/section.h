#include <string>
#include <vector>

using namespace std;

struct section
{
    string class_id;         // unique class id (term + courseno + section)
    string course_no;        // e.g. 1115
    string section_code;     // e.g. S04
    string instr_id;         // e.g. I01
    string term;             // e.g. T04
    vector<string> students; // list of student ids associated with given class instance

};
class Section{
public:
section s;
    Section(string class_id, string course_no, string section_code, string instr_id, string term)
    {
        s.class_id = class_id;
        s.course_no = course_no;
        s.section_code = section_code;
        s.instr_id = instr_id;
        s.term = term;
    }

    void add_student(string emplid)
    {
        s.students.push_back(emplid);
    }
    section* get_section(){
        return &s;
    }
};