#include <iostream>
#include <string>
#include <chrono> // time import needed
#include <ctime> // time import needed
#include <iomanip>
#include <locale>
#include <vector>
#include "Ledger.h"

using namespace std;

Ledger::Ledger() : monthlyPaid(0, "", 0) {}

void Ledger::PrintTime() 
{
  auto now = chrono::system_clock::now();
  auto current_time = chrono::system_clock::to_time_t(now);
  tm* sf_time = localtime(&current_time);
  // Create a time_point with the correct time zone (San Francisco - Pacific Standard Time)
  auto sf_time_point = chrono::system_clock::from_time_t(current_time);
  sf_time_point -= chrono::hours(7);  // Adjust for the time difference -> do not know why, but it is required to get SF time.
  // Convert the adjusted time_point back to time_t
  current_time = chrono::system_clock::to_time_t(sf_time_point);
  sf_time = localtime(&current_time);
  cout << put_time(sf_time, "%Y-%m-%d %H:%M:%S");

  month = sf_time->tm_mon + 1;  // Add 1 to get the month value (0-11 range -> 1-12 range)
}

// Mainly display the various menu lists w/ brief welcome message
void Ledger::PrintLedgerMenu() 
{
  cout << endl;
  cout << "-----------------------------------------------------------\n";
  cout << "|                  ";
  PrintTime(); // Current time would be updated, whenever printWelcome is called.
  cout << "                    |\n";
  cout << "|                                                         |\n"
       << "|                      Welcome :)                         |\n"
       << "|               (1) Set & View Monthly Subscription       |\n"
       << "|               (2) Update K Card record                  |\n"
       << "|               (3) Update Chase Card Deposit             |\n"
       << "|               (4) Update Chase Card Withdraw            |\n"
       << "|               (5) Check Overall Withdraw                |\n"
       << "|               (0) Exit                                  |\n"
       << "-----------------------------------------------------------\n"
       << "Enter the number: ";
}


void Ledger::SetMonthlyPaid()
{
  monthlyPaid.PutAllSubs();
}

void Ledger::DisplayAllMonthlyPaid()
{
  cout << "All MonthlyPaid Record" << endl;
  cout.imbue(locale("")); // 15450 to 15,450 default locale setting 
  cout << fixed << setprecision(2); // fixed to 2 decimal digits  
  cout << "*********************************************************************" << endl;
  for (int i = 0; i < monthlyPaid.allMonthlyPaid.size(); i++)
  {
    cout << "Usage: " << setw(7) << monthlyPaid.allMonthlyPaid.at(i).usage << "     Money: $" << setw(7) << monthlyPaid.allMonthlyPaid.at(i).money << endl;
  }
  totalMonthlyPaid = (monthlyPaid.money * month);
  cout << "*********************************************************************" << endl;
  cout << "Regular Monthly Spent: $" << monthlyPaid.money << endl;
  cout << "Total Monthly Paid (So Far): $" << totalMonthlyPaid << endl;
  cout << "*********************************************************************" << endl;
}

void Ledger::DisplayKCardPaid()
{
   marugame = 0.0;
   washer = 0.0;
   dryer = 0.0;
   vending = 0.0;
   matcha = 0.0;
   poke = 0.0;
   tuition = 0.0;
   target = 0.0;
   traderjoes = 0.0;
   shakeshack = 0.0;
   quickly = 0.0;
   blazepizza = 0.0;
   baypocha = 0.0;
   sushisuki = 0.0;
   hmarket = 0.0;
   airbnb = 0.0;
   hongkong = 0.0;
   daeho = 0.0;
   apple = 0.0;
   yifang = 0.0;
   gangnam = 0.0;
   chickfila = 0.0;
   healthinsurance = 0.0;
   bakery = 0.0;
   pandaexpress = 0.0;
   delta = 0.0;
   smokeshop = 0.0;
   tangbar = 0.0;
   vietquan = 0.0;
  cout << endl;
  cout << "*********************************************************************" << endl;  
  for (int i = 0; i < allKCardPaid.size(); i++)
  {
    cout << "Date: " << setw(2) << allKCardPaid.at(i).month << "/"
         << setw(2) << allKCardPaid.at(i).day
         << "     Usage: ";
    
    // Check if the comma exists before erasing it
    if (allKCardPaid.at(i).usage.find(',') != string::npos) 
    {
      allKCardPaid.at(i).usage.erase(allKCardPaid.at(i).usage.find(','), 1);  // Remove the comma
    }
    // tracking
    if (allKCardPaid.at(i).usage == (" MARUGAME UDON"))
    {
      marugame += allKCardPaid.at(i).money;
    }
    if (allKCardPaid.at(i).usage == (" LAUNDRY WASHER"))
    {
      washer += allKCardPaid.at(i).money;
    }      
    if (allKCardPaid.at(i).usage == (" LAUNDRY DRYER"))
    {
      dryer += allKCardPaid.at(i).money;
    }
    if (allKCardPaid.at(i).usage == (" VENDING"))
    {
      vending += allKCardPaid.at(i).money;
    }  
    if (allKCardPaid.at(i).usage == (" MATCHA MAIKO"))
    {
      matcha += allKCardPaid.at(i).money;
    }  
    if (allKCardPaid.at(i).usage == (" POKE"))
    {
      poke += allKCardPaid.at(i).money;
    }  
    if (allKCardPaid.at(i).usage == (" SFSU TUITION"))
    {
      tuition += allKCardPaid.at(i).money;
    }  
    if (allKCardPaid.at(i).usage == (" TARGET"))
    {
      target += allKCardPaid.at(i).money;
    }  
    if (allKCardPaid.at(i).usage == (" TRADER JOE'S"))
    {
      traderjoes += allKCardPaid.at(i).money;
    }  
    if (allKCardPaid.at(i).usage == (" SHAKE SHACK BURGER"))
    {
      shakeshack += allKCardPaid.at(i).money;
    }  
    if (allKCardPaid.at(i).usage == (" QUICKLY"))
    {
      quickly += allKCardPaid.at(i).money;
    }  
    if (allKCardPaid.at(i).usage == (" BLAZE PIZZA"))
    {
      blazepizza += allKCardPaid.at(i).money;
    }  
    if (allKCardPaid.at(i).usage == (" BAY POCHA"))
    {
      baypocha += allKCardPaid.at(i).money;
    }  
    if (allKCardPaid.at(i).usage == (" SUSHI SUKI"))
    {
      sushisuki += allKCardPaid.at(i).money;
    }  
    if (allKCardPaid.at(i).usage == (" H MARKET"))
    {
      hmarket += allKCardPaid.at(i).money;
    }  
    if (allKCardPaid.at(i).usage == (" AIRBNB"))
    {
      airbnb += allKCardPaid.at(i).money;
    }  
    if (allKCardPaid.at(i).usage == (" HONG KONG BAN JEOM"))
    {
      hongkong += allKCardPaid.at(i).money;
    }  
    if (allKCardPaid.at(i).usage == (" DAEHO KALBI JJIM"))
    {
      daeho += allKCardPaid.at(i).money;
    }  
    if (allKCardPaid.at(i).usage == (" APPLE STORE"))
    {
      apple += allKCardPaid.at(i).money;
    }  
    if (allKCardPaid.at(i).usage == (" YIFANG"))
    {
      yifang += allKCardPaid.at(i).money;
    }      
    if (allKCardPaid.at(i).usage == (" GANGNAM BBQ"))
    {
      gangnam += allKCardPaid.at(i).money;
    }  
    if (allKCardPaid.at(i).usage == (" CHICK FIL A"))
    {
      chickfila += allKCardPaid.at(i).money;
    }  
    if (allKCardPaid.at(i).usage == (" HEALTH INSURANCE"))
    {
      healthinsurance += allKCardPaid.at(i).money;
    }  
    if (allKCardPaid.at(i).usage == (" 85 BAKERY"))
    {
      bakery += allKCardPaid.at(i).money;
    }  
    if (allKCardPaid.at(i).usage == (" PANDA EXPRESS"))
    {
      pandaexpress += allKCardPaid.at(i).money;
    }  
    if (allKCardPaid.at(i).usage == (" DELTA"))
    {
      delta += allKCardPaid.at(i).money;
    }  
    if (allKCardPaid.at(i).usage == (" SMOKE SHOP"))
    {
      smokeshop += allKCardPaid.at(i).money;
    }      
    if (allKCardPaid.at(i).usage == (" TANG BAR"))
    {
      tangbar += allKCardPaid.at(i).money;
    }  
    if (allKCardPaid.at(i).usage == (" VIET QUAN"))
    {
      vietquan += allKCardPaid.at(i).money;
    }    
    cout << setw(25) << allKCardPaid.at(i).usage
         << "     Money: $" << setw(10) << allKCardPaid.at(i).money
         << endl;
    totalCardPaid += allKCardPaid.at(i).money;
  }  
  cout << "*********************************************************************" << endl;
  cout << setw(25) << "Marugame: $" << marugame << endl; 
  cout << setw(25) << "Laundry Washer: $" << washer << endl;
  cout << setw(25) << "Laundry Dryer: $" << dryer << endl;
  cout << setw(25) << "Vending: $" << vending << endl;
  cout << setw(25) << "Matcha: $" << matcha << endl;
  cout << setw(25) << "Poke: $" << poke << endl;
  cout << setw(25) << "Tuition: $" << tuition << endl;
  cout << setw(25) << "Target: $" << target << endl;
  cout << setw(25) << "Trader Joe's: $" << traderjoes << endl;
  cout << setw(25) << "Shake Shack Burger: $" << shakeshack << endl;
  cout << setw(25) << "Quickly: $" << quickly << endl;
  cout << setw(25) << "Blaze Pizza: $" << blazepizza << endl;
  cout << setw(25) << "Bay Pocha: $" << baypocha << endl;
  cout << setw(25) << "Sushi Suki: $" << sushisuki << endl;
  cout << setw(25) << "H Market: $" << hmarket << endl;
  cout << setw(25) << "Air Bnb: $" << airbnb << endl;
  cout << setw(25) << "Hong Kong Ban Jeom: $" << hongkong << endl;
  cout << setw(25) << "Daeho Kalbi Jjim: $" << daeho << endl;
  cout << setw(25) << "Apple Store: $" << apple << endl;
  cout << setw(25) << "Yi Fang: $" << yifang << endl;
  cout << setw(25) << "Gangnam BBQ: $" << gangnam << endl;
  cout << setw(25) << "Chick Fil A: $" << chickfila << endl;
  cout << setw(25) << "Health Insurance: $" << healthinsurance << endl;
  cout << setw(25) << "85 Bakery: $" << bakery << endl;
  cout << setw(25) << "Panda Express: $" << pandaexpress << endl;
  cout << setw(25) << "Delta: $" << delta << endl;
  cout << setw(25) << "Smoke Shop: $" << smokeshop << endl;
  cout << setw(25) << "Tang Bar: $" << tangbar << endl;
  cout << setw(25) << "Viet Quan: $" << vietquan << endl;
  cout << "*********************************************************************" << endl;
  cout << "Total 'K' Card Withdraw (So Far): $" << totalCardPaid << endl;
  cout << "*********************************************************************" << endl;
}

void Ledger::DisplayChaseCardIn()
{
  cout << endl;
  cout << "*********************************************************************" << endl; 
  for (int i = 0; i < chaseCardIn.size(); i++)
  {
    cout << "Date: " << setw(2) << chaseCardIn.at(i).month << "/"
         << setw(2) << chaseCardIn.at(i).day
         << "     Usage: ";  
    cout << setw(25) << chaseCardIn.at(i).usage
         << "     Money: $" << setw(10) << chaseCardIn.at(i).money
         << endl;
    totalChaseCardIn += chaseCardIn.at(i).money;
  }   
  cout << endl;
  cout << "*********************************************************************" << endl; 
  cout << "Chase Card Deposit: $" << totalChaseCardIn << endl;
  cout << "*********************************************************************" << endl;
}

void Ledger::DisplayChaseCardOut()
{
  cout << endl;
  cout << "*********************************************************************" << endl;   
  for (int i = 0; i < chaseCardOut.size(); i++)
  {
    cout << "Date: " << setw(2) << chaseCardOut.at(i).month << "/"
         << setw(2) << chaseCardOut.at(i).day
         << "     Usage: ";  
    cout << setw(25) << chaseCardOut.at(i).usage
         << "     Money: $" << setw(10) << chaseCardOut.at(i).money
         << endl;
    totalChaseCardOut += chaseCardOut.at(i).money;
  }   
  cout << endl;
  cout << "*********************************************************************" << endl; 
  cout << "Chase Card Withdraw: $" << totalChaseCardOut << endl;
  cout << "*********************************************************************" << endl;  
}

void Ledger::DisplayWholePaid()
{
  cout.imbue(locale("")); // 15450 to 15,450 default locale setting 
  cout << fixed << setprecision(2); // fixed to 2 decimal digits
  cout << endl;
  cout << "*********************************************************************" << endl; 
  cout << "Monthly Withdraw: $ " << totalMonthlyPaid << endl;
  cout << "K Card Withdraw: $ " << totalCardPaid << endl;
  cout << "Chase Card Withdraw: $ " << totalChaseCardOut << endl;
  cout << "Chase Card Deposit: $ " << totalChaseCardIn << endl; 
  cout << "Whole Withdraw (So Far): $" << totalMonthlyPaid + totalCardPaid + totalChaseCardOut - totalChaseCardIn << endl;
  cout << "*********************************************************************" << endl;  
}