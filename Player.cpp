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

bool Player::operator==( Player &p) {
    if (this->playerName == p.teamName && this->teamName == p.teamName && this->year == p.year) {
        return true;
    }
    return false;
}

bool Player::operator>(Player &p) {
    if (this->getYear() > p.getYear()) {
        return true;
    }
    return false;
}

bool Player::operator<(Player &p) {
    if (this->getYear() < p.getYear()) {
        return true;
    }
    return false;
}
