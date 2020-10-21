#include "Deck.h"
#include "Card.h"
#include<iostream>
#include<stdlib.h>
#include<time.h>

using namespace std;

Deck::Deck() {

            n_cards = 52;
            int card_number = 0; //index for cards array

            for(int i = 0; i < 4; i ++)
            {
                for(int j = 0; j< 13; j++)
                {
                    cards[card_number] = Card(j, i);
                    card_number += 1;
                }
            }

        }

void Deck::shuffle() {
    srand(time(0));

            for(int i = 0; i <100; i++)
            {
                int n1 = rand()%52; //position of the first card
                int n2 = rand()%52; //position of the second card

                //swapping cards
                Card temp = this->cards[n1];
                this->cards[n1] = this->cards[n2];
                this->cards[n2] = temp;

            }
}

void Deck::display() {

            for(int i = 0; i < 52; i++)
                this->cards[i].display_card();
        }

Card* Deck::get_deck() {

            return this->cards;
        }

void Deck::set_deck(Card* p_cards) {

            for(int i = 0; i < 52; i++)
            {
                this->cards[i] = p_cards[i];
            }
        }

int Deck::get_n_cards() {
            return this->n_cards;
        }

void Deck::set_n_cards(int p_numb) {
            this->n_cards = p_numb;
        }

Card Deck::draw_card(){

            this->set_n_cards(this->get_n_cards()-1);

            return this->cards[52 - this->get_n_cards()-1];
        }
