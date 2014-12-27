#pragma once

#include <initializer_list>
#include "card_deck.hpp"

namespace Poker
{
    class HandRange
    {
    public:
        HandRange();
        HandRange(std::initializer_list<std::initializer_list<int>> rows);
        bool &operator()(Card c1, Card c2);
    private:
        bool x_[15][15];
    };
}

