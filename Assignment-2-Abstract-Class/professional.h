#include "main.h"

class Professional : public Employee {
private:
  double monthlySalary;
  double yearlyVacationDays;

public:
  Professional();
  double salary();
  double healthCost();
  double vacationDays();
};