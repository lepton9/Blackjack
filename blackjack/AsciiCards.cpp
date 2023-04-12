#include "AsciiCards.h"

using namespace std;

vector<string> GetAsciiCard(tuple<int, int> cardSR) {
	return asciiCards[get<0>(cardSR)*13 + get<1>(cardSR) - 1];
};

vector<vector<string>> asciiCards = {
	{" ______", "|A     |", "|  O   |", "| O|O  |", "|_____A|"}, 
	{" ______", "|2     |", "|  O   |", "| O|O  |", "|_____2|"}, 
	{" ______", "|3     |", "|  O   |", "| O|O  |", "|_____3|"}, 
	{" ______", "|4     |", "|  O   |", "| O|O  |", "|_____4|"}, 
	{" ______", "|5     |", "|  O   |", "| O|O  |", "|_____5|"}, 
	{" ______", "|6     |", "|  O   |", "| O|O  |", "|_____6|"}, 
	{" ______", "|7     |", "|  O   |", "| O|O  |", "|_____7|"}, 
	{" ______", "|8     |", "|  O   |", "| O|O  |", "|_____8|"}, 
	{" ______", "|9     |", "|  O   |", "| O|O  |", "|_____9|"}, 
	{" ______", "|10    |", "|  O   |", "| O|O  |", "|____10|"}, 
	{" ______", "|J     |", "|  O   |", "| O|O  |", "|_____J|"}, 
	{" ______", "|Q     |", "|  O   |", "| O|O  |", "|_____Q|"}, 
	{" ______", "|K     |", "|  O   |", "| O|O  |", "|_____K|"},
	{" ______", "|A     |", "|  /\\  |", "|  \\/  |", "|_____A|"}, 
	{" ______", "|2     |", "|  /\\  |", "|  \\/  |", "|_____2|"}, 
	{" ______", "|3     |", "|  /\\  |", "|  \\/  |", "|_____3|"}, 
	{" ______", "|4     |", "|  /\\  |", "|  \\/  |", "|_____4|"}, 
	{" ______", "|5     |", "|  /\\  |", "|  \\/  |", "|_____5|"}, 
	{" ______", "|6     |", "|  /\\  |", "|  \\/  |", "|_____6|"}, 
	{" ______", "|7     |", "|  /\\  |", "|  \\/  |", "|_____7|"}, 
	{" ______", "|8     |", "|  /\\  |", "|  \\/  |", "|_____8|"}, 
	{" ______", "|9     |", "|  /\\  |", "|  \\/  |", "|_____9|"}, 
	{" ______", "|10    |", "|  /\\  |", "|  \\/  |", "|____10|"}, 
	{" ______", "|J     |", "|  /\\  |", "|  \\/  |", "|_____J|"}, 
	{" ______", "|Q     |", "|  /\\  |", "|  \\/  |", "|_____Q|"}, 
	{" ______", "|K     |", "|  /\\  |", "|  \\/  |", "|_____K|"}, 
	{" ______", "|A     |", "| (\\/) |", "|  \\/  |", "|_____A|"}, 
	{" ______", "|2     |", "| (\\/) |", "|  \\/  |", "|_____2|"}, 
	{" ______", "|3     |", "| (\\/) |", "|  \\/  |", "|_____3|"}, 
	{" ______", "|4     |", "| (\\/) |", "|  \\/  |", "|_____4|"}, 
	{" ______", "|5     |", "| (\\/) |", "|  \\/  |", "|_____5|"}, 
	{" ______", "|6     |", "| (\\/) |", "|  \\/  |", "|_____6|"}, 
	{" ______", "|7     |", "| (\\/) |", "|  \\/  |", "|_____7|"}, 
	{" ______", "|8     |", "| (\\/) |", "|  \\/  |", "|_____8|"}, 
	{" ______", "|9     |", "| (\\/) |", "|  \\/  |", "|_____9|"}, 
	{" ______", "|10    |", "| (\\/) |", "|  \\/  |", "|____10|"}, 
	{" ______", "|J     |", "| (\\/) |", "|  \\/  |", "|_____J|"}, 
	{" ______", "|Q     |", "| (\\/) |", "|  \\/  |", "|_____Q|"}, 
	{" ______", "|K     |", "| (\\/) |", "|  \\/  |", "|_____K|"}, 
	{" ______", "|A     |", "|  /\\  |", "| (__) |", "|_____A|"}, 
	{" ______", "|2     |", "|  /\\  |", "| (__) |", "|_____2|"}, 
	{" ______", "|3     |", "|  /\\  |", "| (__) |", "|_____3|"}, 
	{" ______", "|4     |", "|  /\\  |", "| (__) |", "|_____4|"}, 
	{" ______", "|5     |", "|  /\\  |", "| (__) |", "|_____5|"}, 
	{" ______", "|6     |", "|  /\\  |", "| (__) |", "|_____6|"}, 
	{" ______", "|7     |", "|  /\\  |", "| (__) |", "|_____7|"}, 
	{" ______", "|8     |", "|  /\\  |", "| (__) |", "|_____8|"}, 
	{" ______", "|9     |", "|  /\\  |", "| (__) |", "|_____9|"}, 
	{" ______", "|10    |", "|  /\\  |", "| (__) |", "|____10|"}, 
	{" ______", "|J     |", "|  /\\  |", "| (__) |", "|_____J|"}, 
	{" ______", "|Q     |", "|  /\\  |", "| (__) |", "|_____Q|"}, 
	{" ______", "|K     |", "|  /\\  |", "| (__) |", "|_____K|"}, 
	{" ______", "|      |", "|      |", "|      |", "|______|"}
};

