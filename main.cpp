#include <iostream>
#include <fstream>
#include <string>
#include <unistd.h>
#include <vector>
#include "Player.h"
#include "CountingSort.cpp"
#include "Graph.cpp"
using namespace std;



void bubbleSortAlpha(vector<Player>&vec, int size) {
    for(int i = 0; i < size-1; i++) {
        for(int j = 0; j < size-i-1; j++) {
            if(vec[j].getName() < vec[j+1].getName()) {
                Player temp = vec.at(j);
                vec[j] = vec[j+1];
                vec.at(j+1) = temp;
            }
        }
    }
}

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
            case 'i': // input filename
                inputName = optarg;
                break;
            case 's': // player1 name
                tempArg.append(optarg);
                while (optind < argc && argv[optind][0] != '-') {
                    tempArg.append(" ");
                    tempArg.append(argv[optind]);
                    optind++;
                }
                player1Name = tempArg;
                break;
            case 'd': // player 2 name
                tempArg.append(optarg);
                while (optind < argc && argv[optind][0] != '-') {
                    tempArg.append(" ");
                    tempArg.append(argv[optind]);
                    optind++;
                }
                player2Name = tempArg;
                break;
            case 't' : // team name
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
    // case 2a done
    // formatting done.
    if(player1Name != "empty" && player2Name == "empty" && teamName == "empty") {
        // case 2a, print player1's list of teams, sorted by year
        vector<Player> tempVec;
        for (int i = 0; i < (int)allPlayers.size(); i++) {
            if (allPlayers[i].getName() == player1Name) {
                tempVec.push_back(allPlayers[i]);
            }
        }
        if ((int)tempVec.size() == 0) {
            cout << player1Name << " does not appear in the input file" << endl;
            return 1;
        }
        bubbleSort(tempVec, (int)tempVec.size());
        for (int i = 0; i < (int)tempVec.size(); i++) {
            cout << player1Name << " played for the " << tempVec[i].getYear() << " " << tempVec[i].getTeam() << endl;
        }
    }
    // case 2b done
    // formatting done.
    // players never played for specified team case handled.
    if(player1Name != "empty" && player2Name == "empty" && teamName != "empty") {
        // case 2b, print player1's list with that team only, sorted by year
        vector<Player> tempVec2;
        for (int i = 0; i < (int)allPlayers.size(); i++) {
            if (allPlayers[i].getName() == player1Name && allPlayers[i].getTeam() == teamName) {
                tempVec2.push_back(allPlayers[i]);
            }
        }
        if (tempVec2.size() == 0) {
            cout << player1Name << " has never played for the " << teamName << endl;
            return 0;
        }
        bubbleSort(tempVec2, (int)tempVec2.size());
        for (int i = 0; i < (int)tempVec2.size(); i++) {
            cout << player1Name << " played for the " << tempVec2[i].getYear() << " " << tempVec2[i].getTeam() << endl;
        }
    }
    
    if(teamName != "empty" && player1Name == "empty") {
        // case 3, print all the players played for that team
        vector <Player> tempPlayer;
        vector <Player> uniquePlayer;

        for (int i = 0; i < (int)allPlayers.size(); i++) {
            if (allPlayers[i].getTeam() == teamName) {
                tempPlayer.push_back(allPlayers[i]);
            }
        }
        if ((int)tempPlayer.size() == 0) {
            cout << teamName << " does not appear in the input file" << endl;
            return 1;
        }
        for (int i = 0; i < (int)tempPlayer.size(); i++) {
            int flag = 0;
            for (int j = 0; j < (int)uniquePlayer.size(); j++) {
                if (tempPlayer[i].getName() == uniquePlayer[j].getName()) {
                    flag = 1;
                    uniquePlayer[j].incrementAppear();
                    break;
                }
            }
            if (flag == 0) {
                tempPlayer[i].incrementAppear();
                uniquePlayer.push_back(tempPlayer[i]);
            }
        }
        bubbleSortAlpha(uniquePlayer, (int)uniquePlayer.size());
        countSort(uniquePlayer, (int)uniquePlayer.size());
        
        for (int i = (int)uniquePlayer.size() - 1; i >= 0; i--) {
            cout << uniquePlayer[i].getName() << " played " <<  uniquePlayer[i].getAppear() << " years for the " << teamName << endl;
        }
    }
    if(teamName == "empty" && player2Name != "empty" && player1Name != "empty") {
        // case 4a, print the shortest teammate path, may include any team
        int len = (int)allPlayers.size();
        Player source;
        Player target;
        vector<Player> adj[len];
        for (int i = 0; i < len; i++) {
            adj[i].push_back(allPlayers.at(i));
            if(allPlayers.at(i).getName() == player1Name) {
                source = allPlayers.at(i);
            }
            if(allPlayers.at(i).getName() == player2Name) {
                target = allPlayers.at(i);
            }
        }
        addEdge(adj, len);
        vector<Player> currentPath;
        vector<Player> shortestPath;
        shortestPath = DFS(adj, len, source, target, currentPath, shortestPath);
        //cout << "shortest path" << endl;
        if ((int)shortestPath.size() == 0) {
            cout << "No teammate path exists between " << player1Name << " and " << player2Name << endl;
            return 1; 
        }
        for(int i = 0; i < (int)shortestPath.size(); i++) {
            cout << shortestPath.at(i) << " --> ";
        }
        cout << endl;
    }
    if(teamName != "empty" && player2Name != "empty" && player1Name != "empty") {
        // case 4b, print the shortest teammate path, look for specific team
        int len = (int)allPlayers.size();
        Player source;
        Player target;
        vector<Player> adj[len];
        for (int i = 0; i < len; i++) {
            adj[i].push_back(allPlayers.at(i));
            if(allPlayers.at(i).getName() == player1Name && allPlayers.at(i).getTeam() == teamName) {
                source = allPlayers.at(i);
            }
            if(allPlayers.at(i).getName() == player2Name && allPlayers.at(i).getTeam() == teamName) {
                target = allPlayers.at(i);
            }
        }
        if(source.getName() == "empty") {
            cout << "No teammate path exists between " << player1Name << " and " << player2Name << endl;
            return 1;
        }
        if(target.getName() == "empty") {
            cout << "No teammate path exists between " << player1Name << " and " << player2Name << endl;
            return 1;
        }
        addEdge(adj, len);
        vector<Player> currentPath;
        vector<Player> shortestPath;
        shortestPath = DFSTeam(adj, len, source, target, currentPath, shortestPath, teamName);
        //cout << "shortest path" << endl;
        for(int i = 0; i < (int)shortestPath.size(); i++) {
            cout << shortestPath.at(i) << " --> ";
        }
        cout << endl;
    }
}

// int main() {
//     Player p1("Dora Demirkir", "Trabzonspor", "1996");
//     Player p2("Dora Demirkir", "Trabzonspor", "1998");
// 	   Player p3("Dora Demirkir", "Galatasaray", "2019");
//     Player p3("Dora Demirkir", "Trabzonspor", "1997");
//     Player p4("Misal Kelleci", "Galatasaray", "2019");
//     Player p5("Ayberk Aykut", "Galatasaray", "2019");
//     Player p6("Ayberk Aykut", "Fenerbahce", "2018");
//     Player p7("Baris Turgay", "Fenerbahce", "2018");
//	   int len = 7;
//     vector<Player> adj[len];
//     adj[0].push_back(p1);
// 	   adj[1].push_back(p2);
//     adj[2].push_back(p3);
//     adj[3].push_back(p4);
//     adj[4].push_back(p5);
//     adj[5].push_back(p6);
//     adj[6].push_back(p7);
//	   addEdge(adj, len);
//     vector<Player> currentPath;
//     vector<Player> shortestPath;
//     shortestPath = DFS(adj, len, p3, p6, currentPath, shortestPath);
// 	for (int i = 0; i < len; i++) {
// 		for (int j = 0; j < (int)adj[i].size(); j++) {
// 			cout << adj[i].at(j).getName() << " " << adj[i].at(j).getYear() << " --> ";
// 		}
//         cout << endl;
// 	}
//     cout << "shortest path" << endl;
//     for(int i = 0; i < (int)shortestPath.size(); i++) {
//         cout << shortestPath.at(i) << " --> ";
//     }
//     cout << endl;
//     return 0;
// }