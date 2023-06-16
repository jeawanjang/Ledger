#include <iostream>
#include "Ledger.h"

#include <string>
#include <iomanip>
#include <vector>
#include <locale>

// 추가할것 (1) 파일쓰기 (2) 월별 데이터 결산  << 이거 먼저 (3) Sorting
using namespace std;

int main() 
{
  Ledger ledger;
  FileHandler fileHandler;
  double total = 0;
  int choice;

  // Read both file "KCard" and "ChaseCard"
  ledger.allKCardPaid = fileHandler.ReadFileK("KCard", ledger.allKCardPaid);
  ledger.chaseCardIn = fileHandler.ReadFileChaseIn("ChaseCard", ledger.chaseCardIn);
  ledger.chaseCardOut = fileHandler.ReadFileChaseOut("ChaseCard", ledger.chaseCardOut);
  
  do 
  {
    ledger.PrintLedgerMenu();
    cin >> choice;

    switch (choice) {
      case 1:
        ledger.SetMonthlyPaid();
        ledger.DisplayAllMonthlyPaid();
        break;
      case 2:
        ledger.DisplayKCardPaid();
        break;
      case 3:
        ledger.DisplayChaseCardIn();
        break;
      case 4: 
        ledger.DisplayChaseCardOut();
        break; 
      case 5:
      {
          ledger.DisplayWholePaid();
          total = ledger.totalCardPaid + ledger.totalMonthlyPaid + ledger.totalChaseCardOut - ledger.totalChaseCardIn;

          double convertor = 0;
          if (total <= 0)
          {
            cout << "Cannot Convert due to invalid input" << endl;
          }  
          else
          {
            cout << "Enter the exchange rate for $1 as: ₩";
            cin >> convertor;
            cout << "*********************************************************************" << endl;    
            total = (total * convertor); 
            cout.imbue(locale("")); // 15450 to 15,450 default locale setting 
            cout << fixed << setprecision(2); // fixed to 2 decimal digits
            cout << "Whole Withdraw (So Far): ₩" << total << endl;
            cout << "*********************************************************************" << endl;    
          }  
        break;
      }  
      case 0:
        cout << "Exiting the program. Goodbye!" << endl;
        break;
      default:
        cout << "Invalid choice. Please try again." << endl;
          break;
      }
  } while (choice != 0);
  return 0;   
}

