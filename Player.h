#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
using namespace std;

class Player {

    public:
        Player(string playerName, string teamName, string year);
        Player();
        string getName();
        string getTeam();
        string getYear();
        friend ostream& operator<<(ostream &out, Player &p);
        bool operator==(const Player &p);
        bool equals(Player &p);
        bool operator<(Player &p);
        bool operator>(Player &p);
        void incrementAppear();
        int getAppear();

    private:
        string playerName;
        string teamName;
        string year;
        int appear;
};

#endif