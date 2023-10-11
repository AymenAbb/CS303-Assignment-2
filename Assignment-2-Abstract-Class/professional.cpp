#include "professional.h"

/*

Professional:
  - Month pay: $5000
  - Vacations a year: 11 Days
  - Healthcare: 5% of weekly salary

*/

// Professional constructor
Professional::Professional() {
  monthlySalary = 5000.0;
  yearlyVacationDays = 11.0;
}

// Weekly Salary Computation
double Professional::salary() { return monthlySalary / 4.0; }

// Healthcare Contribution Computation
double Professional::healthCost() { return (monthlySalary / 4.0) * 0.05; }

// Vacation Days Computation
double Professional::vacationDays() { return yearlyVacationDays / 52.0; }