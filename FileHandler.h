#ifndef FILEHANDLER_H_
#define FILEHANDLER_H_
#include <string>
#include <vector>
#include "CardPaid.h"

// FileHandler class is created to deal with reading file.
class FileHandler {
public: 
  vector<CardPaid> ReadFileK(string filename, vector<CardPaid> v);
  vector<CardPaid> ReadFileChaseIn(string filename, vector<CardPaid>& vIN);
  vector<CardPaid> ReadFileChaseOut(string filename, vector<CardPaid>& vOUT);
};
#endif // FILEHANDLER_H_