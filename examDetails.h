#ifndef EX2_EXAM_DETAILS
#define EXAM_DETAILS_EXAM
#include <iostream>

using std::string;
using std::ostream;

class ExamDetails{
private:
    int course_number, duration, month, day;
    double hour;
    string link_to_test;
public:
    ExamDetails(int course_number, int month, int day, double hour, int duration,const string& link_to_test);
    ~ExamDetails() = default;
    ExamDetails(const ExamDetails& exam_details);
    string getLink() const;
    void setLink(const string& new_link_to_test);
    int operator-(ExamDetails& exam_details_right) const;
    bool operator<(ExamDetails& exam_details_right) const;
    friend ostream& operator<<(ostream& os,const ExamDetails& exam_details);
    static ExamDetails makeMatamExam() ;
};

#endif //EXAM_DETAILS
