#include <iostream>
#include "Player.h"

using namespace std;

Player::Player(string playerName, string teamName, string year) {
    this->playerName = playerName;
    this->teamName = teamName;
    this->year = year;
    this->appear = 0;
}

Player::Player() {
    this->playerName = "empty";
    this->teamName = "empty";
    this->year = "empty";
    this->appear = 0;
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

bool Player::operator==(const Player &p) {
    // search func uses this one
    if (this->playerName == p.playerName && this->teamName == p.teamName && this->year == p.year) {
        return true;
    }
    return false;
}

bool Player::equals(Player &p) {
    if (this->playerName == p.playerName && this->teamName == p.teamName && this->year == p.year) {
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

void Player::incrementAppear() {
    this->appear++;
}

int Player::getAppear() {
    return this->appear;
}
