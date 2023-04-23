
blackjack: blackjack.o AsciiCards.o P.o Player.o Dealer.o Card.o Deck.o Game.o
	g++ blackjack.o AsciiCards.o P.o Player.o Dealer.o Card.o Deck.o Game.o -o blackjack

blackjack.o: blackjack.cpp
	g++ -c blackjack.cpp

AsciiCards.o: AsciiCards.cpp
	g++ -c AsciiCards.cpp

P.o: P.cpp
	g++ -c P.cpp

Player.o: Player.cpp
	g++ -c Player.cpp

Dealer.o: Dealer.cpp
	g++ -c Dealer.cpp

Card.o: Card.cpp
	g++ -c Card.cpp

Deck.o: Deck.cpp
	g++ -c Deck.cpp

Game.o: Game.cpp
	g++ -c Game.cpp


debug:
	g++ *.cpp -pthread -g -o bjDebug
	gdb -tui bjDebug

run: 
	./blackjack

clean:
	rm *.o blackjack bjDebug
