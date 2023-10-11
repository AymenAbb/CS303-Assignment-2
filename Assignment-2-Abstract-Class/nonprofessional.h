#include "main.h"

class Nonprofessional : public Employee {
private:
  double hourlyRate = 18.0;
  double hoursWorked;

public:
  Nonprofessional(double hours);
  double salary();
  double healthCost();
  double vacationDays();
};