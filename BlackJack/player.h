#pragma once
#include <iostream>
#include <vector>
#include "Card.h"

class player {

    double balance;
    vector <Card> hand;
    int comp;
    int power = 0;
    bool bust = false;

public:
    player();
    player(int a);
    double showBal()const;
    void setBal(double a);
    void setPow(int a);
    void gainCard(Card a);
    int showPower()const;
    void resetPow();
    void display();
    void hit();
    bool showBust()const;
    void setBust(bool a);
    void reset();
    bool checkSplit(player a);
};