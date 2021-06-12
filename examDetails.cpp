#include <iostream>
#include <math.h>
#include "examDetails.h"
using std::string;
using std::ostream;
using std::cout;
using std::endl;
using std::modf;

const int MAX_DAY_OF_MONTH = 30;
const int MIN_DAY_OF_MONTH = 1;
const int MAX_MONTH = 12;
const int MIN_MONTH = 1;
const double MIN_HOUR = 0;
const double MAX_HOUR = 23;

namespace mtm {
    ExamDetails::ExamDetails(int course_number, int month, int day, double hour, int duration, const string
    &link_to_test)
    :course_number(course_number), month(month), day(day),hour(hour), duration(duration),link_to_test(link_to_test) {
        if (this->month < MIN_MONTH || this->month > MAX_MONTH || this->day < MIN_DAY_OF_MONTH ||
            this->day > MAX_DAY_OF_MONTH) {
            throw InvalidDateException(day, month);
        }
        double whole_hour;
        double minutes = modf(hour, &whole_hour);
        if ((minutes!= 0.5 && minutes != 0) || whole_hour>MAX_HOUR || whole_hour<MIN_HOUR) {
            throw InvalidTimeException(hour);
        }
        if (course_number < 0) {
            throw InvalidArgsException();
        }
    }

    ExamDetails::ExamDetails(const ExamDetails &exam_details) :
            course_number(exam_details.course_number), month(exam_details.month),
            day(exam_details.day),hour(exam_details.hour), duration(exam_details.duration),
              link_to_test(string(exam_details.link_to_test)) {
    }

    string ExamDetails::getLink() const {
        return this->link_to_test;
    }

    void ExamDetails::setLink(const string &new_link_to_test) {
        this->link_to_test = string(new_link_to_test);
    }

    int ExamDetails::operator-(ExamDetails &exam_details_right) const {
        return (this->day - exam_details_right.day) + (this->month - exam_details_right.month) * 30;
    }

    bool ExamDetails::operator<(ExamDetails &exam_details_right) const {
        return (this->operator-(exam_details_right)) < 0;
    }
    bool ExamDetails::operator>(ExamDetails &exam_details_right) const {
        return !(this->operator<(exam_details_right));
    }

    ostream &operator<<(ostream &os, const ExamDetails &exam_details) {
        int hour = int(exam_details.hour);
        string minutes;
        if (0 == (exam_details.hour - hour) * 60) {
            minutes = "00";
        } else {
            minutes = "30";
        }
        return os << "Course Number: " << exam_details.course_number << endl
                  << "Time: " << exam_details.day << "." << exam_details.month << " at "
                  << hour << ":" << minutes << endl << "Duration: " << exam_details.duration << ":"
                  << "00" << endl << "Zoom Link: " << exam_details.link_to_test<< endl;
    }

    ExamDetails ExamDetails::makeMatamExam() {
        return ExamDetails(234124, 7, 28, 13, 3, "https://tinyurl.com/59hzps6m");
    }
}


