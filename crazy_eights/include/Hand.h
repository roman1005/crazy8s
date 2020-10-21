#ifndef HAND_H
#define HAND_H
#include "Card.h"
#include <iostream>

using namespace std;

class Hand {

    private:
        Card* cards;
        int n_cards;  // Number of cards in the hand.
        //string name;

    public:

        Hand();

        Hand(Card* p_cards, int p_numb);

        Hand(const Hand &p_hand);

        ~Hand();

        Card* get_cards();

        void set_cards(Card* p_cards, int p_numb); //p_numb is number of cards to store

        int get_n_cards();

        void set_n_cards(int p_numb);

        void add_card(Card p_card);//adds card to hand

        void add_card(int p_rank, int p_suit);//adds card to hand

        void remove_card(Card p_card);

        void remove_card(int p_rank, int p_suit);

        void display_hand();

        void search_by_suit();

        void search_by_rank();

};

#endif // HAND_H
