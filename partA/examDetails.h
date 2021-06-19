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
        static const int max_hour = 23;
        static const int min_hour = 0;
    public:
        /**
         * ExamDetails object constructor
         * @param course_number: whole non-negative number
         * @param month: between min to max month
         * @param day : between min to max day
         * @param hour: int whole or half hours only
         * @param duration: int
         * @param link_to_test
         */
        ExamDetails(int course_number, int month, int day, double hour, int duration, const string &link_to_test="");
        /**
         *ExamDetails object constructor with no arguments
         */
        ExamDetails() = default ;

        /**
         * ExamDetails destructor
         */
        ~ExamDetails() = default;

        /**
         * ExamDetails copy constructor
         */
        ExamDetails(const ExamDetails &exam_details);

        /**
         * Gets zoom link from ExamDetails object
         * @return string for the link
         */
        string getLink() const;

        /**
         * Sets zoom link to ExamDetails object
         * @param new_link_to_test string for the link
         */
        void setLink(const string &new_link_to_test);

        /**
         * get the difference in between two Exams starting hours
         * @param exam_details_right another ExamDetails object to compare with
         * @return int that is the difference between the starting hours
         */
        int operator-(ExamDetails &exam_details_right) const;

        /**
         * checks which exam starts earlier between two exams
         * @param exam_details_right another ExamDetails object to compare with
         * @return bool of which starts earlier
         */
        bool operator<(ExamDetails &exam_details_right) const;

        /**
         * checks which exam starts later between two exams
         * @param exam_details_right another ExamDetails object to compare with
         * @return bool of which starts earlier
         */
        bool operator>(ExamDetails &exam_details_right) const;

        /**
         * prints to stdout the ExamDetails object in pre-specified format
         * @param os
         * @param exam_details
         * @return os_stream object
         */
        friend ostream &operator<<(ostream &os, const ExamDetails &exam_details);

        /**
         * makes static matam exam based on pre-specified data
         * @return ExamDetails object
         */
        static ExamDetails makeMatamExam();

        /**
         * Exception to throw for invalid date in a constructor
         */
        class InvalidDateException;


        /**
         * Exception to throw for invalid time in a constructor
         */
        class InvalidTimeException;


        /**
         * Exception to throw for invalid other argument in a constructor
         */
        class InvalidArgsException {
        };
    };


    class ExamDetails::InvalidDateException {
    public:
        int day;
        int month;
        /**
         * constructor for invalid date exception
         */
        InvalidDateException(int day, int month) : day(day), month(month) {};
    };

    class ExamDetails::InvalidTimeException {
    public:
        int hour;
        /**
         * constructor for invalid time exception
         */
        explicit InvalidTimeException(int hour) : hour(hour) {};
    };
}


#endif //EX2_EXAM_DETAILS
