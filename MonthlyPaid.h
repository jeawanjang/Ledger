#ifndef MONTHLYPAID_H_
#define MONTHLYPAID_H_
#include <vector>
#include <string>
#include "Money.h"

using namespace std;

class MonthlyPaid: public Money 
{
  
  public:
    vector<Money> allMonthlyPaid;
    int whatMonth;
    MonthlyPaid();
    MonthlyPaid(double money, string usage, int whatMonth);
    void PutAllSubs();

};

#endif // MONTHLYPAID_H_