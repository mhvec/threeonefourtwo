#include <string>
#include <unordered_map>

using namespace std;

struct student
{

    string emplid;
    unordered_map<string, string> classes; // all the classes the student attempted - key is the unique class_id
};
class Student
{
public:
student s;
    Student(string emplid, string course, string grade)
    {
        s.emplid = emplid;
        s.classes[course] = grade;
    }

    void add_course(string course, string grade)
    {
        s.classes[course] = grade;
    }
    student* get_student(){
        return &s;
    }
};