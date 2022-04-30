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
        friend ostream& operator<<(ostream &out, Player &p);

    private:
        string playerName;
        string teamName;
        string year;
};








#endif