#include <gtest/gtest.h>
#include <iostream>
#include "date_time.h"

#pragma region Constructors

TEST(Constructors, Empty) {
    DateTime dt;
    
    EXPECT_EQ(dt.get_full_year(), 0);
    EXPECT_EQ(dt.get_month(), 0);
    EXPECT_EQ(dt.get_day(), 0);
    EXPECT_EQ(dt.get_hours(), 0);
    EXPECT_EQ(dt.get_minutes(), 0);
    EXPECT_EQ(dt.get_seconds(), 0);
    EXPECT_EQ(dt.get_timezone(), 0);
}

TEST(Constructors, WithYearMonthDay) {
    DateTime dt(2024, 12, 6);

    EXPECT_EQ(dt.get_full_year(), 2024);
    EXPECT_EQ(dt.get_month(), 12);
    EXPECT_EQ(dt.get_day(), 6);
    EXPECT_EQ(dt.get_hours(), 0);
    EXPECT_EQ(dt.get_minutes(), 0);
    EXPECT_EQ(dt.get_seconds(), 0);
    EXPECT_EQ(dt.get_timezone(), 0);
}

TEST(Constructors, WithYearMonthDayHour) {
    DateTime dt(2024, 12, 6, 15);

    EXPECT_EQ(dt.get_full_year(), 2024);
    EXPECT_EQ(dt.get_month(), 12);
    EXPECT_EQ(dt.get_day(), 6);
    EXPECT_EQ(dt.get_hours(), 15);
    EXPECT_EQ(dt.get_minutes(), 0); 
    EXPECT_EQ(dt.get_seconds(), 0);
    EXPECT_EQ(dt.get_timezone(), 0);
}

TEST(Constructors, WithYearMonthDayHourMinute) {
    DateTime dt(2024, 12, 6, 15, 30);

    EXPECT_EQ(dt.get_full_year(), 2024);
    EXPECT_EQ(dt.get_month(), 12);
    EXPECT_EQ(dt.get_day(), 6);
    EXPECT_EQ(dt.get_hours(), 15);
    EXPECT_EQ(dt.get_minutes(), 30);
    EXPECT_EQ(dt.get_seconds(), 0); 
    EXPECT_EQ(dt.get_timezone(), 0);
}

TEST(Constructors, WithYearMonthDayHourMinuteSecond) {
    DateTime dt(2024, 12, 6, 15, 30, 45);

    EXPECT_EQ(dt.get_full_year(), 2024);
    EXPECT_EQ(dt.get_month(), 12);
    EXPECT_EQ(dt.get_day(), 6);
    EXPECT_EQ(dt.get_hours(), 15);
    EXPECT_EQ(dt.get_minutes(), 30);
    EXPECT_EQ(dt.get_seconds(), 45);
    EXPECT_EQ(dt.get_timezone(), 0); 
}

TEST(Constructors, WithYearMonthDayHourMinuteSecondTimezone) {
    DateTime dt(2024, 12, 6, 15, 30, 45, -3);

    EXPECT_EQ(dt.get_full_year(), 2024);
    EXPECT_EQ(dt.get_month(), 12);
    EXPECT_EQ(dt.get_day(), 6);
    EXPECT_EQ(dt.get_hours(), 15);
    EXPECT_EQ(dt.get_minutes(), 30);
    EXPECT_EQ(dt.get_seconds(), 45);
    EXPECT_EQ(dt.get_timezone(), -3);
}

#pragma endregion

#pragma region Modifiers

TEST(Modifiers, GettersAndSetters) {
    DateTime dt(2024, 12, 6, 15, 30, 45, -3); // leap_year
    EXPECT_EQ(dt.get_day_of_the_year(), 341);

    dt.set_full_year(2025);
    dt.set_month(1);
    dt.set_day(1);
    dt.set_hours(10);
    dt.set_minutes(45);
    dt.set_seconds(30);

    EXPECT_EQ(dt.get_full_year(), 2025);
    EXPECT_EQ(dt.get_month(), 1);
    EXPECT_EQ(dt.get_day(), 1);
    EXPECT_EQ(dt.get_hours(), 10);
    EXPECT_EQ(dt.get_minutes(), 45);
    EXPECT_EQ(dt.get_seconds(), 30);
    EXPECT_EQ(dt.get_day_of_the_year(), 1);
}

TEST(Modifiers, ChangeTimezone) {
  DateTime dt(2024, 12, 06, 12, 0, 0, 0);
  dt.change_timezone(-3);

  EXPECT_EQ(dt.get_hours(), 9);

  dt.change_timezone(3);

  EXPECT_EQ(dt.get_hours(), 15);
}

TEST(Modifiers, ToUTC) {
  DateTime dt(2024, 12, 06, 9, 0, 0, -3);
  DateTime newDate = dt.to_UTC();

  EXPECT_EQ(newDate.get_hours(), 12);
}

#pragma endregion

#pragma region Conversions

TEST(Conversions, ToString) {
  DateTime dt(2024, 12, 06, 12, 0, 0, 0);

  EXPECT_EQ(dt.to_string(), "06/12/2024 12:00:00");  
}

TEST(Conversions, ToISOString) {
  DateTime dt(2024, 12, 06, 9, 0, 0, -3);
  
  EXPECT_EQ(dt.to_ISO_string(), "2024-12-06T12:00:00.000Z");
}

#pragma endregion

#pragma region Comparisons

TEST(Comparisons, IsAfter) {
  DateTime dt1(2024, 12, 06, 9, 0, 0, -3);
  DateTime dt2(2024, 12, 06, 9, 0, 0, -3);
  
  EXPECT_EQ(dt1.is_after(dt2), false);

  dt1.sum_days(2);

  EXPECT_EQ(dt1.is_after(dt2), true);
  EXPECT_EQ(dt2.is_after(dt1), false);
}

TEST(Comparisons, IsBefore) {
  DateTime dt1(2024, 12, 06, 9, 0, 0, -3);
  DateTime dt2(2024, 12, 06, 9, 0, 0, -3);
  
  EXPECT_EQ(dt1.is_before(dt2), false);

  dt1.subtract_days(2);

  EXPECT_EQ(dt1.is_before(dt2), true);
  EXPECT_EQ(dt2.is_before(dt1), false);
}

TEST(Comparisons, IsEqual) {
  
  DateTime dt1(2024, 12, 06, 9, 0, 0, -3);
  DateTime dt2(2024, 12, 06, 9, 0, 0, -3);
  
  EXPECT_EQ(dt1.is_equal(dt2), true);

  dt1.subtract_days(2);

  EXPECT_EQ(dt1.is_equal(dt2), false);
  EXPECT_EQ(dt2.is_equal(dt1), false);
}

#pragma endregion

#pragma region Operations

/// SUM 

TEST(Operations, SumYears) { 
  DateTime dt(2024, 12, 06, 9, 0, 0, -3);
  dt.sum_years(1);

  EXPECT_EQ(dt.get_full_year(), 2025);
}

TEST(Operations, SumMonths) { 
  DateTime dt(2024, 12, 06, 9, 0, 0, -3);
  dt.sum_months(1);

  EXPECT_EQ(dt.get_full_year(), 2025);
  EXPECT_EQ(dt.get_month(), 1);
}

TEST(Operations, SumDays) { 
  DateTime dt(2024, 12, 06, 9, 0, 0, -3);
  
  dt.sum_days(30);

  EXPECT_EQ(dt.get_full_year(), 2025);
  EXPECT_EQ(dt.get_month(), 1);
  EXPECT_EQ(dt.get_day(), 5);
}

TEST(Operations, SumHours) { 
  DateTime dt(2024, 12, 06, 9, 0, 0, -3);
  
  dt.sum_hours(20);

  EXPECT_EQ(dt.get_day(), 7);
  EXPECT_EQ(dt.get_hours(), 5);
}

TEST(Operations, SumMinutes) { 
  DateTime dt(2024, 12, 06, 9, 0, 0, -3);
  
  dt.sum_minutes(70);

  EXPECT_EQ(dt.get_hours(), 10);
  EXPECT_EQ(dt.get_minutes(), 10);
}

TEST(Operations, SumSeconds) { 
  DateTime dt(2024, 12, 06, 9, 0, 0, -3);
  
  dt.sum_seconds(150);

  EXPECT_EQ(dt.get_minutes(), 2);
  EXPECT_EQ(dt.get_seconds(), 30);
}

/// Subtract

TEST(Operations, SubtractYears) { 
  DateTime dt(2024, 12, 06, 9, 0, 0, -3);
  dt.subtract_years(1);

  EXPECT_EQ(dt.get_full_year(), 2023);
}

TEST(Operations, SubtractMonths) { 
  DateTime dt(2025, 1, 06, 9, 0, 0, -3);
  dt.subtract_months(1);

  EXPECT_EQ(dt.get_full_year(), 2024);
  EXPECT_EQ(dt.get_month(), 12);
}

TEST(Operations, SubtractDays) { 
  DateTime dt(2025, 1, 06, 9, 0, 0, -3);
  
  dt.subtract_days(30);

  EXPECT_EQ(dt.get_full_year(), 2024);
  EXPECT_EQ(dt.get_month(), 12);
  EXPECT_EQ(dt.get_day(), 7);
}

TEST(Operations, SubtractHours) { 
  DateTime dt(2024, 12, 06, 9, 0, 0, -3);
  
  dt.subtract_hours(20);

  EXPECT_EQ(dt.get_day(), 5);
  EXPECT_EQ(dt.get_hours(), 13);
}

TEST(Operations, SubtractMinutes) { 
  DateTime dt(2024, 12, 06, 9, 0, 0, -3);
  
  dt.subtract_minutes(70);

  EXPECT_EQ(dt.get_hours(), 7);
  EXPECT_EQ(dt.get_minutes(), 50);
}

TEST(Operations, SubtractSeconds) { 
  DateTime dt(2024, 12, 06, 9, 0, 0, -3);
  
  dt.subtract_seconds(150);
  
  EXPECT_EQ(dt.get_minutes(), 57);
  EXPECT_EQ(dt.get_seconds(), 30);
}

#pragma endregion