#include <string>
#include <unordered_set>

using namespace std;

struct instructor
{
    // instructor data consists of only id and courses they taught
    string ins_id;
    unordered_set<string> classes;
};
struct Instructor{
    instructor ins;
public:
    
    Instructor(string ins_id, string course)
    {
        ins.ins_id = ins_id;
        ins.classes.insert(course);
    }

    void add_course(string course)
    {
        ins.classes.insert(course);
    }
    instructor* get_instruction(){
        return &ins;
    }
};