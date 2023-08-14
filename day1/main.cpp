#include <array>
#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;
void parse() {
  ifstream infile("input");
  string line;
  int most = 0;
  int cur = 0;
  while (getline(infile, line)) {
    if (line == "") {
      cur = 0;
    } else {
      int cals = stoi(line);
      cur += cals;
      if (cur > most) {
        most = cur;
      }
    }
  }
  printf("most: %d\n", most);
}

int main() {
  parse();
  return 0;
}
