#include<iostream>
#include<algorithm>
#include <vector>
#include "Player.h"
using namespace std;

void print(int* arr, int size);
Player getMax(vector<Player> &vec, int size);
void countSort(vector<Player> &vec, int size);


void print(int* arr, int size) {
    for(int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

Player getMax(vector<Player> &vec, int size) {
    Player max = vec[0];
    for(int i = 1; i < size; i++) {
        if(vec[i].getAppear() > max.getAppear()) {
            max = vec[i];
        }
    }
    return max;
}

void countSort(vector<Player> &vec, int size) {
    Player resultArray[size];
    Player max = getMax(vec, size);
    int countArray[max.getAppear()+1]; // create count array (max+1 number of elements)
    for(int i = 0; i <= max.getAppear(); i++) {
        countArray[i] = 0; //initialize count array to all zero
    }
    for(int i = 0; i < size; i++) {
        countArray[vec[i].getAppear()] += 1; //  now we know how many 0's 1's 2's ... (frequency)
        // if we have five 3 in arr, countArray[3] = 5 at the end of this loop 
    }
    for(int i = 1; i <= max.getAppear(); i++) {
        countArray[i] = countArray[i] + countArray[i-1]; // cumulative frequency
    }
    for(int i = size - 1; i >= 0; i--) {
        // looking original array, if i = 5, we look countArray[arr[5]] to get frequency
        // then we put item to index of frequency - 1, then decrement the frequency
        resultArray[countArray[vec[i].getAppear()] - 1] = vec[i];
        countArray[vec[i].getAppear()] -= 1;
    }
    for(int i = 0; i < size; i++) {
        // copy sorted array to original array
        vec[i] = resultArray[i];
    }
}

// Driver code
// int main() {
//     int array[] = {4, 2, 7, 2, 8, 3, 15, 3, 1, 5, 5,};
//     int n = sizeof(array) / sizeof(array[0]);
//     countSort(array, n);
//     print(array, n);
// }