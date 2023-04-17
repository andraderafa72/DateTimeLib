#include <iostream>
#include <string>

#ifndef DATETIME
#define DATETIME

using namespace std;

class DateTime
{
private:
  int days_per_month[2][13] = {{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
                               {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};
  string CompareThisDate(DateTime dt);
  void ValidateTime(int d, int m, int y, int h, int min, int s);
  int isLeapYear(int year);
  int MonthFromDays(int days, int currentYear);
  int GetDateByDays(int days, int currentYear);

public:
  int day,
      month,
      year,
      hours,
      minutes,
      timestamp,
      seconds;

  /* CONSTRUCTORS */
  DateTime();
  DateTime(int d, int m, int y);
  DateTime(int d, int m, int y, int h);
  DateTime(int d, int m, int y, int h, int min);
  DateTime(int d, int m, int y, int h, int min, int s, int ts);

  /* COMPARISONS */
  bool isAfter(DateTime dt);
  bool isEqual(DateTime dt);
  DateTime Compare(DateTime another_time, string output);

  /* CONVERSIONS */
  string ToString();
  string ToISOString();
  DateTime toUTC();
  void ChangeTimeStamp(int ts);

  /* DATE OPERATIONS */
  // Sum
  void SumSeconds(int s);
  void SumMinutes(int min);
  void SumHours(int h);
  void SumDays(int d);
  void SumMonths(int m);
  void SumYears(int y);
  // Sub
  void SubtractSeconds(int s);
  void SubtractMinutes(int min);
  void SubtractHours(int h);
  void SubtractDays(int d);
  void SubtractMonths(int m);
  void SubtractYears(int y);
  bool isBefore(DateTime dt);

  /* ANOTHER METHODS */
  int GetFullYear();
  int GetMonth();
  int GetDate();
  int GetHours();
  int GetMinutes();
  int GetSeconds();
  int GetDayOfTheYear();
};

#endif