#include "AsciiCards.h"
#include <iostream>

using std::cout;

vector<string> GetAsciiCard(int cSuit, int cRank) {
	return utcCards[cSuit*13 + cRank];
};

vector<vector<string>> asciiCards = {
	{" ______ ", "|      |", "|      |", "|      |", "|______|"}, 
	{" ______ ", "|A     |", "|  O   |", "| O|O  |", "|_____A|"}, 
	{" ______ ", "|2     |", "|  O   |", "| O|O  |", "|_____2|"}, 
	{" ______ ", "|3     |", "|  O   |", "| O|O  |", "|_____3|"}, 
	{" ______ ", "|4     |", "|  O   |", "| O|O  |", "|_____4|"}, 
	{" ______ ", "|5     |", "|  O   |", "| O|O  |", "|_____5|"}, 
	{" ______ ", "|6     |", "|  O   |", "| O|O  |", "|_____6|"}, 
	{" ______ ", "|7     |", "|  O   |", "| O|O  |", "|_____7|"}, 
	{" ______ ", "|8     |", "|  O   |", "| O|O  |", "|_____8|"}, 
	{" ______ ", "|9     |", "|  O   |", "| O|O  |", "|_____9|"}, 
	{" ______ ", "|10    |", "|  O   |", "| O|O  |", "|____10|"}, 
	{" ______ ", "|J     |", "|  O   |", "| O|O  |", "|_____J|"}, 
	{" ______ ", "|Q     |", "|  O   |", "| O|O  |", "|_____Q|"}, 
	{" ______ ", "|K     |", "|  O   |", "| O|O  |", "|_____K|"},
	{" ______ ", "|A     |", "|  /\\  |", "|  \\/  |", "|_____A|"}, 
	{" ______ ", "|2     |", "|  /\\  |", "|  \\/  |", "|_____2|"}, 
	{" ______ ", "|3     |", "|  /\\  |", "|  \\/  |", "|_____3|"}, 
	{" ______ ", "|4     |", "|  /\\  |", "|  \\/  |", "|_____4|"}, 
	{" ______ ", "|5     |", "|  /\\  |", "|  \\/  |", "|_____5|"}, 
	{" ______ ", "|6     |", "|  /\\  |", "|  \\/  |", "|_____6|"}, 
	{" ______ ", "|7     |", "|  /\\  |", "|  \\/  |", "|_____7|"}, 
	{" ______ ", "|8     |", "|  /\\  |", "|  \\/  |", "|_____8|"}, 
	{" ______ ", "|9     |", "|  /\\  |", "|  \\/  |", "|_____9|"}, 
	{" ______ ", "|10    |", "|  /\\  |", "|  \\/  |", "|____10|"}, 
	{" ______ ", "|J     |", "|  /\\  |", "|  \\/  |", "|_____J|"}, 
	{" ______ ", "|Q     |", "|  /\\  |", "|  \\/  |", "|_____Q|"}, 
	{" ______ ", "|K     |", "|  /\\  |", "|  \\/  |", "|_____K|"}, 
	{" ______ ", "|A     |", "| (\\/) |", "|  \\/  |", "|_____A|"}, 
	{" ______ ", "|2     |", "| (\\/) |", "|  \\/  |", "|_____2|"}, 
	{" ______ ", "|3     |", "| (\\/) |", "|  \\/  |", "|_____3|"}, 
	{" ______ ", "|4     |", "| (\\/) |", "|  \\/  |", "|_____4|"}, 
	{" ______ ", "|5     |", "| (\\/) |", "|  \\/  |", "|_____5|"}, 
	{" ______ ", "|6     |", "| (\\/) |", "|  \\/  |", "|_____6|"}, 
	{" ______ ", "|7     |", "| (\\/) |", "|  \\/  |", "|_____7|"}, 
	{" ______ ", "|8     |", "| (\\/) |", "|  \\/  |", "|_____8|"}, 
	{" ______ ", "|9     |", "| (\\/) |", "|  \\/  |", "|_____9|"}, 
	{" ______ ", "|10    |", "| (\\/) |", "|  \\/  |", "|____10|"}, 
	{" ______ ", "|J     |", "| (\\/) |", "|  \\/  |", "|_____J|"}, 
	{" ______ ", "|Q     |", "| (\\/) |", "|  \\/  |", "|_____Q|"}, 
	{" ______ ", "|K     |", "| (\\/) |", "|  \\/  |", "|_____K|"}, 
	{" ______ ", "|A     |", "|  /\\  |", "| (__) |", "|_____A|"}, 
	{" ______ ", "|2     |", "|  /\\  |", "| (__) |", "|_____2|"}, 
	{" ______ ", "|3     |", "|  /\\  |", "| (__) |", "|_____3|"}, 
	{" ______ ", "|4     |", "|  /\\  |", "| (__) |", "|_____4|"}, 
	{" ______ ", "|5     |", "|  /\\  |", "| (__) |", "|_____5|"}, 
	{" ______ ", "|6     |", "|  /\\  |", "| (__) |", "|_____6|"}, 
	{" ______ ", "|7     |", "|  /\\  |", "| (__) |", "|_____7|"}, 
	{" ______ ", "|8     |", "|  /\\  |", "| (__) |", "|_____8|"}, 
	{" ______ ", "|9     |", "|  /\\  |", "| (__) |", "|_____9|"}, 
	{" ______ ", "|10    |", "|  /\\  |", "| (__) |", "|____10|"}, 
	{" ______ ", "|J     |", "|  /\\  |", "| (__) |", "|_____J|"}, 
	{" ______ ", "|Q     |", "|  /\\  |", "| (__) |", "|_____Q|"}, 
	{" ______ ", "|K     |", "|  /\\  |", "| (__) |", "|_____K|"}
};

vector<vector<string>> utcCards = {
	{" ______ ", "|░░░░░░|", "|░░░░░░|", "|░░░░░░|", "|░░░░░░|", " ‾‾‾‾‾‾ "}, 
	{" ______ ", "|A     |", "|  O   |", "| O|O  |", "|     A|", " ‾‾‾‾‾‾ "}, 
	{" ______ ", "|2     |", "|  O   |", "| O|O  |", "|     2|", " ‾‾‾‾‾‾ "}, 
	{" ______ ", "|3     |", "|  O   |", "| O|O  |", "|     3|", " ‾‾‾‾‾‾ "}, 
	{" ______ ", "|4     |", "|  O   |", "| O|O  |", "|     4|", " ‾‾‾‾‾‾ "}, 
	{" ______ ", "|5     |", "|  O   |", "| O|O  |", "|     5|", " ‾‾‾‾‾‾ "}, 
	{" ______ ", "|6     |", "|  O   |", "| O|O  |", "|     6|", " ‾‾‾‾‾‾ "}, 
	{" ______ ", "|7     |", "|  O   |", "| O|O  |", "|     7|", " ‾‾‾‾‾‾ "}, 
	{" ______ ", "|8     |", "|  O   |", "| O|O  |", "|     8|", " ‾‾‾‾‾‾ "}, 
	{" ______ ", "|9     |", "|  O   |", "| O|O  |", "|     9|", " ‾‾‾‾‾‾ "}, 
	{" ______ ", "|10    |", "|  O   |", "| O|O  |", "|    10|", " ‾‾‾‾‾‾ "}, 
	{" ______ ", "|J     |", "|  O   |", "| O|O  |", "|     J|", " ‾‾‾‾‾‾ "}, 
	{" ______ ", "|Q     |", "|  O   |", "| O|O  |", "|     Q|", " ‾‾‾‾‾‾ "}, 
	{" ______ ", "|K     |", "|  O   |", "| O|O  |", "|     K|", " ‾‾‾‾‾‾ "}, 
	{" ______ ", "|A     |", "|  /\\  |", "|  \\/  |", "|     A|", " ‾‾‾‾‾‾ "}, 
	{" ______ ", "|2     |", "|  /\\  |", "|  \\/  |", "|     2|", " ‾‾‾‾‾‾ "}, 
	{" ______ ", "|3     |", "|  /\\  |", "|  \\/  |", "|     3|", " ‾‾‾‾‾‾ "}, 
	{" ______ ", "|4     |", "|  /\\  |", "|  \\/  |", "|     4|", " ‾‾‾‾‾‾ "}, 
	{" ______ ", "|5     |", "|  /\\  |", "|  \\/  |", "|     5|", " ‾‾‾‾‾‾ "}, 
	{" ______ ", "|6     |", "|  /\\  |", "|  \\/  |", "|     6|", " ‾‾‾‾‾‾ "}, 
	{" ______ ", "|7     |", "|  /\\  |", "|  \\/  |", "|     7|", " ‾‾‾‾‾‾ "}, 
	{" ______ ", "|8     |", "|  /\\  |", "|  \\/  |", "|     8|", " ‾‾‾‾‾‾ "}, 
	{" ______ ", "|9     |", "|  /\\  |", "|  \\/  |", "|     9|", " ‾‾‾‾‾‾ "}, 
	{" ______ ", "|10    |", "|  /\\  |", "|  \\/  |", "|    10|", " ‾‾‾‾‾‾ "}, 
	{" ______ ", "|J     |", "|  /\\  |", "|  \\/  |", "|     J|", " ‾‾‾‾‾‾ "}, 
	{" ______ ", "|Q     |", "|  /\\  |", "|  \\/  |", "|     Q|", " ‾‾‾‾‾‾ "}, 
	{" ______ ", "|K     |", "|  /\\  |", "|  \\/  |", "|     K|", " ‾‾‾‾‾‾ "}, 
	{" ______ ", "|A     |", "| (\\/) |", "|  \\/  |", "|     A|", " ‾‾‾‾‾‾ "}, 
	{" ______ ", "|2     |", "| (\\/) |", "|  \\/  |", "|     2|", " ‾‾‾‾‾‾ "}, 
	{" ______ ", "|3     |", "| (\\/) |", "|  \\/  |", "|     3|", " ‾‾‾‾‾‾ "}, 
	{" ______ ", "|4     |", "| (\\/) |", "|  \\/  |", "|     4|", " ‾‾‾‾‾‾ "}, 
	{" ______ ", "|5     |", "| (\\/) |", "|  \\/  |", "|     5|", " ‾‾‾‾‾‾ "}, 
	{" ______ ", "|6     |", "| (\\/) |", "|  \\/  |", "|     6|", " ‾‾‾‾‾‾ "}, 
	{" ______ ", "|7     |", "| (\\/) |", "|  \\/  |", "|     7|", " ‾‾‾‾‾‾ "}, 
	{" ______ ", "|8     |", "| (\\/) |", "|  \\/  |", "|     8|", " ‾‾‾‾‾‾ "}, 
	{" ______ ", "|9     |", "| (\\/) |", "|  \\/  |", "|     9|", " ‾‾‾‾‾‾ "}, 
	{" ______ ", "|10    |", "| (\\/) |", "|  \\/  |", "|    10|", " ‾‾‾‾‾‾ "}, 
	{" ______ ", "|J     |", "| (\\/) |", "|  \\/  |", "|     J|", " ‾‾‾‾‾‾ "}, 
	{" ______ ", "|Q     |", "| (\\/) |", "|  \\/  |", "|     Q|", " ‾‾‾‾‾‾ "}, 
	{" ______ ", "|K     |", "| (\\/) |", "|  \\/  |", "|     K|", " ‾‾‾‾‾‾ "}, 
	{" ______ ", "|A     |", "|  /\\  |", "| (__) |", "|     A|", " ‾‾‾‾‾‾ "}, 
	{" ______ ", "|2     |", "|  /\\  |", "| (__) |", "|     2|", " ‾‾‾‾‾‾ "}, 
	{" ______ ", "|3     |", "|  /\\  |", "| (__) |", "|     3|", " ‾‾‾‾‾‾ "}, 
	{" ______ ", "|4     |", "|  /\\  |", "| (__) |", "|     4|", " ‾‾‾‾‾‾ "}, 
	{" ______ ", "|5     |", "|  /\\  |", "| (__) |", "|     5|", " ‾‾‾‾‾‾ "}, 
	{" ______ ", "|6     |", "|  /\\  |", "| (__) |", "|     6|", " ‾‾‾‾‾‾ "}, 
	{" ______ ", "|7     |", "|  /\\  |", "| (__) |", "|     7|", " ‾‾‾‾‾‾ "}, 
	{" ______ ", "|8     |", "|  /\\  |", "| (__) |", "|     8|", " ‾‾‾‾‾‾ "}, 
	{" ______ ", "|9     |", "|  /\\  |", "| (__) |", "|     9|", " ‾‾‾‾‾‾ "}, 
	{" ______ ", "|10    |", "|  /\\  |", "| (__) |", "|    10|", " ‾‾‾‾‾‾ "}, 
	{" ______ ", "|J     |", "|  /\\  |", "| (__) |", "|     J|", " ‾‾‾‾‾‾ "}, 
	{" ______ ", "|Q     |", "|  /\\  |", "| (__) |", "|     Q|", " ‾‾‾‾‾‾ "}, 
	{" ______ ", "|K     |", "|  /\\  |", "| (__) |", "|     K|", " ‾‾‾‾‾‾ "}
};
