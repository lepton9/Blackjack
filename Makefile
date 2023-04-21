
blackjack: blackjack.o AsciiCards.o
	g++ blackjack.o AsciiCards.o -o blackjack

blackjack.o: blackjack.cpp
	g++ -c blackjack.cpp

AsciiCards.o: AsciiCards.cpp
	g++ -c AsciiCards.cpp

debug:
	g++ blackjack.cpp AsciiCards.cpp -pthread -g -o bjDebug
	gdb -tui bjDebug

run: 
	./blackjack

clean:
	rm *.o blackjack bjDebug
