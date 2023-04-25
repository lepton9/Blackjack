#ifndef ASCIICARDS_H
#define ASCIICARDS_H

#include <vector>
#include <string>

using std::vector;
using std::string;

extern vector<vector<string>> asciiCards;
extern vector<vector<string>> utcCards;

vector<string> GetAsciiCard(int cSuit = 0, int cRank = 0);

#endif
