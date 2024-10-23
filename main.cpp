#include <iostream>
#include "DateTime.h"

int main(int argc, char *argv[])
{
  DateTime date(2024, 10, 23);
  std::cout << "Date before sum: " << date << std::endl
    << "Summing 10 days...\n";

  date.sum_days(10);

  std::cout << "Date after sum: " << date << std::endl
    << "---------------------------";
    
  DateTime date2(2024, 10, 23);
  std::cout << "\nDay of the year: " << date2.get_day_of_the_year() << std::endl;

  return 0;
}