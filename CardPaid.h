#ifndef CARDPAID_H_
#define CARDPAID_H_
#include "Money.h"
#include <vector>
#include <string>

using namespace std;

class CardPaid: public Money 
{
   public:
      CardPaid();
      CardPaid(int month, int day, double money, string usage);
      int month, day;

};
#endif //CARDPAID_H_