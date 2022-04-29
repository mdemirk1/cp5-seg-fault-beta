#include <iostream>
#include <fstream>
#include <string>
#include <unistd.h>
#include <stdlib.h>
#include <vector>
#include "Player.h"

using namespace std;



int main(int argc, char *argv[]) {
    string inputName = "empty";
    string player1Name = "empty";
    string player2Name = "empty";
    string teamName = "empty";
    int opt;
    //int flags = 0;
    //string nsecs;
    //int tfnd = 0;


    while ((opt = getopt(argc, argv, ":t:d:s:i:")) != -1) {
        switch (opt) {
        case 's':
            player1Name = optarg;
            //flags = 1;
            break;
        case 'i':
            inputName = optarg;
            //tfnd = 1;
            break;
        case 'd':
            //code
            player2Name = optarg; 
            break;
        case 't' :
            //code
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

    cout << "input name --> " << inputName << endl;
    cout << "player 1 name --> " << player1Name << endl;
    cout << "player 2 name --> " << player2Name << endl;
    cout << "team name --> " << teamName << endl;
    



}