#pragma once
#include <iostream>
using namespace std;

class Employee {
public:
  virtual double salary() = 0;
  virtual double healthCost() = 0;
  virtual double vacationDays() = 0;
};
