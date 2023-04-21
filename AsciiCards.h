#ifndef ASCIICARDS_H
#define ASCIICARDS_H

#include <vector>
#include <string>

extern std::vector<std::vector<std::string>> asciiCards;
extern std::vector<std::vector<std::string>> utcCards;

std::vector<std::string> GetAsciiCard(int cSuit = 0, int cRank = 0);

#endif
