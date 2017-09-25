#pragma once
#include <iostream>
#include <string>
using namespace std;

class Card {
    string cardName;
    int power;

public:
    Card();
    Card(string name, int p);
    void display()const;
    void setN(string nam);
    void setP(int P);
    string getN()const;
    int getP()const;

};