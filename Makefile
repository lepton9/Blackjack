
SRC := ./src
INC := -I ./include
FLAGS := -c $(INC)
CC := g++

blackjack: blackjack.o AsciiCards.o P.o Player.o Dealer.o Card.o Deck.o Game.o CardCount.o
	$(CC) $^ -o $@

blackjack.o: $(SRC)/blackjack.cpp
	$(CC) $(FLAGS) $<

AsciiCards.o: $(SRC)/AsciiCards.cpp
	$(CC) $(FLAGS) $<

P.o: $(SRC)/P.cpp
	$(CC) $(FLAGS) $<

Player.o: $(SRC)/Player.cpp
	$(CC) $(FLAGS) $<

Dealer.o: $(SRC)/Dealer.cpp
	$(CC) $(FLAGS) $<

Card.o: $(SRC)/Card.cpp
	$(CC) $(FLAGS) $<

Deck.o: $(SRC)/Deck.cpp
	$(CC) $(FLAGS) $<

Game.o: $(SRC)/Game.cpp
	$(CC) $(FLAGS) $<

CardCount.o: $(SRC)/CardCount.cpp
	$(CC) $(FLAGS) $<

debug:
	$(CC) $(INC) $(SRC)/*.cpp -pthread -g -o bjDebug
	gdb -tui bjDebug

run: 
	./blackjack

clean:
	rm *.o bjDebug
