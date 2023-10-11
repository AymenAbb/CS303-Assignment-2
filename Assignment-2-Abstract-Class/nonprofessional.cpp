#include "nonprofessional.h"

/*

Non-professional:
  - Hourly pay: 18
  - Vacations per 40 hours: 3 hours
  - Healthcare: 2% of weekly salary

*/

// Nonprofessional constructor
Nonprofessional::Nonprofessional(double hours) { hoursWorked = hours; }

// Weekly Salary Computation
double Nonprofessional::salary() { return (hourlyRate * hoursWorked); }

// Healthcare contribution Computation
double Nonprofessional::healthCost() {
  return (hourlyRate * hoursWorked) * 0.02;
}

// Vacation Time Computation
double Nonprofessional::vacationDays() { return (hoursWorked * 0.075 / 24.0); }