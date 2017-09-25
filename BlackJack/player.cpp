#include "player.h"




player::player() {
    balance = 20.00;
    comp = 0;
}
player::player(int a) {
    comp = a;
}
void player::setBal(double a) {
    balance = a;
}
void player::gainCard(Card a) {

    hand.push_back(a);
    setPow(a.getP());
}
double player::showBal()const {
    return balance;
}
int player::showPower()const {
    return power;
}
void player::setPow(int a) {
    power += a;
}
void player::resetPow() {
    power = 0;
}
void player::display() {
    if (comp == 0) {

        for (unsigned int i = 0; i < hand.size(); i++) {

            std::cout << hand[i].getN() << " ";

        }
        std::cout << endl;
        std::cout << "Your total is " << showPower() << endl;
    }
    else {
        std::cout << "The Dealer has ";
        for (unsigned int i = 0; i < 1; i++) {

            std::cout << hand[i].getN() << " ";

        }
        std::cout << endl << endl;
        //std::cout << "The dealers total is " << showPower() << std::endl;
    }


}
bool player::showBust()const {
    return bust;
}
void player::setBust(bool a) {
    bust = a;
}
void player::hit() {

}
void player::reset() {
    unsigned int k = hand.size();
    for (unsigned int i = 0; i < k; i++) {

        hand.pop_back();
    }
    power = 0;
}

bool player::checkSplit(player a) {

    bool valid = false;
    string c = a.hand[1].getN().substr(0, 4);
    string b = a.hand[2].getN().substr(0, 4);

    if (c == b) {
        valid = true;
    }

    return valid;
    
}