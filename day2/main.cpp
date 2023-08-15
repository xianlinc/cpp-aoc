#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

enum Hand { Rock, Paper, Scissors };
enum Outcome { Win, Draw, Loss };

struct Shape {
  int hand;
};

Outcome won(Hand p1, Hand p2) {
  if (p1 == Rock) {
    if (p2 == Scissors) {
      return Win;
    } else if (p2 == Rock) {
      return Draw;
    } else {
      return Loss;
    }
  }
  if (p1 == Paper) {
    if (p2 == Rock) {
      return Win;
    } else if (p2 == Paper) {
      return Draw;
    } else {
      return Loss;
    }
  }
  if (p1 == Scissors) {
    if (p2 == Paper) {
      return Win;
    } else if (p2 == Scissors) {
      return Draw;
    } else {
      return Loss;
    }
  }
  throw string("Unknown outcome");
}

int getScore(Hand p1, Hand p2) {
  int total = 0;
  if (p1 == Rock) {
    total = 1;
  } else if (p1 == Paper) {
    total = 2;
  } else {
    total = 3;
  }

  Outcome outcome = won(p1, p2);
  if (outcome == Win) {
    total += 6;
  } else if (outcome == Draw) {
    total += 3;
  } else {
    // do nothing
  }

  return total;
}

Hand parseOpp(char c) {
  switch (c) {
  case 'A':
    return Rock;
  case 'B':
    return Paper;
  case 'C':
    return Scissors;
  default:
    printf("unable to parse Opp: %c\n", c);
    throw;
  }
}

Hand parsePlayer(char c) {
  switch (c) {
  case 'X':
    return Rock;
  case 'Y':
    return Paper;
  case 'Z':
    return Scissors;
  default:
    printf("unable to parse Player: %c\n", c);
    throw;
  }
}

Hand parsePlayerTwo(Hand opp, char c) {
  Hand arr[3] = {Rock, Paper, Scissors};
  Outcome o;
  if (c == 'Z') {
    o = Win;
  } else if (c == 'Y') {
    o = Draw;
  } else {
    o = Loss;
  }

  for (int i = 0; i < 3; i++) {
    if (won(arr[i], opp) == o) {
      return arr[i];
    }
  }

  printf("Could not parse part 2 hand\n");
  throw;
}

int part2(ifstream *f) {
  char opp, player;
  int score = 0;
  Hand p1, p2;
  string line;
  while (getline(*f, line)) {
    if (line == "") {
      continue;
    }
    istringstream ss(line);
    ss >> opp >> player;
    p2 = parseOpp(opp);
    p1 = parsePlayerTwo(p2, player);
    score += getScore(p1, p2);
  }
  printf("score: %d\n", score);
  return score;
}

int part1(ifstream *f) {
  char opp, player;
  int score = 0;
  Hand p1, p2;
  string line;
  while (getline(*f, line)) {
    if (line == "") {
      continue;
    }
    istringstream ss(line);
    ss >> opp >> player;
    p1 = parsePlayer(player);
    p2 = parseOpp(opp);
    score += getScore(p1, p2);
    printf("round: %c,%c = %d\n", opp, player, score);
  }
  printf("score: %d\n", score);
  return score;
}

int main(int argc, char *argv[1]) {
  ifstream f(argv[1]);
  part2(&f);
  return 0;
}
