#include "Hand.h"
#include "Card.h"
#include <iostream>

using namespace std;

Hand::Hand() {
            n_cards = 0;
            cards = new Card[0];
        }

Hand::Hand(Card* p_cards, int p_numb) {
            n_cards = p_numb;
            cards = new Card[n_cards];
            for(int i =0; i< p_numb; i++)
              cards[i] = p_cards[i];
        }

Hand::Hand(const Hand &p_hand) {
            n_cards  = p_hand.n_cards;
            cards = new Card[n_cards];
            for(int i =0; i< n_cards; i++)
              cards[i] = p_hand.cards[i];
        }

Hand::~Hand() {
            delete []cards;
        }

Card* Hand::get_cards()
        {
            return this->cards;
        }

void Hand::set_cards(Card* p_cards, int p_numb) //p_numb is number of cards to store
        {
            this->cards = new Card[p_numb];
            for(int i = 0; i < p_numb; i++)
            {
                this->cards[i] = p_cards[i];
            }
        }

int Hand::get_n_cards() {
            return this->n_cards;
        }

void Hand::set_n_cards(int p_numb) {
            this->n_cards = p_numb;
        }

void Hand::add_card(Card p_card)//adds card to hand
        {
            Card* temp_cards = new Card[this->n_cards+1]; //temp_array to store data to

            for(int i =0; i< n_cards; i++){
                temp_cards[i] = this->cards[i];
            }
            delete [] this->cards;

            temp_cards[this->n_cards] = p_card;

            this->n_cards += 1;
            this->cards = new Card[this->n_cards];
            this->set_cards(temp_cards, this->n_cards);

            delete [] temp_cards;
        }

void Hand::add_card(int p_rank, int p_suit)//adds card to hand
        {
            Card* temp_cards = new Card[this->n_cards+1]; //temp_array to store data to

            for(int i =0; i< n_cards; i++){
                temp_cards[i] = this->cards[i];
            }
            delete [] this->cards;

            temp_cards[this->n_cards] = Card(p_rank, p_suit);

            this->n_cards += 1;
            this->cards = new Card[this->n_cards];
            this->set_cards(temp_cards, this->n_cards);

            delete [] temp_cards;
        }

void Hand::remove_card(Card p_card) {
            Card* temp_cards = new Card[this->n_cards-1]; //temp_array to store data to

            int j = 0; //to avoid going over the temps' array index range
            for(int i =0; i< n_cards; i++){
                if((p_card.get_rank() != this->cards[i].get_rank()) || (p_card.get_suit() != this->cards[i].get_suit()))
                {
                    temp_cards[j] = this->cards[i];
                    j += 1;
                }
            }
            delete [] this->cards;


            this->n_cards -= 1;
            this->cards = new Card[this->n_cards];
            this->set_cards(temp_cards, this->n_cards);

            delete [] temp_cards;
        }

void Hand::remove_card(int p_rank, int p_suit)
        {
            Card* temp_cards = new Card[this->n_cards-1]; //temp_array to store data to

            int j = 0; //to avoid going over the temps' array index range
            for(int i =0; i< n_cards; i++){
                if((p_rank != this->cards[i].get_rank()) || (p_suit != this->cards[i].get_suit()))
                {
                    temp_cards[j] = this->cards[i];
                    j += 1;
                }
            }
            delete [] this->cards;


            this->n_cards -= 1;
            this->cards = new Card[this->n_cards];
            this->set_cards(temp_cards, this->n_cards);

            delete [] temp_cards;
        }

void Hand::display_hand() {
            cout<<"_________________"<<endl;
            cout<<"Number of cards: "<<this->n_cards<<endl;
            for(int i = 0; i < this->n_cards; i++)
                this->cards[i].display_card();
            cout<<"_________________"<<endl;
        }

void Hand::search_by_suit() {
            bool flag = false;
            int suit;
            while(flag != true)
            {

                cout<<"Enter a suit to view (0 1 2 3): "<<endl;
                cin>>suit;

                if(!(suit == 0 || suit == 1 || suit == 2 || suit == 3))
                   cout<<"Only 0 1 2 3 are allowed ones"<<endl;
                else {
                    cout<<"_________________"<<endl;
                    cout<<"Cards with "<<suit<<" suit:"<<endl;
                    flag = true;
                    for(int i =0; i < this->n_cards; i ++)
                    {
                        if(this->cards[i].get_suit() == suit)
                            this->cards[i].display_card();
                    }
                    cout<<"_________________"<<endl;
                }
            }
        }

void Hand::search_by_rank() {
            bool flag = false;
            int suit;
            while(flag != true)
            {

                cout<<"Enter a rank to view (0 1 2 3 4 5 6 7 8 9 10 11 12): "<<endl;
                cin>>suit;

                if(!(suit == 0 || suit == 1 || suit == 2 || suit == 3 || suit == 4 || suit == 5 || suit == 6 || suit == 7
                      || suit == 8 || suit == 9 || suit == 10 || suit == 11 || suit == 12))
                   cout<<"Only 0 1 2 3 4 5 6 7 8 9 10 11 12 are allowed ones"<<endl;
                else {
                    cout<<"_________________"<<endl;
                    cout<<"Cards with "<<suit<<" rank:"<<endl;
                    flag = true;
                    for(int i =0; i < this->n_cards; i ++)
                    {
                        if(this->cards[i].get_rank() == suit)
                            this->cards[i].display_card();
                    }
                    cout<<"_________________"<<endl;
                }
            }
        }
