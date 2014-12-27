#include <iostream>
#include <algorithm>
#include <vector>
#include "card_deck.hpp"
#include "hand.hpp"
#include "hand_range.hpp"

using namespace Poker;

int main()
{
    HandRange hr_0 = {
    //   A  K  Q  J  T  9  8  7  6  5  4  3  2
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, // A
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, // K
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, // Q
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, // J
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, // T
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, // 9
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, // 8
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, // 7
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, // 6
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, // 5
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, // 4
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, // 3
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}  // 2
    };

    HandRange hr_10 = {
    //   A  K  Q  J  T  9  8  7  6  5  4  3  2
        {1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0}, // A
        {1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0}, // K
        {1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, // Q
        {1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0}, // J
        {0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0}, // T
        {0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0}, // 9
        {0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0}, // 8
        {0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0}, // 7
        {0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0}, // 6
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, // 5
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, // 4
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, // 3
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}  // 2
    };

    HandRange hr_20 = {
    //   A  K  Q  J  T  9  8  7  6  5  4  3  2
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0}, // A
        {1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0}, // K
        {1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0}, // Q
        {1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0}, // J
        {1, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0}, // T
        {1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0}, // 9
        {1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0}, // 8
        {1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0}, // 7
        {0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0}, // 6
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0}, // 5
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, // 4
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, // 3
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}  // 2
    };

    HandRange hr_30 = {
    //   A  K  Q  J  T  9  8  7  6  5  4  3  2
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, // A
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0}, // K
        {1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0}, // Q
        {1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0}, // J
        {1, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0}, // T
        {1, 1, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0}, // 9
        {1, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0}, // 8
        {1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0}, // 7
        {1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0}, // 6
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0}, // 5
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0}, // 4
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, // 3
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}  // 2
    };

    HandRange hr_40 = {
    //   A  K  Q  J  T  9  8  7  6  5  4  3  2
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, // A
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, // K
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0}, // Q
        {1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0}, // J
        {1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0}, // T
        {1, 1, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0}, // 9
        {1, 1, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0}, // 8
        {1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0}, // 7
        {1, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0}, // 6
        {1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0}, // 5
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0}, // 4
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0}, // 3
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}  // 2
    };

    HandRange hr_50 = {
    //   A  K  Q  J  T  9  8  7  6  5  4  3  2
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, // A
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, // K
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, // Q
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0}, // J
        {1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0}, // T
        {1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0}, // 9
        {1, 1, 1, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0}, // 8
        {1, 1, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0}, // 7
        {1, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0}, // 6
        {1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0}, // 5
        {1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0}, // 4
        {1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0}, // 3
        {1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}  // 2
    };

    HandRange hr_60 = {
    //   A  K  Q  J  T  9  8  7  6  5  4  3  2
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, // A
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, // K
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, // Q
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, // J
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0}, // T
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0}, // 9
        {1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0}, // 8
        {1, 1, 1, 1, 1, 0, 0, 1, 0, 0, 0, 0, 0}, // 7
        {1, 1, 1, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0}, // 6
        {1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0}, // 5
        {1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0}, // 4
        {1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0}, // 3
        {1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}  // 2
    };

    HandRange hr_65 = {
    //   A  K  Q  J  T  9  8  7  6  5  4  3  2
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, // A
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, // K
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, // Q
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, // J
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, // T
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0}, // 9
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0}, // 8
        {1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 0, 0, 0}, // 7
        {1, 1, 1, 1, 1, 0, 0, 0, 1, 0, 0, 0, 0}, // 6
        {1, 1, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0}, // 5
        {1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0}, // 4
        {1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0}, // 3
        {1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}  // 2
    };

    HandRange hr_70 = {
    //   A  K  Q  J  T  9  8  7  6  5  4  3  2
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, // A
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, // K
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, // Q
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, // J
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, // T
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0}, // 9
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0}, // 8
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0}, // 7
        {1, 1, 1, 1, 1, 0, 0, 0, 1, 0, 0, 0, 0}, // 6
        {1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 0, 0, 0}, // 5
        {1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0}, // 4
        {1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0}, // 3
        {1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1}  // 2
    };

    HandRange hr_80 = {
    //   A  K  Q  J  T  9  8  7  6  5  4  3  2
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, // A
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, // K
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, // Q
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, // J
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, // T
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, // 9
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, // 8
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0}, // 7
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0}, // 6
        {1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 0, 0}, // 5
        {1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0}, // 4
        {1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 0}, // 3
        {1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1}  // 2
    };

    HandRange hr_90 = {
    //   A  K  Q  J  T  9  8  7  6  5  4  3  2
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, // A
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, // K
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, // Q
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, // J
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, // T
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, // 9
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, // 8
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, // 7
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, // 6
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, // 5
        {1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1}, // 4
        {1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 0}, // 3
        {1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1}  // 2
    };

    HandRange hr_100 = {
    //   A  K  Q  J  T  9  8  7  6  5  4  3  2
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, // A
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, // K
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, // Q
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, // J
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, // T
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, // 9
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, // 8
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, // 7
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, // 6
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, // 5
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, // 4
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, // 3
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}  // 2
    };

    HandRange hr_p = hr_70, hr_o;

    long double small_blind = 15, big_blind = 30;
    long double stack = 10 * small_blind;
    long double rake = 4;

    std::vector<std::pair<Card, Card>> hr_cards_o;
    for (int v1 = 2; v1 != 14; ++v1)
        for (int v2 = v1 + 1; v2 != 15; ++v2)
        {
            hr_cards_o.emplace_back(Card(v1, Suit::h), Card(v2, Suit::h));
            hr_cards_o.emplace_back(Card(v1, Suit::h), Card(v2, Suit::d));
        }

    for (int v = 2; v != 15; ++v)
        hr_cards_o.emplace_back(Card(v, Suit::h), Card(v, Suit::d));

    {
        for (auto p : hr_cards_o)
        {
            CardDeck cd({p.first, p.second});

            Card c_po[2] = {p.first, p.second};
            Card c_pp[2];
            Card c_t[5];

            long double total_loss_p = 0;
            long double num_plays = 0;
            long double avg_loss_p;
            for (int i = 0; i != 1000000; ++i)
            {
                cd.reset();

                c_pp[0] = cd.deal();
                c_pp[1] = cd.deal();

                if (!hr_p(c_pp[0], c_pp[1])) continue;

                c_t[0] = cd.deal();
                c_t[1] = cd.deal();
                c_t[2] = cd.deal();
                c_t[3] = cd.deal();
                c_t[4] = cd.deal();

                Hand h_p(c_pp, c_t), h_o(c_po, c_t);    

                if (h_p < h_o) // Player loses
                    total_loss_p += stack;
                else if (h_o < h_p) // Player wins
                    total_loss_p -= stack - rake;
                else // Tie
                    total_loss_p += rake / 2;

                num_plays += 1;
            }

            avg_loss_p = total_loss_p / num_plays;
            std::cout << "Avg loss for player, when player goes all in and opponent calls with " << card_to_string(c_po[0]) << card_to_string(c_po[1]) << ": " << avg_loss_p << std::endl;
            std::cout << "Avg loss for player, when player goes all in and opponent folds with " << card_to_string(c_po[0]) << card_to_string(c_po[1]) << ": " << -big_blind << std::endl << std::endl;

            if (avg_loss_p > -big_blind) hr_o(c_po[0], c_po[1]) = true;
        }
    }

    {
        CardDeck cd;

        Card c_pp[2];
        Card c_po[2];
        Card c_t[5];

        long double total_loss_p = 0;
        long double num_plays = 0;
        long double avg_loss_p;
        for (int i = 0; i != 10000000; ++i)
        {
            cd.reset();

            c_pp[0] = cd.deal();
            c_pp[1] = cd.deal();

            c_po[0] = cd.deal();
            c_po[1] = cd.deal();

            if (!hr_p(c_pp[0], c_pp[1])) // Player folds, and loses small blind.
                total_loss_p += small_blind;
            else if (!hr_o(c_po[0], c_po[1])) // Player goes all in, opponent folds and player wins big blind.
                total_loss_p -= big_blind;
            else // Player goes all in, opponent calls.
            {
                c_t[0] = cd.deal();
                c_t[1] = cd.deal();
                c_t[2] = cd.deal();
                c_t[3] = cd.deal();
                c_t[4] = cd.deal();

                Hand h_p(c_pp, c_t), h_o(c_po, c_t); 

                if (h_p < h_o) // Player goes all in, opponent calls, player loses, and losses stack.
                    total_loss_p += stack;
                else if (h_o < h_p) // Player goes all in, opponent calls, opponent loses, and player wins stack - rake.
                    total_loss_p -= stack - rake;
                else // Player goes all in, opponent calls, tie, and player loses half a rake.
                    total_loss_p += rake / 2;
            }

            num_plays += 1;
        }
        
        avg_loss_p = total_loss_p / num_plays;
        std::cout << "Average win for player: " << -avg_loss_p << std::endl << std::endl;
    }
}
