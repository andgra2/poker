#pragma once

#include <algorithm>
#include <array>
#include <vector>
#include <string>

namespace Poker
{
    enum class Suit {h, d, c, s};

    struct Card
    {
        Card() {}
        Card(int v, Suit s);
        int value;
        Suit suit;
    };

    inline Card::Card(int v, Suit s)
    {
        value = v;
        suit = s;
    }

    inline bool operator==(Card c1, Card c2)
    {
        return c1.value == c2.value && c1.suit == c2.suit;
    }

    char card_value_to_string(int value);
    char card_suit_to_string(Suit suit);
    std::string card_to_string(Card c);

    class CardDeck
    {
    public:
        CardDeck();
        CardDeck(std::vector<Card> removed_cards);
        Card deal();
        void reset();
    private:
        std::vector<Card> cards_;
        std::vector<Card>::const_iterator next_card_;
    };

    inline Card CardDeck::deal()
    {
        return *(next_card_++);
    }

}

