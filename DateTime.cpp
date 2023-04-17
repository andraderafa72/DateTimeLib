#include <iostream>
#include <string>

#include "DateTime.h"

using namespace std;

class DateTime
{
private:
  int days_per_month[2][13] = {{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
                               {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};

  string CompareThisDate(DateTime dt)
  {
    bool isThisBiggerThanComparedDate, isTheSameDate;
    string thisYearComparison,
        thisMonthComparison,
        thisDayComparison,
        thisHoursComparison,
        thisMinutesComparison,
        thisSecondsComparison;

    isTheSameDate = year == dt.year && month == dt.month && day == dt.day && hours == dt.hours && minutes == dt.minutes && seconds == dt.seconds;
    if (isTheSameDate)
      return "equal";

    thisYearComparison = year > dt.year ? "bigger" : year == dt.year ? "equal"
                                                                     : "smaller";
    thisMonthComparison = month > dt.month ? "bigger" : month == dt.month ? "equal"
                                                                          : "smaller";
    thisDayComparison = day > dt.day ? "bigger" : day == dt.day ? "equal"
                                                                : "smaller";
    thisHoursComparison = hours > dt.hours ? "bigger" : hours == dt.hours ? "equal"
                                                                          : "smaller";
    thisMinutesComparison = minutes > dt.minutes ? "bigger" : minutes == dt.minutes ? "equal"
                                                                                    : "smaller";
    thisSecondsComparison = seconds > dt.seconds ? "bigger" : seconds == dt.seconds ? "equal"
                                                                                    : "smaller";

    if (
        thisYearComparison == "bigger" || (thisYearComparison == "equal" && thisMonthComparison == "bigger") || (thisYearComparison == "equal" && thisMonthComparison == "equal" && thisDayComparison == "bigger") || (thisYearComparison == "equal" && thisMonthComparison == "equal" && thisDayComparison == "equal" && thisHoursComparison == "bigger") || (thisYearComparison == "equal" && thisMonthComparison == "equal" && thisDayComparison == "equal" && thisHoursComparison == "equal" && thisMinutesComparison == "bigger") || (thisYearComparison == "equal" && thisMonthComparison == "equal" && thisDayComparison == "equal" && thisHoursComparison == "equal" && thisMinutesComparison == "equal" && thisSecondsComparison == "bigger"))
      return "bigger";
    else
      return "smaller";
  }

  void ValidateTime(int d, int m, int y, int h, int min, int s)
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

  int isLeapYear(int year)
  {
    return (year % 4 == 0) && ((year % 100 != 0) || (year % 400 == 0));
  }

  int MonthFromDays(int days, int currentYear)
  {
    if (days > 365)
      throw std::invalid_argument("DateTime Exception: Invalid 'days' argument. It must be between 1 and 365");
    int daysAux = days;
    int mes = 0;

    int isBissexto = isLeapYear(currentYear) ? 0 : 1;

    for (int j = 1; j <= 13; j++)
    {
      if (daysAux > days_per_month[isBissexto][j])
      {
        mes++;
        daysAux -= days_per_month[isBissexto][j];
      }
      else
        return mes;
    }
  };

  int GetDateByDays(int days, int currentYear)
  {
    if (days > 365)
      throw std::invalid_argument("DateTime Exception: Invalid 'days' argument. It must be between 1 and 365");
    int daysAux = days;

    int isBissexto = isLeapYear(currentYear) ? 0 : 1;

    for (int j = 1; j <= 13; j++)
    {
      if (daysAux > days_per_month[isBissexto][j])
      {
        daysAux -= days_per_month[isBissexto][j];
      }
      else
        return daysAux;
    }
  };

public:
  int day,
      month,
      year,
      hours,
      minutes,
      timestamp,
      seconds;

  DateTime(){};
  DateTime(int d, int m, int y)
  {
    ValidateTime(d, m, y, 0, 0, 0);
    day = d;
    month = m;
    year = y;
    hours = 0;
    minutes = 0;
    seconds = 0;
    timestamp = 0;
  }
  DateTime(int d, int m, int y, int h)
  {
    ValidateTime(d, m, y, h, 0, 0);
    day = d;
    month = m;
    year = y;
    hours = h;
    minutes = 0;
    seconds = 0;
    timestamp = 0;
  };
  DateTime(int d, int m, int y, int h, int min)
  {
    ValidateTime(d, m, y, h, min, 0);
    day = d;
    month = m;
    year = y;
    hours = h;
    minutes = min;
    seconds = 0;
    timestamp = 0;
  };
  DateTime(int d, int m, int y, int h, int min, int s, int ts)
  {
    ValidateTime(d, m, y, h, min, s);
    day = d;
    month = m;
    year = y;
    hours = h;
    minutes = min;
    seconds = s;
    timestamp = ts;
  };

  DateTime Compare(DateTime another_time, string output = "D")
  {
    // VALIDAÇÃO DE VALORES
    bool isTheSameDate = year == another_time.year && month == another_time.month && day == another_time.day;
    bool isThisBiggerThanComparedDate = CompareThisDate(another_time) == "bigger";

    unsigned long startDays, finalDays, startYear;
    unsigned long def_anos = 0;

    register int i;
    int dbissexto;

    startDays = isThisBiggerThanComparedDate ? another_time.day : day;
    dbissexto = isLeapYear(!isThisBiggerThanComparedDate ? another_time.year : year);
    startYear = isThisBiggerThanComparedDate ? another_time.year : year;

    for (i = month - 1; i > 0; --i)
      startDays += days_per_month[dbissexto][i];

    finalDays = isThisBiggerThanComparedDate ? day : another_time.day;
    dbissexto = isLeapYear(!isThisBiggerThanComparedDate ? another_time.year : year);

    for (i = another_time.month - 1; i > 0; --i)
      finalDays += days_per_month[dbissexto][i];

    int yearAux = isThisBiggerThanComparedDate ? year : another_time.year;
    while (startYear < yearAux)
      def_anos += 365 + isLeapYear(startYear++);

    long totalDaysDifference = def_anos - startDays + finalDays;
    totalDaysDifference = totalDaysDifference > 0 ? totalDaysDifference : -totalDaysDifference;

    long aux = totalDaysDifference;
    DateTime diffDt;
    diffDt.year = aux / 365;
    aux -= diffDt.year * 365;
    diffDt.month = MonthFromDays(aux, diffDt.year);
    diffDt.day = GetDateByDays(aux, diffDt.year);

    return diffDt;
  }

  string ToString() // dd/MM/yyyy hh:mm:ss
  {
    string dayString = day < 10 ? "0" + to_string(day) : to_string(day);
    string monthString = month < 10 ? "0" + to_string(month) : to_string(month);
    string hoursString = hours < 10 ? "0" + to_string(hours) : to_string(hours);
    string minutesString = minutes < 10 ? "0" + to_string(minutes) : to_string(minutes);
    string secondsString = seconds < 10 ? "0" + to_string(seconds) : to_string(seconds);
    string yearString;

    if (year < 10)
    {
      yearString = "000" + to_string(year);
    }
    else if (year < 100)
    {
      yearString = "00" + to_string(year);
    }
    else if (year < 1000)
    {
      yearString = "0" + to_string(year);
    }
    else
    {
      yearString = to_string(year);
    }

    return dayString + "/" + monthString + "/" + yearString + " " + hoursString + ":" + minutesString + ":" + secondsString;
  }

  string ToISOString() // dd/MM/yyyy hh:mm:ss
  {
    string dayString = day < 10 ? "0" + to_string(day) : to_string(day);
    string monthString = month < 10 ? "0" + to_string(month) : to_string(month);
    string hoursString = hours < 10 ? "0" + to_string(hours) : to_string(hours);
    string minutesString = minutes < 10 ? "0" + to_string(minutes) : to_string(minutes);
    string secondsString = seconds < 10 ? "0" + to_string(seconds) : to_string(seconds);
    string yearString;

    if (year < 10)
    {
      yearString = "000" + to_string(year);
    }
    else if (year < 100)
    {
      yearString = "00" + to_string(year);
    }
    else if (year < 1000)
    {
      yearString = "0" + to_string(year);
    }
    else
    {
      yearString = to_string(year);
    }

    return yearString + "-" + monthString + "-" + dayString + "T" + hoursString + ":" + minutesString + ":" + secondsString + ".000Z";
  }

  DateTime toUTC()
  {
    if (timestamp != 0)
      SubtractHours(timestamp > 0 ? timestamp : -timestamp);

    return DateTime(day, month, year, hours, minutes, seconds, 0);
  }

  void ChangeTimeStamp(int ts)
  {
    SubtractHours(timestamp > 0 ? timestamp : -timestamp);
    SumHours(ts);
  };

  void SumSeconds(int s)
  {
    int newS = seconds + s;
    while (newS > 60)
    {
      SumMinutes(1);
      newS -= 60;
    }

    seconds = newS;
  };

  void SumMinutes(int min)
  {
    int newMin = minutes + min;
    while (newMin > 59)
    {
      SumHours(1);
      newMin -= 60;
    }

    minutes = newMin;
  };

  void SumHours(int h)
  {
    int newH = hours + h;
    while (newH > 23)
    {
      SumDays(1);
      newH -= 24;
    }

    hours = newH;
  };

  void SumDays(int d)
  {
    int newD = day + d;

    while (newD > days_per_month[isLeapYear(year)][month])
    {
      newD -= days_per_month[isLeapYear(year)][month];
      SumMonths(1);
    }

    day = newD;
  };

  void SumMonths(int m)
  {
    int newM = month + m;

    while (newM > 12)
    {
      SumYears(1);
      newM -= 12;
    }

    month = newM;
  };

  void SumYears(int y)
  {
    int newY = year + y;

    if (newY < 1968 || newY > 2100)
      std::invalid_argument("DateTime Exception: Year to sum out of range.");

    year = newY;
  }

  void SubtractSeconds(int s)
  {
    int newS = seconds - s;
    while (newS < 0)
    {
      SubtractMinutes(1);
      newS += 60;
    }

    seconds = newS;
  };

  void SubtractMinutes(int min)
  {
    int newMin = minutes - min;
    while (newMin < 0)
    {
      SubtractHours(1);
      newMin += 60;
    }

    minutes = newMin;
  };

  void SubtractHours(int h)
  {
    int newH = hours - h;
    while (newH < 0)
    {
      SubtractDays(1);
      newH += 24;
    }

    hours = newH;
  };

  void SubtractDays(int d)
  {
    int newD = day - d;

    while (newD < 1)
    {
      newD += days_per_month[isLeapYear(year)][month - 1];
      SubtractMonths(1);
    }

    day = newD;
  };

  void SubtractMonths(int m)
  {
    int newM = month - m;

    while (newM < 1)
    {
      SubtractYears(1);
      newM += 12;
    }

    month = newM;
  };

  void SubtractYears(int y)
  {
    int newY = year - y;

    if (newY < 1968)
      std::invalid_argument("DateTime Exception: Year to subtract out of range.");

    year = newY;
  }

  bool isBefore(DateTime dt)
  {
    return CompareThisDate(dt) == "smaller";
  };

  bool isAfter(DateTime dt)
  {
    return CompareThisDate(dt) == "bigger";
  };

  bool isEqual(DateTime dt)
  {
    return CompareThisDate(dt) == "equal";
  };

  int GetFullYear() { return year; }
  int GetMonth() { return month; }
  int GetDate() { return day; }
  int GetHours() { return hours; }
  int GetMinutes() { return month; }
  int GetSeconds() { return seconds; }

  int GetDayOfTheYear()
  {
    int dayAux = day;
    int b = isLeapYear(year);
    int dayOfTheYear = 0;

    int i = month;
    while (dayAux > 0)
    {
      // int qtdOfDays = days_per_month[b][i];
      // if (dayAux > qtdOfDays)
      // {
      //   dayAux -= qtdOfDays;
      //   dayOfTheYear += qtdOfDays;
      // }
      // else
      // {
      //   dayOfTheYear += dayAux;
      //   dayAux = 0;
      // }

      // i--;
    }

    return dayOfTheYear;
  }
};

int main()
{
  DateTime dt1(1, 1, 2023);
  DateTime dt2(10, 3, 2020);
  // DateTime diff = dt1.Subtract(dt2);
  cout << dt1.ToString() << endl;

  dt1.SubtractSeconds(100);
  cout << dt1.ToString() << endl;

  dt1.SubtractMinutes(15);
  cout << dt1.ToString() << endl;

  dt1.SubtractHours(2);
  cout << dt1.ToString() << endl;

  cout << dt1.ToISOString() << endl;
  cout << dt1.GetDayOfTheYear() << endl;

  return 0;
}

int main()
{
  DateTime dt;
  
}
