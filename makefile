all:
	g++ -std=c++11 -Wall -Wextra main.cpp card_deck.cpp hand.cpp hand_range.cpp -o test
clean:
	rm -f *.o test

