#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
using namespace std;

class Player {

    public:
        Player(string playerName, string teamName, int year);
        string getName();
        string getTeam();
        int getYear();


    private:
        string playerName;
        string teamName;
        int year;
};








#endif