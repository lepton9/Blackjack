
blackjack: blackjack.o AsciiCards.o
	g++ blackjack.o AsciiCards.o -o blackjack

blackjack.o: blackjack.cpp
	g++ -c blackjack.cpp

AsciiCards.o: AsciiCards.cpp
	g++ -c AsciiCards.cpp

clean:
	rm *.o blackjack
