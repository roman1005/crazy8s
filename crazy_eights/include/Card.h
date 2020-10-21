#ifndef CARD_H
#define CARD_H


class Card {

    private:
        int rank;  // Should be in the range 0-12. (0 represents 2, 1 represents 3, ..., 12 - king, 13 - ace)
        int suit;  // Should be in the range 0-3 - each represents unique suit

    public:

        // must have constructors, destructor, accessor methods, and mutator methods

        Card();

        Card(int p_rank, int p_suit);

        ~Card()
        {

        }

        int get_rank();

        int get_suit();

        void display_card();// displaying card


};

#endif // CARD_H
