#include "Money.h"
#include <string>
using namespace std;

Money::Money() 
{
  money = 0;
}

Money::Money(double money, string usage) 
{
  this->money = money;
  this->usage = usage;
}

