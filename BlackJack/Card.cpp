#include "Card.h"

Card::Card() {

}
Card::Card(string name, int p) {
    cardName = name;
    power = p;
}

void Card::display()const {
    cout << cardName<< " ";
    cout << power<< endl;
}


void Card::setN(string nam) {
    cardName = nam;
}
void Card::setP(int P) {
    power = P;
}

string Card::getN()const {
    return cardName;
}
int Card::getP()const {
    return power;
}