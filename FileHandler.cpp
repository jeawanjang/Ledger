#include <fstream>
#include <sstream>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm> // added for trim function
#include "FileHandler.h"

using namespace std;

// Function to trim leading and trailing whitespaces from a string
string trim(const string& str)
{
    size_t first = str.find_first_not_of(' ');
    size_t last = str.find_last_not_of(' ');
    if (first == string::npos || last == string::npos)
        return str;
    return str.substr(first, last - first + 1);
}

vector<CardPaid> FileHandler::ReadFileK(string fileName, vector<CardPaid> v) 
{
  ifstream file(fileName);
  if (file.is_open())
  {
    string line;
    while (getline(file, line)) 
    {
      stringstream ss(line);
      string month, day;
      double money;
      string usage;
    
      if (getline(ss, month, ',') && getline(ss, day, ',') && ss >> money)
      {
        getline(ss >> ws, usage); // read the rest of the line as the usage string
        usage = trim(usage); // trim leading and trailing whitespaces from the usage string
        CardPaid cardPaid(stoi(month), stoi(day), money, usage);
        v.push_back(cardPaid);
      }
    }
    file.close();
  }
  else
  {
    cerr << "Error opening file: " << fileName << endl;
  }  
  return v;
}

vector<CardPaid> FileHandler::ReadFileChaseIn(string fileName, vector<CardPaid>& vIN) {
  ifstream file(fileName);
  if (file.is_open()) {
    string line;
    while (getline(file, line)) {
      stringstream ss(line);
      string month, day, usage, money, det;  // Change the type of 'money' and 'det' to string

      // Read all values as strings
      if (getline(ss, month, ',') && getline(ss, day, ',') && getline(ss, usage, ',') && getline(ss, money, ',') && getline(ss, det)) {
        usage = trim(usage); // trim leading and trailing whitespaces from the usage string
        det = trim(det);

        // Create a 'CardPaid' object and add it to the vector if 'det' is "+1"
        if (det == "+1") {
          CardPaid cardPaid(stoi(month), stoi(day), stod(money), usage);
          vIN.push_back(cardPaid);
        }
      }
    }
    file.close();
  } else {
    cerr << "Error opening file: " << fileName << endl;
  }
  // Return the vector with positive values (vIN) as per the function signature
  return vIN;
}

vector<CardPaid> FileHandler::ReadFileChaseOut(string fileName, vector<CardPaid>& vOUT) {
  ifstream file(fileName);
  if (file.is_open()) {
    string line;
    while (getline(file, line)) {
      stringstream ss(line);
      string month, day, usage, money, det;  // Change the type of 'money' and 'det' to string

      // Read all values as strings
      if (getline(ss, month, ',') && getline(ss, day, ',') && getline(ss, usage, ',') && getline(ss, money, ',') && getline(ss, det)) {
        usage = trim(usage); // trim leading and trailing whitespaces from the usage string
        det = trim(det);

        // Create a 'CardPaid' object and add it to the vector if 'det' is "+1"
        if (det == "-1") {
          CardPaid cardPaid(stoi(month), stoi(day), stod(money), usage);
          vOUT.push_back(cardPaid);
        }
      }
    }
    file.close();
  } else {
    cerr << "Error opening file: " << fileName << endl;
  }
  // Return the vector with positive values (vIN) as per the function signature
  return vOUT;
}