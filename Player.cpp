#include <iostream>
#include "Player.h"

using namespace std;


string Player::getName() {
    return this->playerName;
}

string Player::getTeam() {
    return this->teamName;
}

int Player::getYear() {
    return this->year;
}