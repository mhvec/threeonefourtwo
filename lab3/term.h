#include <string>
#include <unordered_set>

using namespace std;

struct term
{
    string term_id;
    bool is_spring; // attribute informing whether a given term is a spring term (1) or a fall term (0)
    unordered_set<string> courses;
};
class Term
{
    term t;

public:
    Term() {}

    Term(string term_id, string course, bool is_spring)
    {
        t.term_id = term_id;
        t.is_spring = is_spring;
        t.courses.insert(course);
    }

    void add_course(string course)
    {
        t.courses.insert(course);
    }
    term* get_term(){
        return &t;
    }
};