#include "Player.h"
#include "Hand.h"

Player::Player() {
            name = "No name";
            is_human = true;
        }

Player::Player(string p_name, Hand p_hand, bool p_human): hand(p_hand.get_cards(), p_hand.get_n_cards())
        {
            name = p_name;
            is_human = p_human;
        }

Hand Player::get_hand() {
            return this->hand;
        }

void Player::set_hand(Card* p_cards, int p_numb) {
            this->hand.set_n_cards(p_numb);
            this->hand.set_cards(p_cards, p_numb);

        }

string Player::get_name() {
            return this->name;
        }

void Player::set_name(string p_name) {
            this->name = p_name;
        }

bool Player::get_human() {
            return this->is_human;
        }

void Player::set_human(bool p_human) {
            this->is_human = p_human;
        }

void Player::display_player(){
            cout<<"Player "<<this->get_name()<<" ";
            if(this->is_human)
                cout<<"(human)"<<endl;
            else
                cout<<" (AI)"<<endl;

            this->get_hand().display_hand();
        }

int Player::get_suit_8() {
            //returns suit when 8 is played - it will be the first suit where player has max number of cards
            int max_suit = 0;//suit where player has max number of cards
            int max_suit_numb = 0;//number of players' cards in max suit
            for(int i =0; i < 4; i++)
            {
                int numb = 0;//number of cards in current suit

                for(int j =0; j < this->hand.get_n_cards(); j ++)
                {
                    if(this->hand.get_cards()[j].get_suit() == i)
                        numb += 1;
                }
                if(numb > max_suit_numb)
                {
                    max_suit_numb = numb;
                    max_suit = i;
                }

            }
            return max_suit;
        }

void Player::draw_card(int p_rank, int p_suit) {

            this->hand.add_card(p_rank, p_suit);
        }

void Player::play_card(int p_rank, int p_suit) {
            this->hand.remove_card(p_rank, p_suit);
        }
