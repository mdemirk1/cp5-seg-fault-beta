#include <iostream>
#include <fstream>
#include <string>
#include <unistd.h>
#include <stdlib.h>
#include <vector>
#include "Player.h"

using namespace std;



int main(int argc, char *argv[]) {
    string inputName = " ";
    int opt;
    //int flags = 0;
    //string nsecs;
    //int tfnd = 0;


    while ((opt = getopt(argc, argv, "tdsi:")) != -1) {
        switch (opt) {
        case 's':
            //flags = 1;
            break;
        case 'i':
            inputName = optarg;
            //tfnd = 1;
            break;
        case 'd':
            //code 
            break;
        case 't' :
            //code
            break;
        default:
            cerr << "ERROR: incorrect input usage" << endl;
            exit(1);
        }
    }

    if (inputName == " ") {
        cerr << "ERROR: input file name is mandatory" << endl;
        exit(1);
    }

    cout << "input name --> " << inputName << endl;
    cout << " name --> " << argv[4] << endl;
    cout << "deneme commiti" << endl;
    // denemeler...
    



}