#include "Game.h"
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

Game::Game(): cards(){

            cards = Deck();

            cards.shuffle();

            srand(time(0));

            Card comp_cards[7];//initial cards of computer

            Card pl_cards[7];//initial cards of player

            dead_ends = 0;

            for(int i =0; i<7; i++)
            {
                comp_cards[i] = cards.draw_card();
            }

            for(int i =0; i<7; i++)
            {
                pl_cards[i] = cards.draw_card();
            }

            Hand comp_hand = Hand(comp_cards, 7);//initial hand of computer
            Hand pl_hand = Hand(pl_cards, 7);//initial hand of player

            string pl_name;//name of player

            cout<<"Enter your name: ";
            cin>>pl_name;
            cout<<endl;

            cout<<"Hello, "<<pl_name<<endl;

            Player p_player1 = Player(pl_name, pl_hand, true);

            Player p_player2 = Player("Bob", comp_hand, false);

            last_played = cards.draw_card();

            players[0].set_hand(p_player1.get_hand().get_cards(), p_player1.get_hand().get_n_cards());
            players[1].set_hand(p_player2.get_hand().get_cards(),  p_player2.get_hand().get_n_cards());

            players[0].set_name(p_player1.get_name());
            players[1].set_name(p_player2.get_name());

            players[0].set_human(p_player1.get_human());
            players[1].set_human(p_player2.get_human());

            srand(time(0));
            current_player = rand() % 2;//randomle assign right of the first turn

            cout<<"The game has started"<<endl;

            cout<<"The right of the first turn has "<<players[current_player].get_name();
            if(players[current_player].get_human())
                cout<<"(human)"<<endl;
            else
                cout<<" (AI)"<<endl;
        }

int Game::get_ends() {
    return this->dead_ends;
}

Deck Game::get_deck() {
            return this->cards;
        }

bool Game::can_play(Player current_player, Card p_card, Card* p_cards, int p_numb)//checks whether current player have a card in hand to play depending on the top card
        {
            for(int i = 0; i < p_numb; i++)
            {
                if(p_cards[i].get_rank() == p_card.get_rank())
                {
                    if(!current_player.get_human())
                    {
                        Card pl_card = Card(p_cards[i].get_rank(), p_cards[i].get_suit());
                        players[this->current_player].play_card(p_cards[i].get_rank(), p_cards[i].get_suit());
                        cout<<"Computer plays card"<<endl;
                        pl_card.display_card();
                        this->last_played = pl_card;
                        dead_ends = 0;

                        if(p_cards[i].get_rank() == 6)//if card's rank is 8 - make comp choose new suit
                        {
                            int new_suit = current_player.get_suit_8();
                            this->last_played = Card(6, new_suit);
                            cout<<"Computer sets new suit: new suit is "<<new_suit<<endl;
                        }
                        this->current_player = (this->current_player + 1) % 2;

                    }

                    return true;
                }

                if(p_cards[i].get_suit() == p_card.get_suit())
                {
                    if(!current_player.get_human())
                    {
                        Card pl_card = Card(p_cards[i].get_rank(), p_cards[i].get_suit());
                        players[this->current_player].play_card(p_cards[i].get_rank(), p_cards[i].get_suit());
                        if(players[this->current_player].get_hand().get_n_cards() == 0)
                            dead_ends = 2;
                        else
                            dead_ends = 0;

                        cout<<"Computer plays card"<<endl;
                        pl_card.display_card();
                        this->last_played = pl_card;

                        if(p_cards[i].get_rank() == 6)//if card's rank is 8 - make comp choose new suit
                        {
                            int new_suit = current_player.get_suit_8();
                            this->last_played = Card(6, new_suit);
                            cout<<"Computer sets new suit: new suit is "<<new_suit<<endl;
                        }
                        this->current_player = (this->current_player + 1) % 2;

                    }


                    return true;
                }
            }
            return false;
        }

void Game::play_card_menu(Player current_player)
        {
            bool flag = false;//indicates whether player played the card or no
            bool flag1 = false;//indicates whether rank input was correct
            bool flag2 = false;//indicates whether suit input was correct
            int suit;//suit of card to be played
            int rrank;//rank of card to be played

            while(!flag)
            {

            flag1 = false;
            flag2 = false;

            while(!flag1) {

                cout<<"Enter a rank of card (0 1 2 3 4 5 6 7 8 9 10 11 12): "<<endl;
                cin>>rrank;

                if(!(rrank == 0 || rrank == 1 || rrank == 2 || rrank == 3 || rrank == 4 || rrank == 5 || rrank == 6 || rrank == 7
                      || rrank == 8 || rrank == 9 || rrank == 10 || rrank == 11 || rrank == 12))
                   cout<<"Only 0 1 2 3 4 5 6 7 8 9 10 11 12 are allowed ones"<<endl;
                else
                    flag1 = 1;
            }

            while(flag2 != true)
            {

                cout<<"Enter a suit of card (0 1 2 3): "<<endl;
                cin>>suit;

                if(!(suit == 0 || suit == 1 || suit == 2 || suit == 3))
                   cout<<"Only 0 1 2 3 are allowed ones"<<endl;
                else
                    flag2 = true;
            }
            int numb = current_player.get_hand().get_n_cards();//number of cards in players' hand
            for(int i = 0; i< numb; i++) {
                Card current_card = current_player.get_hand().get_cards()[i];
                if(current_card.get_rank() == rrank && (current_card.get_rank() == this->last_played.get_rank() ||
                                                        current_card.get_suit() == this->last_played.get_suit()))
                {
                    if(current_player.get_hand().get_cards()[i].get_suit() == suit) {
                        Card card = Card(rrank, suit);
                        flag = true;
                        cout<<"You played card: "<<endl;
                        card.display_card();
                        players[this->current_player].play_card(card.get_rank(), card.get_suit());

                        if(players[this->current_player].get_hand().get_n_cards() == 0)
                            dead_ends = 2;

                        this->last_played = card;


                        if(card.get_rank() == 6)//if card's rank is 8 prompt to choose the new suit
                        {
                            flag2 = false;
                            int suit;
                            while(flag2 != true)
                            {

                                cout<<"Enter a suit of card (0 1 2 3): "<<endl;
                                cin>>suit;

                                if(!(suit == 0 || suit == 1 || suit == 2 || suit == 3))
                                    cout<<"Only 0 1 2 3 are allowed ones"<<endl;
                                else {
                                    flag2 = true;
                                    cout<<"You've set new suit: "<<suit<<endl;
                                    Card temp_card = Card(6, suit);
                                    this->last_played = temp_card;
                                }
                            }
                        }

                    }
                }

            }
            if(!flag)
                cout<<"You don have such card in your hand, or you can't play it. Try again, please"<<endl;
            }

        }

Player* Game::get_players() {
    return this->players;
}

void Game::set_players(Player p_player1, Player p_player2) {

            this->players[0].set_hand(p_player1.get_hand().get_cards(), p_player1.get_hand().get_n_cards());
            this->players[1].set_hand(p_player1.get_hand().get_cards(),  p_player1.get_hand().get_n_cards());

            this->players[0].set_name(p_player1.get_name());
            this->players[1].set_name(p_player2.get_name());
        }


void Game::turn() {
            Player current_player = this->players[this->current_player];
            //If current player is user
                //###
                //message him, show top card
                //@@@
                //check if he has rank or card same as top card - if he has - message him, options will be:
                //show cards by rank(1), by suit(2), play card(3), show cards(4)
                //else options will be
                //rank(1), by suit(2), draw card(3), show cards(4)
                //when he played card:
                        //message successful operation, pass turn to computer
                        //computer turn emulation: computer draws, computer draws again, computer plays
                        //go to ###
                //else message him and show him his cards, prompt to draw, options will be:
                    //show cards by rank(1), by suit(2), draw card(3)

                //if he draws card
                    //show drawn card
                    //go to @@@

            cout<<"<--------------->"<<endl;
            cout<<"Top card is:"<<endl;
            this->last_played.display_card();
            cout<<"<--------------->"<<endl;

            cout<<"__________________________________"<<endl;
            cout<<"=================================="<<endl;

            if(current_player.get_human())
            {
                cout<<"Now it's your turn, "<<current_player.get_name()<<" (human)"<<endl;


                    bool flag = false;//checks whether user inputted correct option
                    bool played_card = false;//is false until user plays a card
                    int option;
                    while(played_card != true)//user should see this options while he or she won't play a card
                    {

                        bool can_play = this->can_play(current_player, this->last_played, current_player.get_hand().get_cards(), current_player.get_hand().get_n_cards());//check if he has rank or card same as top card


                        if(can_play)
                            cout<<"You have a card(s) to play"<<endl;
                        else {
                            cout<<"You don't have a card to play - need to draw a card"<<endl;

                            if(this->cards.get_n_cards() == 0)
                            {
                                if(dead_ends == 0) {
                                    cout<<"There are no cards in deck - so passing turn to Bob"<<endl;
                                    this->current_player = (this->current_player + 1) % 2;
                                    dead_ends += 1;
                                    break;
                                }
                                else {
                                    dead_ends = 2;
                                    break;
                                }
                            }
                        }



                        cout<<"Choose one of the options"<<endl;
                        cout<<"(1) - view cards of certain rank"<<endl;
                        cout<<"(2) - view cards of a certain suit"<<endl;
                        cout<<"(3) - view all of your cards"<<endl;

                        if(can_play)
                            cout<<"(4) - play a card"<<endl;
                        else
                            cout<<"(4) - draw a card"<<endl;

                        int option;
                        flag = false;

                        while(flag != true)
                        {

                            cout<<"Enter a option 1 2 3 4 : "<<endl;
                            cin>>option;

                            if(!(option == 1 || option == 2 || option == 3 || option == 4))
                                cout<<"Only 1 2 3 4 are allowed options"<<endl;
                            else {
                                flag = true;
                            }


                        if(option == 1)
                        {
                            current_player.get_hand().search_by_rank();
                            cout<<"<--------------->"<<endl;
                            cout<<"Top card is:"<<endl;
                            this->last_played.display_card();
                            cout<<"<--------------->"<<endl;
                        }

                        if(option == 2) {
                            current_player.get_hand().search_by_suit();
                            cout<<"<--------------->"<<endl;
                            cout<<"Top card is:"<<endl;
                            this->last_played.display_card();
                            cout<<"<--------------->"<<endl;
                        }

                        if(option == 3) {
                            current_player.get_hand().display_hand();
                            cout<<"<--------------->"<<endl;
                            cout<<"Top card is:"<<endl;
                            this->last_played.display_card();
                            cout<<"<--------------->"<<endl;
                        }

                        if(option == 4)
                        {
                            if(can_play) {
                                dead_ends = 0;
                                this->play_card_menu(current_player);
                                played_card = true;
                                this->current_player = (this->current_player + 1) % 2;

                            }
                            else {

                                Card drawn_card = this->cards.draw_card();

                                this->players[this->current_player].draw_card(drawn_card.get_rank(), drawn_card.get_suit());
                                cout<<"You've drawn card: "<<endl;
                                drawn_card.display_card();
                                this->players[this->current_player].get_hand().display_hand();
                                current_player.draw_card(drawn_card.get_rank(), drawn_card.get_suit());

                                cout<<"<--------------->"<<endl;
                                cout<<"Top card is:"<<endl;
                                this->last_played.display_card();
                                cout<<"<--------------->"<<endl;
                            }

                        }
                        }
                    }
            }
            //if it is computer
                //check if he has rank or card same as top card, if he has - play the first one which is encountered, pass turn to user
                //else draw card and message user
            else {

                cout<<"Now it's "<<this->players[this->current_player].get_name()<<" turn"<<endl;
                cout<<this->players[this->current_player].get_name()<<" is thinking..."<<endl;
                usleep(5000000);
                if(!this->can_play(current_player, this->last_played, current_player.get_hand().get_cards(), current_player.get_hand().get_n_cards()))
                {
                    if(this->cards.get_n_cards() != 0)
                    {
                        cout<<this->players[this->current_player].get_name()<<" draws card"<<endl;
                        Card card = this->cards.draw_card();
                        this->players[this->current_player].draw_card(card.get_rank(), card.get_suit());
                        current_player.draw_card(card.get_rank(), card.get_suit());
                    }
                    else
                    {
                        if(dead_ends == 0) {
                            cout<<"Bob can't play - passing to you"<<endl;
                            this->current_player = (this->current_player + 1) % 2;
                        }

                        else {
                            dead_ends = 2;
                        }
                    }
               }

            }
        }

