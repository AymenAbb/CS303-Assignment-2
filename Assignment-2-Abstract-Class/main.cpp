#include "nonprofessional.h"
#include "professional.h"
#include <iostream>

int main() {

  // Professional Employee Menu
  Professional employeePro = Professional();

  cout << "\nProfessional Employee:" << endl;
  cout << "  Weekly Salary: $" << employeePro.salary() << endl;
  cout << "  Weekly Healthcare Contribution: $" << employeePro.healthCost()
       << endl;
  cout << "  Vacation Days Earned this Week: " << employeePro.vacationDays()
       << " days" << endl
       << endl;

  // Non-Professional Employee Menu
  double hours = 0;
  cout << "How many hours did the non-professional employee work this week? ";
  cin >> hours;
  Nonprofessional employeeNon = Nonprofessional(hours);
  cout << "\nNonprofessional Employee:\n";
  cout << "\tWeekly Salary: $" << employeeNon.salary() << endl;
  cout << "\tWeekly Healthcare Contribution: $" << employeeNon.healthCost()
       << endl;
  cout << "\tVacation Days Earned this Week: " << employeeNon.vacationDays()
       << " days\n\n";
}