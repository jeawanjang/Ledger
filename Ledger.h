#ifndef LEDGER_H_
#define LEDGER_H_
#include "MonthlyPaid.h"
#include "CardPaid.h"
#include "FileHandler.h"
#include <string>
#include <iostream>
#include <vector>

class Ledger
{
  private:
    MonthlyPaid monthlyPaid;
  public:
    Ledger();
    vector<CardPaid> allKCardPaid;  
    vector<CardPaid> chaseCardIn;
    vector<CardPaid> chaseCardOut;

    vector<Money> KCardPaidTrack;

    int month;

    double totalMonthlyPaid;
    double totalCardPaid;
    double totalChaseCardIn;
    double totalChaseCardOut;

    void PrintTime();
    void PrintLedgerMenu();
    void SetMonthlyPaid();
    void DisplayAllMonthlyPaid();
    void DisplayKCardPaid();
    void DisplayChaseCardIn();
    void DisplayChaseCardOut();
    void DisplayWholePaid();

    // Specific usage
    double marugame;
    double washer;
    double dryer;
    double vending;
    double matcha;
    double poke;
    double tuition;
    double target;
    double traderjoes;
    double shakeshack;
    double quickly;
    double blazepizza;
    double baypocha;
    double sushisuki;
    double hmarket;
    double airbnb;
    double hongkong;
    double daeho;
    double apple;
    double yifang;
    double gangnam;
    double chickfila;
    double healthinsurance;
    double bakery;
    double pandaexpress;
    double delta;
    double smokeshop;
    double tangbar;
    double vietquan;
};



#endif // LEDGER_H_