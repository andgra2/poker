#include "hand_range.hpp"

namespace Poker
{
    HandRange::HandRange()
    {
        for (int i = 2; i != 15; ++i)
            for (int j = 2; j != 15; ++j)
                x_[i][j] = false;
    }

    HandRange::HandRange(std::initializer_list<std::initializer_list<int>> rows)
    {
        int j = 14;
        for (const std::initializer_list<int> &row : rows)
        {
            int i = 14;
            for (int x : row)
            {
                x_[i][j] = static_cast<bool>(x);
                --i;
            }
            --j;
        }
    }
    
    bool &HandRange::operator()(Card c1, Card c2)
    {
        if (c2.value < c1.value) std::swap(c1, c2);
    
        int i, j;
        if (c1.suit == c2.suit)
        {
            i = c1.value;
            j = c2.value;
        }
        else
        {
            i = c2.value;
            j = c1.value;
        }

        return x_[i][j];
    }
}

