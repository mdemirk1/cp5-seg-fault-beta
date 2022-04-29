#include <iostream>
#include "Player.h"

using namespace std;

Player::Player(string playerName, string teamName, int year) {
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

int Player::getYear() {
    return this->year;
}