#include <array>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <queue>
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

void part2() {
  priority_queue<int> pq;
  ifstream infile("input");
  string line;
  int cur = 0;
  while (getline(infile, line)) {
    if (line == "") {
      pq.push(-1 * cur);
      if (pq.size() > 3) {
        pq.pop();
      }
      cur = 0;
      continue;
    }

    int cals = stoi(line);
    cur += cals;

    if (infile.peek() == EOF) {
      pq.push(-1 * cur);
      if (pq.size() > 3) {
        pq.pop();
      }
      cur = 0;
    }
  }

  int total = 0;
  while (!pq.empty()) {
    total += -1 * pq.top();
    pq.pop();
  }
  printf("total: %d\n", total);
}

int main() {
  // parse();
  part2();
  return 0;
}
