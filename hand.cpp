#include "hand.hpp"

namespace Poker
{
    bool operator<(const Hand &h1, const Hand &h2)
    {
        if (static_cast<int>(h1.type_) < static_cast<int>(h2.type_))
            return true;
        else if (static_cast<int>(h1.type_) == static_cast<int>(h2.type_))
        {
            switch (h1.type_)
            {
            case HandType::other:
            case HandType::full_house:
            case HandType::four_of_a_kind:
                if (std::lexicographical_compare(
                    h1.normal_counts_, h1.normal_counts_ + h1.normal_counts_size_,
                    h2.normal_counts_, h2.normal_counts_ + h1.normal_counts_size_
                ))
                    return true;
                else if (std::lexicographical_compare(
                    h2.normal_counts_, h2.normal_counts_ + h2.normal_counts_size_,
                    h1.normal_counts_, h1.normal_counts_ + h1.normal_counts_size_
                ))
                    return false;
                else
                    return std::lexicographical_compare(
                        h1.normal_values_, h1.normal_values_ + h1.normal_values_size_,
                        h2.normal_values_, h2.normal_values_ + h2.normal_values_size_
                    );
                break;
            case HandType::straight:
                return h1.straight_value_ < h1.straight_value_;
                break;
            case HandType::flush:
                return std::lexicographical_compare(h1.flush_values_, h1.flush_values_ + 5, h2.flush_values_, h2.flush_values_ + 5);
                break;
            case HandType::straight_flush:
                return h1.straight_flush_value_ < h2.straight_flush_value_;
                break;
            }
        }
        else
            return false;
    }

    Hand::Hand(Card cards_pocket[2], Card cards_table[5])
    {
        // Sorting

        static Card cards[7];
        std::copy(cards_pocket, cards_pocket + 2, cards);
        std::copy(cards_table, cards_table + 5, cards + 2);
        std::sort(cards, cards + 7, [](Card c1, Card c2) { return c2.value < c1.value; });

        // Normal hand

        static int value_counts[15];
        for (int v = 2; v != 15; ++v) value_counts[v] = 0;
        for (int ci = 0; ci != 7; ++ci) ++value_counts[cards[ci].value];

        int num_cards = 5;
        normal_counts_size_ = 0;
        normal_values_size_ = 0;
        while (true)
        {
            int v_max_caped_value_count;
            int max_caped_value_count = 0;
            for (int v = 14; v != 1; --v)
            {
                if (value_counts[v] == 0) continue;

                if (value_counts[v] >= num_cards)
                {
                    v_max_caped_value_count = v;
                    max_caped_value_count = num_cards;

                    break;
                }
                
                if (value_counts[v] > max_caped_value_count)
                {
                    v_max_caped_value_count = v;
                    max_caped_value_count = value_counts[v];
                }
            }

            if (max_caped_value_count != 1) normal_counts_[normal_counts_size_++] = max_caped_value_count;

            normal_values_[normal_values_size_++] = v_max_caped_value_count;

            if (max_caped_value_count == num_cards) break;

            value_counts[v_max_caped_value_count] = 0;

            num_cards -= max_caped_value_count;
        }

        // Straight

        bool is_straight = false;

        static int straight_card_values[7];
        for (int ci = 0; ci != 7; ++ci) straight_card_values[ci] = cards[ci].value;

        straight_value_ = get_straight_value(straight_card_values, 7);
        if (straight_value_ != 0) is_straight = true;

        // Flush

        bool is_flush = false;

        static int suit_counts[4];
        for (int s = 0; s != 4; ++s) suit_counts[s] = 0;
        for (int ci = 0; ci != 7; ++ci) ++suit_counts[static_cast<int>(cards[ci].suit)];

        int s_flush = 5;
        for (int s = 0; s != 4; ++s)
        {
            if (suit_counts[s] >= 5)
            {
                s_flush = s;
                break;
            }
        }

        if (s_flush != 5)
        {
            is_flush = true;

            for (int ci = 0, i = 0; i != 5; ++ci)
            {
                if (cards[ci].suit == static_cast<Suit>(s_flush))
                    flush_values_[i++] = cards[ci].value;
            }
        }

        // Straight flush

        bool is_straight_flush = false;

        if (is_straight && is_flush)
        {
            static int straight_flush_card_values[7];
            int i = 0;
            for (int ci = 0; ci != 7; ++ci)
            {
                if (cards[ci].suit == static_cast<Suit>(s_flush))
                    straight_flush_card_values[i++] = cards[ci].value;
            }
        
            straight_flush_value_ = get_straight_value(straight_flush_card_values, i);
            if (straight_flush_value_ != 0) is_straight_flush = true;
        }

        // Hand type

        if (is_straight_flush)
            type_ = HandType::straight_flush;
        else if (normal_counts_size_ == 1 && normal_counts_[0] == 4)
            type_ = HandType::four_of_a_kind;
        else if (normal_counts_size_ == 2 && normal_counts_[0] == 3 && normal_counts_[1] == 2)
            type_ = HandType::full_house;
        else if (is_flush)
            type_ = HandType::flush;
        else if (is_straight)
            type_ = HandType::straight;
        else
            type_ = HandType::other;
    }

    int Hand::get_straight_value(int card_values[], int n)
    {
        int i_straight_start = 0;
        int straight_count = 1;
        for (int i = 1; i != n; ++i)
        {
            if (card_values[i] == card_values[i - 1]) continue;

            if (card_values[i] == card_values[i - 1] - 1)
            {
                if (++straight_count == 5) return card_values[i_straight_start];

                if (card_values[i_straight_start] == 5 && straight_count == 4 && card_values[0] == 14) return card_values[i_straight_start];
            }
            else
            {
                i_straight_start = i;
                straight_count = 1;
            }
        }

        return 0;
    }
}

