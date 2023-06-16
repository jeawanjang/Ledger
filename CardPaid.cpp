#include "CardPaid.h"
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include <iostream>

using namespace std;

CardPaid::CardPaid() : month(0), day(0), Money(0, "") {}

CardPaid::CardPaid(int month, int day, double money, string usage) : month(month), day(day), Money(money, usage) {}