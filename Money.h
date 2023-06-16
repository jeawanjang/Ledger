#ifndef MONEY_H_
#define MONEY_H_
#include <string>

using namespace std;

class Money 
{
  public:
    Money();
    Money(double money, string usage);
    double money;
    string usage;
};
#endif //MONEY_H_