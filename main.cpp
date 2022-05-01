#include <iostream>
#include <fstream>
#include <string>
#include <unistd.h>
#include <vector>
#include "Player.h"

using namespace std;

void bubbleSort(vector<Player>&vec, int size) {
    for(int i = 0; i < size-1; i++) {
        for(int j = 0; j < size-i-1; j++) {
            if(vec[j] > vec[j+1]) {
                Player temp = vec.at(j);
                vec[j] = vec[j+1];
                vec.at(j+1) = temp;
            }
        }
    }
}

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
        string tempArg;
        switch(opt) {
            case 'i':
                inputName = optarg;
                break;
            case 's':
                tempArg.append(optarg);
                while (optind < argc && argv[optind][0] != '-') {
                    tempArg.append(" ");
                    tempArg.append(argv[optind]);
                    optind++;
                }
                player1Name = tempArg;
                break;
            case 'd':
                tempArg.append(optarg);
                while (optind < argc && argv[optind][0] != '-') {
                    tempArg.append(" ");
                    tempArg.append(argv[optind]);
                    optind++;
                }
                player2Name = tempArg;
                break;
            case 't' :
                tempArg.append(optarg);
                while (optind < argc && argv[optind][0] != '-') {
                    tempArg.append(" ");
                    tempArg.append(argv[optind]);
                    optind++;
                }
                teamName = tempArg;
                break;
            default:
                cerr << "ERROR: incorrect input usage" << endl;
                exit(1);
        }
    }

    // cout << "input name --> " << inputName << endl;
    // cout << "player 1 name --> " << player1Name << endl;
    // cout << "player 2 name --> " << player2Name << endl;
    // cout << "team name --> " << teamName << endl;

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
        // cout << "player1Name ---> " << player1Name << endl;
        // case 2a, print player1's list of teams, sorted by year
        vector<Player> tempVec;
        for (int i = 0; i < (int)allPlayers.size(); i++) {
            if (allPlayers[i].getName() == player1Name) {
                tempVec.push_back(allPlayers[i]);
            }
        }
        bubbleSort(tempVec, (int)tempVec.size());
        for (int i = 0; i < (int)tempVec.size(); i++) {
            cout << tempVec[i] << endl;
        }
    }
    if(player1Name != "empty" && player2Name == "empty" && teamName != "empty") {
        // case 2b, print player1's list with that team only, sorted by year
        vector<Player> tempVec2;
        for (int i = 0; i < (int)allPlayers.size(); i++) {
            if (allPlayers[i].getName() == player1Name && allPlayers[i].getTeam() == teamName) {
                tempVec2.push_back(allPlayers[i]);
            }
        }
        bubbleSort(tempVec2, (int)tempVec2.size());
        for (int i = 0; i < (int)tempVec2.size(); i++) {
            cout << tempVec2[i] << endl;
        }
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