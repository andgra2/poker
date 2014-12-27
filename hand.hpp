#pragma once

#include <iostream>
#include <algorithm>
#include <array>
#include <vector>
#include "card_deck.hpp"

namespace Poker
{
    enum class HandType {other, straight, flush, full_house, four_of_a_kind, straight_flush};

    class Hand
    {
    friend bool operator<(const Hand &h1, const Hand &h2);
    public:
        Hand(Card cards_pocket[2], Card cards_table[5]);
    private:
        static int get_straight_value(int card_values[], int n);

        HandType type_;

        int normal_counts_[2];
        int normal_counts_size_;
        int normal_values_[5];
        int normal_values_size_;

        int straight_value_;

        int flush_values_[5];

        int straight_flush_value_;
    };

    bool operator<(const Hand &h1, const Hand &h2);
}

