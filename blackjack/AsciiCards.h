#ifndef ASCIICARDS_H
#define ASCIICARDS_H

#include <vector>
#include <string>
#include <tuple>

extern std::vector<std::vector<std::string>> asciiCards;
std::vector<std::string> GetAsciiCard(std::tuple<int, int> cardSR);

#endif
