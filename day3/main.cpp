#include <fstream>
#include <iostream>
#include <string>
#include <unordered_set>
#define SIZE 10000
using namespace std;

int convert(char c) {
  string s = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
  return s.find(c) + 1;
}

int parseLine(string line) {
  // find matching elems in two halves
  unordered_set<char> myset;
  unordered_set<char> matches;

  for (int i = 0; i < line.length(); i++) {
    if (i < line.length() / 2) {
      myset.insert(line[i]);
    } else {
      if (myset.count(line[i]) > 0) {
        matches.insert(line[i]);
      }
    }
  }

  int total = 0;
  for (unordered_set<char>::iterator it = matches.cbegin();
       it != matches.cend(); ++it) {
    char c = *it;
    total += convert(c);
  }
  return total;
}

int main(int argc, char *argv[]) {
  string filename;  // Name of the file
  string line;      // To read each line from code
  int i = 0;        // Variable to keep count of each line
  string arr[SIZE]; // array to store each line

  filename = argv[1];
  ifstream mFile(filename);
  if (mFile.is_open()) {
    while (!mFile.eof()) {
      getline(mFile, line);
      arr[i] = line;
      i++;
    }
    mFile.close();
  } else
    cout << "Couldn't open the file\n";

  int numLines = i;

  int total = 0;
  for (int j = 0; j < numLines; j++) {
    total += parseLine(arr[j]);
  }
  cout << "total: " << total << "\n";

  return 0;
}
