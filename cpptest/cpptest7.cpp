#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <chrono>
#include <string>
#include <sstream>

class DateInput
{
    int m, d, y;
    bool isValid;
    struct tm di_tm;

public:
    DateInput()
    :
        m(0),
        d(0),
        y(0),
        isValid(false)
    {
        di_tm = {};
    }

    void getDate();
    constexpr bool DateIsValid() const
    {              //gregorian dates started in 1582
        //if (y < 1582)
        //    return false;
                   //limit of localtime()
        //if (y < 1900)
        //    return false;
                   //limit of the time_t epoch
        if (y < 1970)
            return false;
        if (m < 1 || 12 < m)
            return false;
        if (d < 1 || 31 < d)
            return false;
        if (d == 31 && (m == 2 || m == 4 || m == 6 || m == 9 || m == 11))
            return false;
        if (d == 30 && m == 2)
            return false;
        if (d == 29 && m == 2 && y%4 != 0)
            return false;
        if (d == 29 && m == 2 && y%400 == 0)
            return true;
        if (d == 29 && m == 2 && y%100 == 0)
            return false;
        //if (d == 29 && m == 2 && y%4 == 0)
        //    return true;
        return true;
    }

    int get_weekday()
    {
        struct tm time_in {};
        time_in.tm_mday = getDay();
        time_in.tm_mon  = getMonth() - 1;
        time_in.tm_year = getYear() - 1900;
        time_t time_temp = mktime(&time_in); // tm_wday and tm_yday are ignored by mktime. tm_isdst is irrelevant when it comes to dates.
        if (time_temp < 0)
            return -1;

                   //Note: Return value of localtime is not threadsafe, because it might be
                   // (and will be) reused in subsequent calls to std::localtime!
        memcpy(&di_tm, localtime(&time_temp), sizeof(di_tm));

                   //Sunday == 0, Monday == 1, and so on
//#ifndef NDEBUG
//        std::cout << "Today is this day of the week: " << di_tm.tm_wday << std::endl;
//        std::cout << "(Sunday is 0, Monday is 1, and so on...)" << std::endl;
//#endif
        return (di_tm.tm_wday);
    }

    int center(int width, int str_len)
    {
        int half_string_length = str_len / 2;
        int half_output_width = width / 2;
        int leading_spaces = half_output_width - half_string_length;
        return (leading_spaces);
    }

    constexpr int numOfDaysThisMonth() const
    {
        if (m == 4 || m == 6 || m == 9 || m == 11)
            return 30;
        if (m == 2)
            return (28 + (y%400 == 0 || (y%4 == 0 && y%100 != 0) ? 1 : 0));
        return 31;
    }

    int getMonth() const   { return (m); }
    int getDay() const     { return (d); }
    int setDay(int theDay) { int oldDay = d; d = theDay; return (oldDay); }
    int getYear() const    { return (y); }
    bool getIsValid() const            { return (isValid); }
    const struct tm *get_di_tm() const { return (&di_tm); }

    int printMonth();
};

void DateInput::getDate()
{
    using namespace std;
    string str;
    cout << "Enter a day: ";
    getline(cin, str);
    stringstream(str) >> d;

    str.clear();
    cout << "Enter a month: ";
    getline(cin, str);
    stringstream(str) >> m;

    str.clear();
    cout << "Enter a year (1970 or greater): ";
    getline(cin, str);
    stringstream(str) >> y;

    isValid = DateIsValid();
    if (isValid)
        cout << endl;
}

int DateInput::printMonth()
{
    using namespace std;
    int firstDay = 1;
    int currentDay = setDay(firstDay);
    int weekday = get_weekday(); // 0-6
    if (weekday < 0)
    {
        cout << "A bad weekday of " << weekday << " was returned!" << endl;
        return -1;
    }
                   // Now print the calendar
                   //      Month yyyy
                   // Su Mo Tu We Th Fr Sa
                   // nn nn nn nn nn nn nn
    char temp_buf[40];
    string line;
    strftime(temp_buf, sizeof(temp_buf)/sizeof(temp_buf[0]), "%B", get_di_tm()); // Month full name
    line += temp_buf;
    line += ' ';
    line += to_string(getYear());
    int leading_spaces = center(20, line.size());
    line = string(leading_spaces, ' '); // string fill
    line += temp_buf;
    line += ' ';
    line += to_string(getYear());
    while (line.size() < 20)
        line += ' ';
    cout << line << endl;
    line.clear();

    cout << "Su Mo Tu We Th Fr Sa" << endl; // TODO: i18n

    int i, j;
    bool done = false;
    int lastday = numOfDaysThisMonth();
//#ifndef NDEBUG
//    cout << "lastday=" << lastday << endl;
//#endif
    string wk, wk2;
    for (j = 0; j < 6; ++j) // at most 6 weeks
    {
        for (i = 0; i < 7; ++i)
        {
            if (!j && i < weekday)
                line += string(2, ' ');
            else
            {
                wk2 = to_string(getDay());
                if (currentDay == getDay())
                {
                    wk = "\33[7m";  // TODO: ANSI Reversed
                    wk += wk2;
                    wk += "\33[0m"; // TODO: ANSI Reset
                }
                else
                    wk = wk2;
                if (getDay() < lastday)
                    setDay(getDay() + 1);
                else
                    done = true;
                line += string(2 - min<size_t>(2, wk2.size()), ' ');
                line += wk;
            }
            if (i < 7-1 && !done)
                line += ' ';
            if (done)
                i = 7 - 1; // break
        }//for
        if (!line.empty())
        {
            cout << line << endl;
            line.clear();
        }
        if (done)
            j = 6 - 1; // break
    }//for
    return 0;
}

int main()
{
    DateInput di;
    di.getDate();
    if (!di.getIsValid())
    {
        std::cout << "Date " << di.getMonth() << '/' << di.getDay() << '/' << di.getYear() << " (M/D/YYYY) " << " is not valid" << std::endl;
        return -1;
    }
    return (di.printMonth());
}
