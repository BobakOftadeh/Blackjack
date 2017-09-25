#include <vector>
#include <cstdlib>
#include <ctime>
#include "Card.h"
#include "Deck.h"
#include "player.h"
using namespace std;

//void filldeck(vector<Card>& a);

int main() {
    int deckcount = 52;
    string quit = "yes";
    double bet = 0;
    int cardDraw;
    string pass = "h";
    player playerone;
    player playertwo(1);
    Deck mainDeck;
    cout << "Welcome to Blackjack" << endl;
    while (quit != "n" && quit != "N")
    {

        cout << "Your balance: $" << playerone.showBal() << endl;
        cout << "How much will you bet?: $";
        cin >> bet;
        while (cin.fail() || (playerone.showBal() - bet) < 0) {
            cin.clear();
            cin.ignore(2000, '\n');
            cout << "Invaild input please input a number that is in range of your balance." << endl;
            cout << "Your balance: $" << playerone.showBal() << endl;
            cout << "How much will you bet?: $";
            cin >> bet;
        }

        //filldeck(DeckofCards);
        for (int i = 0; i < 2; i++)
        {

            cardDraw = rand() % (deckcount + 1 - 1) + 1;
            playerone.gainCard(mainDeck.DeckofCards[cardDraw]);
            mainDeck.DeckofCards.erase(mainDeck.DeckofCards.begin() + cardDraw);
            --deckcount;

            cardDraw = rand() % deckcount + 1;
            playertwo.gainCard(mainDeck.DeckofCards[cardDraw]);
            mainDeck.DeckofCards.erase(mainDeck.DeckofCards.begin() + cardDraw);
            --deckcount;
        }

        playertwo.display();
        playerone.display();
        
        while (pass != "pass" && pass != "p")
        {
            cout << "Will you hit or stay?";
            cin >> pass;
            if (pass == "h" || pass == "hit" || pass == "Hit" || pass == "H")
            {
                cardDraw = rand() % deckcount + 1;
                playerone.gainCard(mainDeck.DeckofCards[cardDraw]);
                mainDeck.DeckofCards.erase(mainDeck.DeckofCards.begin() + cardDraw);
                --deckcount;
                playerone.display();
                if (playerone.showPower() > 21) {
                    cout << "Bust!" << endl;
                    playerone.setBust(true);
                    break;
                }
            }
            else if (pass == "s" || pass == "stay" || pass == "Stay" || pass == "S") {
                break;
            }

        }

        while (playertwo.showPower() < 17 && playerone.showBust() == false)
        {
            cardDraw = rand() % deckcount + 1;
            playertwo.gainCard(mainDeck.DeckofCards[cardDraw]);
            mainDeck.DeckofCards.erase(mainDeck.DeckofCards.begin() + cardDraw);
            --deckcount;
            playertwo.display();
            if (playertwo.showPower() > 21) {
                playertwo.setBust(true);
            }
            
        }

        if (playerone.showBust() || playerone.showPower() < playertwo.showPower()) {

            cout << "You lose!" << endl;
            playerone.setBal(playerone.showBal() - bet);
        }
        else if (playertwo.showBust() || playerone.showPower() > playertwo.showPower()) {

            cout << "You win!" << endl;
            playerone.setBal(playerone.showBal() + bet);

        }
        else {
            cout << "Push!" << endl;
        }
        cout << "Will you keep playing (Y)es or (N)o?: ";
        cin >> quit;
        while (quit != "N" && quit !="n" && quit !="y" && quit != "Y") {
            cin.clear();
            cin.ignore(2000, '\n');
            cout << "Invaild input, please input (Y)es or (N)o."<< endl <<endl;
            cout << "Will you keep playing (Y)es or (N)o?: ";
            cin >> quit;
        }
        playerone.reset();
        playertwo.reset();

    }
    /* for (unsigned int i = 0; i < mainDeck.DeckofCards.size(); i++)
     {

         mainDeck.DeckofCards[i].display();


     }*/
     //cout << mainDeck.DeckofCards.size();



}

/*void filldeck(vector<Card>& a) {
    Card temp;
    temp.setN("Ace of Hearts");
    temp.setP(1);
    a.push_back(temp);

    temp.setN("Ace of Spades");
    temp.setP(1);
    a.push_back(temp);

    temp.setN("Ace of Clubs");
    temp.setP(1);
    a.push_back(temp);

    temp.setN("Ace of Diamonds");
    temp.setP(1);
    a.push_back(temp);

    temp.setN("Two of Hearts");
    temp.setP(2);
    a.push_back(temp);

    temp.setN("Two of Spades");
    temp.setP(2);
    a.push_back(temp);

    temp.setN("Two of Clubs");
    temp.setP(2);
    a.push_back(temp);

    temp.setN("Two of Diamonds");
    temp.setP(2);
    a.push_back(temp);

    temp.setN("Three of Hearts");
    temp.setP(3);
    a.push_back(temp);

    temp.setN("Three of Spades");
    temp.setP(3);
    a.push_back(temp);

    temp.setN("Three of Clubs");
    temp.setP(3);
    a.push_back(temp);

    temp.setN("Three of Diamonds");
    temp.setP(3);
    a.push_back(temp);

    temp.setN("Four of Hearts");
    temp.setP(4);
    a.push_back(temp);

    temp.setN("Four of Spades");
    temp.setP(4);
    a.push_back(temp);

    temp.setN("Four of Clubs");
    temp.setP(4);
    a.push_back(temp);

    temp.setN("Four of Diamonds");
    temp.setP(4);
    a.push_back(temp);

    temp.setN("Five of Hearts");
    temp.setP(5);
    a.push_back(temp);

    temp.setN("Five of Spades");
    temp.setP(5);
    a.push_back(temp);

    temp.setN("Five of Clubs");
    temp.setP(5);
    a.push_back(temp);

    temp.setN("Five of Diamonds");
    temp.setP(5);
    a.push_back(temp);

    temp.setN("Six of Hearts");
    temp.setP(6);
    a.push_back(temp);

    temp.setN("Six of Spades");
    temp.setP(6);
    a.push_back(temp);

    temp.setN("Six of Clubs");
    temp.setP(6);
    a.push_back(temp);

    temp.setN("Six of Diamonds");
    temp.setP(6);
    a.push_back(temp);

    temp.setN("Seven of Hearts");
    temp.setP(7);
    a.push_back(temp);

    temp.setN("Seven of Spades");
    temp.setP(7);
    a.push_back(temp);

    temp.setN("Seven of Clubs");
    temp.setP(7);
    a.push_back(temp);

    temp.setN("Seven of Diamonds");
    temp.setP(7);
    a.push_back(temp);

    temp.setN("Eight of Hearts");
    temp.setP(8);
    a.push_back(temp);

    temp.setN("Eight of Spades");
    temp.setP(8);
    a.push_back(temp);

    temp.setN("Eight of Clubs");
    temp.setP(8);
    a.push_back(temp);

    temp.setN("Eight of Diamonds");
    temp.setP(8);
    a.push_back(temp);

    temp.setN("Nine of Hearts");
    temp.setP(9);
    a.push_back(temp);

    temp.setN("Nine of Spades");
    temp.setP(9);
    a.push_back(temp);

    temp.setN("Nine of Clubs");
    temp.setP(9);
    a.push_back(temp);

    temp.setN("Nine of Diamonds");
    temp.setP(9);
    a.push_back(temp);

    temp.setN("Ten of Hearts");
    temp.setP(10);
    a.push_back(temp);

    temp.setN("Ten of Spades");
    temp.setP(10);
    a.push_back(temp);

    temp.setN("Ten of Clubs");
    temp.setP(10);
    a.push_back(temp);

    temp.setN("Ten of Diamonds");
    temp.setP(10);
    a.push_back(temp);

    temp.setN("Jack of Hearts");
    temp.setP(10);
    a.push_back(temp);

    temp.setN("Jack of Spades");
    temp.setP(10);
    a.push_back(temp);

    temp.setN("Jack of Clubs");
    temp.setP(10);
    a.push_back(temp);

    temp.setN("Jack of Diamonds");
    temp.setP(10);
    a.push_back(temp);

    temp.setN("Queen of Hearts");
    temp.setP(10);
    a.push_back(temp);

    temp.setN("Queen of Spades");
    temp.setP(10);
    a.push_back(temp);

    temp.setN("Queen of Clubs");
    temp.setP(10);
    a.push_back(temp);

    temp.setN("Queen of Diamonds");
    temp.setP(10);
    a.push_back(temp);

    temp.setN("King of Hearts");
    temp.setP(10);
    a.push_back(temp);

    temp.setN("King of Spades");
    temp.setP(10);
    a.push_back(temp);

    temp.setN("King of Clubs");
    temp.setP(10);
    a.push_back(temp);

    temp.setN("King of Diamonds");
    temp.setP(10);
    a.push_back(temp); */



    /* Card temp("Ace of Hearts",1);
     a.push_back(temp);
     Card temp("Ace of Spades", 1);
     a.push_back(temp);
     Card temp("Ace of Clubs", 1);
     a.push_back(temp);
     Card temp("Ace of Diamonds", 1);
     a.push_back(temp);
     Card temp("Two of Hearts", 2);
     a.push_back(temp);
     Card temp("Two of Spades", 2);
     a.push_back(temp);
     Card temp("Two of Clubs", 2);
     a.push_back(temp);
     Card temp("Two of Diamonds", 2);
     a.push_back(temp);
     Card temp("Three of Hearts", 3);
     a.push_back(temp);
     Card temp("Three of Spades", 3);
     a.push_back(temp);
     Card temp("Three of Clubs", 3);
     a.push_back(temp);
     Card temp("Three of Diamonds", 3);
     a.push_back(temp);
     Card temp("Four of Hearts", 4);
     a.push_back(temp);
     Card temp("Four of Spades", 4);
     a.push_back(temp);
     Card temp("Four of Clubs", 4);
     a.push_back(temp);
     Card temp("Four of Diamonds", 4);
     a.push_back(temp);*/







     //}