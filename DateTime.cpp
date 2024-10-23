/**
 * @file DateTime.cpp
 * @brief Implementation da classe DateTime
 */

#include <iostream>
#include <string>

#include "DateTime.h"

// using namespace std;

#pragma region Private Methods

string DateTime::compare_this_date(DateTime dt)
{
    int thisComponents[] = {year, month, day, hours, minutes, seconds};
    int dtComponents[] = {dt.year, dt.month, dt.day, dt.hours, dt.minutes, dt.seconds};

    for (int i = 0; i < 6; i++)
    {
        if (thisComponents[i] > dtComponents[i])
            return "bigger";
        else if (thisComponents[i] < dtComponents[i])
            return "smaller";
    }

    return "equal";
}

void DateTime::validate_time(int y, int m, int d, int h, int min, int s)
{
  if (d > 31 || d < 1)
    throw std::invalid_argument("DateTime Exception: Invalid 'day' argument. It must be between 1 and 31");
  if (m > 12 || m < 1)
    throw std::invalid_argument("DateTime Exception: Invalid 'month' argument. It must be between 1 and 12");
  if (y < 1)
    throw std::invalid_argument("DateTime Exception: Invalid 'year' argument. It must be bigger than 1");
  if (h > 23 || h < 0)
    throw std::invalid_argument("DateTime Exception: Invalid 'hours' argument. It must be between 0 and 23");
  if (m > 59 || m < 0)
    throw std::invalid_argument("DateTime Exception: Invalid 'minutes' argument. It must be between 0 and 59");
  if (s > 59 || s < 0)
    throw std::invalid_argument("DateTime Exception: Invalid 'seconds' argument. It must be between 0 and 59");
};

int DateTime::is_leap_year(int year) const
{
  return (year % 4 == 0) && ((year % 100 != 0) || (year % 400 == 0));
}

int DateTime::month_from_days(int days, int currentYear)
{
  if (days > 365)
    throw std::invalid_argument("DateTime Exception: Invalid 'days' argument. It must be between 1 and 365");
  int daysAux = days;
  int mes = 0;

  int isLeapYear = is_leap_year(currentYear) ? 0 : 1;

  for (int j = 1; j < 13; j++)
  {
    if (daysAux > days_per_month[isLeapYear][j])
    {
      mes++;
      daysAux -= days_per_month[isLeapYear][j];
    }
    else
      break;
  }
  return mes;
};

int DateTime::get_date_by_days(int days, int currentYear)
{
  if (days > 365)
    throw std::invalid_argument("DateTime Exception: Invalid 'days' argument. It must be between 1 and 365");
  int daysAux = days;

  int isLeapYear = is_leap_year(currentYear) ? 0 : 1;

  for (int j = 1; j <= 13; j++)
  {
    if (daysAux > days_per_month[isLeapYear][j])
    {
      daysAux -= days_per_month[isLeapYear][j];
    }
    else
      break;
  }
  return daysAux;
};

#pragma endregion

#pragma region Constructors

DateTime::DateTime() {};
DateTime::DateTime(int y, int m, int d)
{
  validate_time(y, m, d, 0, 0, 0);
  day = d;
  month = m;
  year = y;
  hours = 0;
  minutes = 0;
  seconds = 0;
  timestamp = 0;
}
DateTime::DateTime(int y, int m, int d, int h)
{
  validate_time(y, m, d, h, 0, 0);
  day = d;
  month = m;
  year = y;
  hours = h;
  minutes = 0;
  seconds = 0;
  timestamp = 0;
};
DateTime::DateTime(int y, int m, int d, int h, int min)
{
  validate_time(y, m, d, h, min, 0);
  day = d;
  month = m;
  year = y;
  hours = h;
  minutes = min;
  seconds = 0;
  timestamp = 0;
};
DateTime::DateTime(int y, int m, int d, int h, int min, int s, int ts)
{
  validate_time(y, m, d, h, min, s);
  day = d;
  month = m;
  year = y;
  hours = h;
  minutes = min;
  seconds = s;
  timestamp = ts;
};

#pragma endregion

#pragma region Comparisors

bool DateTime::is_before(DateTime dt)
{
  return compare_this_date(dt) == "smaller";
};

bool DateTime::is_after(DateTime dt)
{
  return compare_this_date(dt) == "bigger";
};

bool DateTime::is_equal(DateTime dt)
{
  return compare_this_date(dt) == "equal";
};

#pragma endregion

#pragma region Date Operations

void DateTime::sum_seconds(int s)
{
  int newS = seconds + s;
  while (newS > 60)
  {
    sum_minutes(1);
    newS -= 60;
  }

  seconds = newS;
};

void DateTime::sum_minutes(int min)
{
  int newMin = minutes + min;
  while (newMin > 59)
  {
    sum_hours(1);
    newMin -= 60;
  }

  minutes = newMin;
};

void DateTime::sum_hours(int h)
{
  int newH = hours + h;
  while (newH > 23)
  {
    sum_days(1);
    newH -= 24;
  }

  hours = newH;
};

void DateTime::sum_days(int d)
{
  int newD = day + d;

  while (newD > days_per_month[is_leap_year(year)][month])
  {
    newD -= days_per_month[is_leap_year(year)][month];
    sum_months(1);
  }

  day = newD;
};

void DateTime::sum_months(int m)
{
  int newM = month + m;

  while (newM > 12)
  {
    sum_years(1);
    newM -= 12;
  }

  month = newM;
};

void DateTime::sum_years(int y)
{
  int newY = year + y;

  if (newY < 1968 || newY > 2100)
    std::invalid_argument("DateTime Exception: Year to sum out of range.");

  year = newY;
}

void DateTime::subtract_seconds(int s)
{
  int newS = seconds - s;
  while (newS < 0)
  {
    subtract_minutes(1);
    newS += 60;
  }

  seconds = newS;
};

void DateTime::subtract_minutes(int min)
{
  int newMin = minutes - min;
  while (newMin < 0)
  {
    subtract_hours(1);
    newMin += 60;
  }

  minutes = newMin;
};

void DateTime::subtract_hours(int h)
{
  int newH = hours - h;
  while (newH < 0)
  {
    subtract_days(1);
    newH += 24;
  }

  hours = newH;
};

void DateTime::subtract_days(int d)
{
  int newD = day - d;

  while (newD < 1)
  {
    newD += days_per_month[is_leap_year(year)][month - 1];
    subtract_months(1);
  }

  day = newD;
};

void DateTime::subtract_months(int m)
{
  int newM = month - m;

  while (newM < 1)
  {
    subtract_years(1);
    newM += 12;
  }

  month = newM;
};

void DateTime::subtract_years(int y)
{
  int newY = year - y;

  if (newY < 1968)
    std::invalid_argument("DateTime Exception: Year to subtract out of range.");

  year = newY;
}

#pragma endregion

#pragma region Acessors

int DateTime::get_full_year() const { return year; }
int DateTime::get_month() const { return month; }
int DateTime::get_date() const { return day; }
int DateTime::get_hours() const { return hours; }
int DateTime::get_minutes() const { return month; }
int DateTime::get_seconds() const { return seconds; }
int DateTime::get_day_of_the_year() const
{
  int isLeap = is_leap_year(year);
  int dayOfTheYear = 0;

  for (int i = 1; i < month; i++)
  {
    dayOfTheYear += days_per_month[isLeap][i];
  }

  dayOfTheYear += day;
  return dayOfTheYear;
}

#pragma endregion

string DateTime::to_string() const // dd/MM/yyyy hh:mm:ss
{
  string dayString = day < 10 ? "0" + std::to_string(day) : std::to_string(day);
  string monthString = month < 10 ? "0" + std::to_string(month) : std::to_string(month);
  string hoursString = hours < 10 ? "0" + std::to_string(hours) : std::to_string(hours);
  string minutesString = minutes < 10 ? "0" + std::to_string(minutes) : std::to_string(minutes);
  string secondsString = seconds < 10 ? "0" + std::to_string(seconds) : std::to_string(seconds);
  string yearString;

  if (year < 10)
  {
    yearString = "000" + std::to_string(year);
  }
  else if (year < 100)
  {
    yearString = "00" + std::to_string(year);
  }
  else if (year < 1000)
  {
    yearString = "0" + std::to_string(year);
  }
  else
  {
    yearString = std::to_string(year);
  }

  return dayString + "/" + monthString + "/" + yearString + " " + hoursString + ":" + minutesString + ":" + secondsString;
}

string DateTime::to_ISO_string() const // dd/MM/yyyy hh:mm:ss
{
  string dayString = day < 10 ? "0" + std::to_string(day) : std::to_string(day);
  string monthString = month < 10 ? "0" + std::to_string(month) : std::to_string(month);
  string hoursString = hours < 10 ? "0" + std::to_string(hours) : std::to_string(hours);
  string minutesString = minutes < 10 ? "0" + std::to_string(minutes) : std::to_string(minutes);
  string secondsString = seconds < 10 ? "0" + std::to_string(seconds) : std::to_string(seconds);
  string yearString;

  if (year < 10)
  {
    yearString = "000" + std::to_string(year);
  }
  else if (year < 100)
  {
    yearString = "00" + std::to_string(year);
  }
  else if (year < 1000)
  {
    yearString = "0" + std::to_string(year);
  }
  else
  {
    yearString = std::to_string(year);
  }

  return yearString + "-" + monthString + "-" + dayString + "T" + hoursString + ":" + minutesString + ":" + secondsString + ".000Z";
}

DateTime DateTime::to_UTC()
{
  if (timestamp != 0)
    subtract_hours(timestamp > 0 ? timestamp : -timestamp);

  return DateTime(day, month, year, hours, minutes, seconds, 0);
}

void DateTime::change_time_stamp(int ts)
{
  subtract_hours(timestamp > 0 ? timestamp : -timestamp);
  sum_hours(ts);
};