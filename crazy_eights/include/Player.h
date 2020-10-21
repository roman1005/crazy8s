#ifndef PLAYER_H
#define PLAYER_H
#include "Hand.h"

class Player {
    private:

        Hand hand;
        string name;
        bool is_human;

    public:
        // must have constructors, destructor, accessor methods, and mutator methods};

        Player();

        Player(string p_name, Hand p_hand, bool p_human);

        ~Player() {
        }

        Hand get_hand();

        void set_hand(Card* p_cards, int p_numb);

        string get_name();

        void set_name(string p_name);

        bool get_human();

        void set_human(bool p_human);

        void display_player();

        int get_suit_8();

        void draw_card(int p_rank, int p_suit);

        void play_card(int p_rank, int p_suit);


};

#endif // PLAYER_H
