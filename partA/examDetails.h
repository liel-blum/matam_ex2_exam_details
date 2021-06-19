#ifndef EX2_EXAM_DETAILS
#define EXAM_DETAILS_EXAM
#include <iostream>

using std::string;
using std::ostream;

namespace mtm {
    class ExamDetails {
    private:
        int course_number;
        int month;
        int day;
        double hour;
        int duration;
        string link_to_test;
        static const int max_day_of_month = 30;
        static const int min_day_of_month = 1;
        static const int max_month = 12;
        static const int min_month = 1;
    public:
        ExamDetails(int course_number, int month, int day, double hour, int duration, const string &link_to_test="");
        ExamDetails() = default ;

        ~ExamDetails() = default;

        ExamDetails(const ExamDetails &exam_details);

        string getLink() const;

        void setLink(const string &new_link_to_test);

        int operator-(ExamDetails &exam_details_right) const;

        bool operator<(ExamDetails &exam_details_right) const;

        bool operator>(ExamDetails &exam_details_right) const;

        friend ostream &operator<<(ostream &os, const ExamDetails &exam_details);

        static ExamDetails makeMatamExam();

        class InvalidDateException;

        class InvalidTimeException;

        class InvalidArgsException {
        };
    };


    class ExamDetails::InvalidDateException {
    public:
        int day;
        int month;

        InvalidDateException(int day, int month) : day(day), month(month) {};
    };

    class ExamDetails::InvalidTimeException {
    public:
        int hour;

        explicit InvalidTimeException(int hour) : hour(hour) {};
    };
}


#endif //EX2_EXAM_DETAILS
