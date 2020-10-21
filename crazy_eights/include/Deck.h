#ifndef DECK_H
#define DECK_H
#include "Card.h"

class Deck
{
    private:
        Card cards[52];
        int n_cards;  // Number of cards remaining in the deck.  public:

    public:
        // must have constructors, destructor, accessor methods, and mutator methods

        Deck();

        ~Deck(){

        }

        void shuffle(); // 100 times two random cards will be swapped


        void display(); //showing the Deck


        Card* get_deck();


        void set_deck(Card* p_cards);

        int get_n_cards();

        void set_n_cards(int p_numb);

        Card draw_card();//emulates draw of the top card

};

#endif // DECK_H
