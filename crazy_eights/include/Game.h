#ifndef GAME_H
#define GAME_H
#include "Player.h"
#include "Card.h"
#include "Deck.h"


class Game {

    private:
        Deck cards;
        Player players[2];
        int current_player;//indicates which turn is now as index of players array
        Player player1;
        Player player2;
        Card last_played;//last played card
        int dead_ends;//indicates number of times when there are no cards in deck and the player can't play any card

    public:
        // must have constructors, destructor, accessor methods, and mutator methods

        Game();

        ~Game(){}

        Deck get_deck();


        bool can_play(Player current_player, Card p_card, Card* p_cards, int p_numb);//checks whether current player have a card in hand to play depending on the top card


        void play_card_menu(Player current_player);

        int get_ends();

        Player* get_players();

        void set_players(Player p_player1, Player p_player2);

        void display() {
            this->players[0].display_player();
            this->players[1].display_player();
            this->last_played.display_card();
        }

        void turn();
    };
#endif // GAME_H
