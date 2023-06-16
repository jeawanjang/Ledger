#include "MonthlyPaid.h"
#include <string>
#include <iostream>
#include <vector>

using namespace std;

MonthlyPaid:: MonthlyPaid() : Money(0, "") {}

MonthlyPaid:: MonthlyPaid(double money, string usage, int whatMonth) : Money(money, usage), whatMonth(whatMonth) {}

void MonthlyPaid::PutAllSubs()
{
  double tempMoney;
  string tempUsage;
  do 
  {
    cout << "($0: exit) Enter the monthly paid: $" ;
    cin >> tempMoney;
    cout << endl;
    cout << "(when $0, type 'd') Enter the usage: ";
    cin >> tempUsage;
    cout << endl;
      
    if (tempMoney != 0)
    {
      Money moneyConstructor(tempMoney, tempUsage);
      allMonthlyPaid.push_back(moneyConstructor); 
    }  
    money += tempMoney;
  }
  while (tempMoney != 0);
}
