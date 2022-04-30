#include <iostream>
#include <fstream>
#include <string>
#include <unistd.h>
#include <stdlib.h>
#include <vector>
#include "Player.h"

using namespace std;

vector<string> splitLine(string line) {
    vector<string> vec;
    int start = 0;
    string del = ",";
    int end = (line).find(del);
    while (end != -1) {
        vec.push_back((line).substr(start, end - start));
        start = end + del.size();
        end = (line).find(del, start);
    }
    vec.push_back((line).substr(start, end - start));
    return vec;
}

vector<Player> allPlayers;

int main(int argc, char *argv[]) {
    string inputName = "empty";
    string player1Name = "empty";
    string player2Name = "empty";
    string teamName = "empty";
    int opt;


    while ((opt = getopt(argc, argv, ":t:d:s:i:")) != -1) {
        switch (opt) {
        case 's':
            player1Name = optarg; // burasi -s Mike Lewis yazinca sadece Mike'i aliyor...
            break;
        case 'i':
            inputName = optarg;
            break;
        case 'd':
            player2Name = optarg; 
            break;
        case 't' :
            teamName = optarg;
            break;
        default:
            cerr << "ERROR: incorrect input usage" << endl;
            exit(1);
        }
    }


    if (inputName == "empty") {
        // case 0a
        cerr << "ERROR: input file name is mandatory" << endl;
        exit(1);
    }
    if(player2Name != "empty" && player1Name == "empty") {
        // case 0b
        cerr << "ERROR: player2 provided, player1 should also be provided" << endl;
        exit(1);
    }

    // put all the players to the vector
    fstream inputFile;
    inputFile.open(inputName, ios::in);
    if (inputFile.is_open()) {
        string tp;
        while(getline(inputFile, tp)) {
            vector<string> playerParts = splitLine(tp);
            allPlayers.push_back(Player(playerParts[0], playerParts[1], playerParts[2]));
        }
        inputFile.close();
    }
    else {
        cerr << "ERROR: file can not be opened" << endl;
        exit(1);    
    }

    if(inputName != "empty" && player1Name == "empty" && player2Name == "empty" && teamName == "empty") {
        // case 1, print the data in the input file
        for(int i = 0; i < (int)allPlayers.size(); i++) {
            cout << allPlayers[i] << endl;
        }
    }
    //case 2a, beta version
    if(player1Name != "empty" && player2Name == "empty" && teamName == "empty") {
        
        cout << "player1Name ---> " << player1Name << endl;
        
        // case 2a, print player1's list of teams, sorted by year
        for (int i = 0; i < (int)allPlayers.size(); i++) {
            if (allPlayers[i].getName() == player1Name) {
                cout << player1Name << " played for the " << allPlayers[i].getYear() << " " 
                << allPlayers[i].getTeam() << endl;
            }
        }
    }
    if(player1Name != "empty" && player2Name == "empty" && teamName != "empty") {
        // case 2b, print player1's list with that team only, sorted by year
    }
    if(teamName != "empty" && player1Name == "empty") {
        // case 3, print all the players played for that team
    }
    if(teamName == "empty" && player2Name != "empty" && player1Name != "empty") {
        // case 4a, print the shortest teammate path, may include any team
    }
    if(teamName != "empty" && player2Name != "empty" && player1Name != "empty") {
        // case 4b, print the shortest teammate path, look for specific team
    }
}