/**
 * @file DateTime.cpp
 * @brief Implementation da classe DateTime
 */

#include <iostream>
#include <string>

#include "./date_time.h"

// using namespace std;

#pragma region Private Methods

std::string DateTime::compare_this_date(DateTime dt)
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

void DateTime::validate_time(int y, int m, int d, int h, int min, int s, int ts)
{
  if (d > 31 || d < 1)
    throw std::invalid_argument("DateTime Exception: Invalid 'day' argument. It must be between 1 and 31");
  if (m > 12 || m < 1)
    throw std::invalid_argument("DateTime Exception: Invalid 'month' argument. It must be between 1 and 12");
  if (ts < -12 || ts > 12)
    throw std::invalid_argument("DateTime Exception: Invalid 'time stamp' argument. It must be between -12 and 12");
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

DateTime::DateTime() {
  year = 0;
  month = 0;
  day = 0;
  hours = 0;
  minutes= 0;
  seconds = 0;
  timezone = 0;
};

DateTime::DateTime(int y, int m, int d)
{
  validate_time(y, m, d, 0, 0, 0, 0);
  day = d;
  month = m;
  year = y;
  hours = 0;
  minutes = 0;
  seconds = 0;
  timezone = 0;
}
DateTime::DateTime(int y, int m, int d, int h)
{
  validate_time(y, m, d, h, 0, 0, 0);
  day = d;
  month = m;
  year = y;
  hours = h;
  minutes = 0;
  seconds = 0;
  timezone = 0;
};
DateTime::DateTime(int y, int m, int d, int h, int min)
{
  validate_time(y, m, d, h, min, 0, 0);
  day = d;
  month = m;
  year = y;
  hours = h;
  minutes = min;
  seconds = 0;
  timezone = 0;
};
DateTime::DateTime(int y, int m, int d, int h, int min, int s)
{
  validate_time(y, m, d, h, min, s, 0);
  day = d;
  month = m;
  year = y;
  hours = h;
  minutes = min;
  seconds = s;
  timezone = 0;
};

DateTime::DateTime(int y, int m, int d, int h, int min, int s, int tz)
{
  validate_time(y, m, d, h, min, s, tz);
  day = d;
  month = m;
  year = y;
  hours = h;
  minutes = min;
  seconds = s;
  timezone = tz;
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
  if(s < 0) return subtract_seconds(-s);

  int newS = seconds + s;
  while (newS > 59)
  {
    sum_minutes(1);
    newS -= 60;
  }

  seconds = newS;
};

void DateTime::sum_minutes(int min)
{
  if(min < 0) return subtract_minutes(-min);

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
  if(h < 0) return subtract_hours(-h);

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
  if(d < 0) return subtract_days(-d);

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
  if(m < 0) return subtract_months(-m);

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
  if(y < 0) return subtract_years(-y);

  int newY = year + y;

  if (newY < 1968 || newY > 2100)
    std::invalid_argument("DateTime Exception: Year to sum out of range.");

  year = newY;
}

void DateTime::subtract_seconds(int s)
{
  if(s < 0) return sum_seconds(-s);

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
  if(min < 0) return sum_minutes(-min);

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
  if(h < 0) return sum_hours(-h);

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
  if(d < 0) return sum_days(-d);

  int newD = day - d;

  while (newD < 1)
  {
    int month_index = month - 1 == 0 ? 12 : month - 1;
    newD += days_per_month[is_leap_year(year)][month_index];
    subtract_months(1);
  }

  day = newD;
};

void DateTime::subtract_months(int m)
{
  if(m < 0) return sum_months(-m);

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
  if(y < 0) return sum_years(-y);
  
  int newY = year - y;

  if (newY < 1)
    std::invalid_argument("DateTime Exception: Year to subtract out of range.");

  year = newY;
}

#pragma endregion

#pragma region Setters

void DateTime::set_full_year(int y) { year = y; }
void DateTime::set_month(int m) { month = m; }
void DateTime::set_day(int d) { day = d; }
void DateTime::set_hours(int h) { hours = h; }
void DateTime::set_minutes(int min) { minutes = min; }
void DateTime::set_seconds(int s) { seconds = s; }

#pragma endregion

#pragma region Acessors

int DateTime::get_full_year() const { return year; }
int DateTime::get_month() const { return month; }
int DateTime::get_day() const { return day; }
int DateTime::get_hours() const { return hours; }
int DateTime::get_minutes() const { return minutes; }
int DateTime::get_seconds() const { return seconds; }
int DateTime::get_timezone() const { return timezone; }
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

auto pad_zero = [](int value)
{
  return (value < 10 ? "0" : "") + std::to_string(value);
};

std::string DateTime::to_string() const // dd/MM/yyyy hh:mm:ss
{
  std::string yearString = std::to_string(year);
  yearString.insert(0, 4 - yearString.length(), '0');

  return pad_zero(day) + "/" + pad_zero(month) + "/" + yearString + " " +
         pad_zero(hours) + ":" + pad_zero(minutes) + ":" + pad_zero(seconds);
}

std::string DateTime::to_ISO_string() const // yyyy-MM-ddThh:mm:ss.000Z
{
  DateTime tempDate = to_UTC();

  std::string yearString = std::to_string(tempDate.year);
  yearString.insert(0, 4 - yearString.length(), '0');

  return yearString + "-" + pad_zero(tempDate.month) + "-" + pad_zero(tempDate.day) + "T" +
         pad_zero(tempDate.hours) + ":" + pad_zero(tempDate.minutes) + ":" + pad_zero(tempDate.seconds) + ".000Z";
}

DateTime DateTime::to_UTC() const
{
  DateTime newDate(year, month, day, hours, minutes, seconds, timezone);
  newDate.change_timezone(0);

  return newDate;
}

void DateTime::change_timezone(int newTimezone)
{
  if (timezone > 0)
    subtract_hours(timezone);
  else if(timezone < 0)
    sum_hours(-timezone);

  if (newTimezone > 0)
    sum_hours(newTimezone);
  else if(newTimezone < 0)
    subtract_hours(-newTimezone);

  timezone = newTimezone;
};
