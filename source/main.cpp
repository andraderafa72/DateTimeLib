#include <iostream>
#include "date_time.h"

int main(int argc, char *argv[])
{
  DateTime date(2024, 10, 23);
  std::cout << "Date before sum: " << date << std::endl
    << "Summing 10 days...\n";

  date.sum_days(10);

  std::cout << "Date after sum: " << date << std::endl
    << "---------------------------";
    
  DateTime date2(2024, 10, 23);
  date2.timezone = -3;
  std::cout << "\nDate string: " << date2.to_string();
  std::cout << "\nDate ISO string: " << date2.to_ISO_string();
  std::cout << "\nDay of the year: " << date2.get_day_of_the_year();

  return 0;
}