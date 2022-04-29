#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
using namespace std;

class Player {

    public:
        Player(string playerName, string teamName, string year);
        string getName();
        string getTeam();
        string getYear();


    private:
        string playerName;
        string teamName;
        string year;
};








#endif