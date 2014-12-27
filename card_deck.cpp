#include "card_deck.hpp"

namespace Poker
{
    char card_value_to_string(int value)
    {
        switch (value)
        {
        case 2: return '2'; break;
        case 3: return '3'; break;
        case 4: return '4'; break;
        case 5: return '5'; break;
        case 6: return '6'; break;
        case 7: return '7'; break;
        case 8: return '8'; break;
        case 9: return '9'; break;
        case 10: return 'T'; break;
        case 11: return 'J'; break;
        case 12: return 'Q'; break;
        case 13: return 'K'; break;
        case 14: return 'A'; break;
        }
    }

    char card_suit_to_string(Suit suit)
    {
        switch (suit)
        {
        case Suit::h: return 'h'; break;
        case Suit::d: return 'd'; break;
        case Suit::c: return 'c'; break;
        case Suit::s: return 's'; break;
        }
    }

    std::string card_to_string(Card c)
    {
        std::string r;

        r.push_back(card_value_to_string(c.value));
        r.push_back(card_suit_to_string(c.suit));

        return r;
    }

    CardDeck::CardDeck() : CardDeck(std::vector<Card>{})
    {
    }

    CardDeck::CardDeck(std::vector<Card> removed_cards)
    {
        for (auto s : std::vector<Suit>{Suit::h, Suit::d, Suit::c, Suit::s})
            for (int v = 2; v != 15; ++v)
            {
                if (find(removed_cards.begin(), removed_cards.end(), Card(v, s)) == removed_cards.end())
                    cards_.emplace_back(v, s);
            }

        reset();
    }

    void CardDeck::reset()
    {
        next_card_ = cards_.cbegin();

        random_shuffle(cards_.begin(), cards_.end());
    }
}

