#include "Card.h"
#include<iostream>

using namespace std;

Card::Card() {
            this->rank = -1;
            this->suit = -1;
            //this->c_rank = '@';
            //this->c_suit = '@';
        }

Card::Card(int p_rank, int p_suit) {
            this->rank = p_rank;
            this->suit = p_suit;
            //this->c_rank = ranks[p_rank];
            //this->c_suit = suits[p_suit];
        }

void Card::display_card()// displaying card
{
    cout<<"Rank "<<this->rank<<" -- "<<"Suit "<<this->suit<<endl;
}

int Card::get_suit()
    {
        return this->suit;
    }


int Card::get_rank() {
            return this->rank;
        }


