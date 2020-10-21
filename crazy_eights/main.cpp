#include <iostream>
#include"Card.h"
#include"Deck.h"
#include "Hand.h"
#include "Player.h"
#include "Game.h"

using namespace std;



void test1();
void test2();
void test3();
void test4();
void test5();
void game();


int main()
{

    //test1();
    //test2();
    //test3();
    //test4();
    //test5();

    game();
}


//checking Deck constructor + shuffle work
void test1(){
    Deck d = Deck();
    d.display();
    d.shuffle();
    cout<<"##################"<<endl;
    cout<<"After shuffle: "<<endl;
    d.display();
}

//checking deck mutator and accessor
void test2() {
    Deck b;
    Deck d;
    d.shuffle();
    d.get_deck()[30].display_card();

    Card* cards = d.get_deck();

    cards[30].display_card();

    //mutator check
    b.get_deck()[30].display_card();
    d.set_deck(b.get_deck());
    d.get_deck()[30].display_card();

}

//Hand add and remove search card test
void test3() {
    Deck d;

    Hand h;

    Card card1 = d.get_deck()[0];
    Card card2 = d.get_deck()[1];

    h.add_card(0, 0);
    h.add_card(card2);
    h.display_hand();

    h.remove_card(0, 0);
    h.remove_card(card2);
    h.display_hand();
}

//Player get_8_suit test
void test4(){

    Card cards[7];
    Deck d;
    d.shuffle();

    for(int i =0; i< 7; i++)
       cards[i] = d.get_deck()[i];

    Hand hand = Hand(cards, 7);

    hand.display_hand();

    Player p = Player("Player1", hand, true);


    p.display_player();
    int suit = p.get_suit_8();
    cout<<"Suit for this player after playing 8 is "<<suit<<endl;

}

//testing adding and playing cards to Player
void test5()
{
    Card cards1[7];
    Deck d;


    for(int i =0; i< 7; i++)
       cards1[i] = d.get_deck()[i];


    Hand hand1 = Hand(cards1, 7);

    Player Player1 = Player("Player1", hand1, true);

    Player1.draw_card(3, 7);

    Player1.get_hand().display_hand();

    Player1.play_card(3, 7);

    Player1.display_player();

}


void game()
{

    Game game = Game();

    while(game.get_ends() < 2)
        game.turn();

    if((game.get_players()[0].get_hand().get_n_cards() == 0) ||
       game.get_players()[0].get_hand().get_n_cards() < game.get_players()[1].get_hand().get_n_cards())
        cout<<"Player "<<game.get_players()[0].get_name()<<" wins!!"<<endl;
    else
        cout<<"Player "<<game.get_players()[1].get_name()<<" wins!!"<<endl;

    cout<<game.get_players()[0].get_name()<<" has "<<game.get_players()[0].get_hand().get_n_cards()<<" card(s)"<<endl;

    cout<<game.get_players()[1].get_name()<<" has "<<game.get_players()[1].get_hand().get_n_cards()<<" card(s)"<<endl;
}


