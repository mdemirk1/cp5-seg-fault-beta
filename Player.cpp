#include <iostream>
#include "Player.h"

using namespace std;

Player::Player(string playerName, string teamName, string year) {
    this->playerName = playerName;
    this->teamName = teamName;
    this->year = year;
}

string Player::getName() {
    return this->playerName;
}

string Player::getTeam() {
    return this->teamName;
}

string Player::getYear() {
    return this->year;
}

ostream& operator<<(ostream &out, Player &p) {
    out << p.getName() << "," << p.getTeam() << "," << p.getYear();
    return out;
}