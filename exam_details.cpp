#include <iostream>

using std::string;
using std::ostream;
using std::cout;
using std::endl;


class ExamDetails{
private:
    int course_number, duration, month, day;
    double hour;
    string link_to_test;
public:
    ExamDetails(int course_number, int month, int day, double hour, int duration, string link_to_test);
    ~ExamDetails() = default;
    ExamDetails(const ExamDetails& exam_details);
    string getLink() const;
    void setLink(const string new_link_to_test);
    int operator-(ExamDetails& exam_details_right) const;
    bool operator<(ExamDetails& exam_details_right) const;
    friend ostream& operator<<(ostream& os,const ExamDetails& exam_details);
    static ExamDetails makeMatamExam() ;
};

ExamDetails:: ExamDetails(int course_number, int month, int day, double hour, int duration, string link_to_test=""){
    this->course_number = course_number;
    this->duration = duration;
    this->month=month;
    this->day = day;
    this->hour = hour;
    this->link_to_test = link_to_test; //todo: check if need to allocate space for this
}

ExamDetails::ExamDetails(const ExamDetails& exam_details):
        course_number(exam_details.course_number),
        duration(exam_details.duration),
        day(exam_details.day),hour(exam_details.hour),link_to_test(exam_details.link_to_test){
}
string ExamDetails::getLink() const{
    return this->link_to_test;
}
void ExamDetails::setLink(const string new_link_to_test){
    this->link_to_test=new_link_to_test;
}

int ExamDetails::operator-(ExamDetails& exam_details_right) const{
    return (this->day-exam_details_right.day)+(this->month-exam_details_right.month)*30;
}

bool ExamDetails::operator<(ExamDetails& exam_details_right) const{
    return (this->operator-(exam_details_right))<0 ;
}

ostream& operator<<(ostream& os,const ExamDetails& exam_details) {
    int hour = int(exam_details.hour);
    string minutes;
    if(0==(exam_details.hour-hour)*60){
        minutes = "00";
    }
    else {
        minutes = "30";
    }
    return os << "Course Number:" << exam_details.course_number <<'\n'
    << "Time: " << exam_details.day << "." << exam_details.month << " at "
    << hour << ":" << minutes << '\n' << "Duration:" << exam_details.duration << ":"
    << "00" << '\n' << "Zoom Link:" << exam_details.link_to_test;
}

ExamDetails ExamDetails::makeMatamExam() {
    return ExamDetails(234124,7,28,13,3,"https://tinyurl.com/59hzps6m");
}

int main()
{
    ExamDetails exam1 = ExamDetails::makeMatamExam();
    ExamDetails exam2(104032, 7, 11, 9.5, 3);
    ExamDetails exam3 = exam1;
    cout << "the difference between MATAM and infi 2m is " << (exam1-exam2) << " days \n";
    ExamDetails& closest = (exam1 < exam2) ? exam1 : exam2;
    cout << "your closest exam is:" << endl << closest << endl;
}