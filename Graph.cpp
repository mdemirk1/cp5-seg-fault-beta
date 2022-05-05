#include <vector>
#include <string>
#include "Player.h"
#include <iostream>
#include <list>
using namespace std;

int search(vector<Player> vec, Player p){
    vector<Player>::iterator it;
    it = find(vec.begin(), vec.end(), p);
    if(it != vec.end()) {
        return (it - vec.begin());
	}
    else {
        return -1;
	}
}

void printVector(vector<Player> vec) {
	for(int i = 0; i < (int)vec.size(); i++) {
		cout << vec.at(i) << "-";
	}
	cout << endl;
}

// A utility function to add an edge in an
// undirected graph.
static void addEdge(vector<Player> adj[], int len) {
	for (int i = 0; i < len; i++) {
		for (int j = 0; j < len; j++) {
			if (adj[i].at(0).getName() != adj[j].at(0).getName()) {
				if (adj[i].at(0).getTeam() == adj[j].at(0).getTeam()) {
					if (adj[i].at(0).getYear() == adj[j].at(0).getYear()) {
						adj[i].push_back(adj[j].at(0));
					}
				}
			}
			else {
				if(i != j) {
					adj[i].push_back(adj[j].at(0));
				}
			}
		}
	}
}

// dfs works for disconnected graph, we may have a disconnected graph.
vector<Player> DFS(vector<Player> adj[], int len, Player source, Player target, vector<Player> currentPath, vector<Player> shortestPath) {
	currentPath.push_back(source);
	if(source.equals(target)) {
		return currentPath;
	}
	else {
		for(int i = 0; i < len; i++) {
			if(adj[i][0].equals(source)) {
				for(int j = 1; j < (int)adj[i].size(); j++) {
					if(search(currentPath, adj[i][j]) == -1) {
						if((int)shortestPath.size() == 0 || (int)currentPath.size() < (int)shortestPath.size()) {
							vector<Player> newPath = DFS(adj, len, adj[i][j], target, currentPath, shortestPath);
							if((int)newPath.size() != 0) {
								shortestPath = newPath;
							}
						}
					}
				}
			}
		}
		return shortestPath;
	}
}

// int main()
// {
//     Player p1("Dora Demirkir", "Trabzonspor", "1996");
// 	Player p2("Ahmet Ezdesir", "Galatasaray", "2002"); 
 
//     // The below line may not work on all
//     // compilers.  If it does not work on
//     // your compiler, please replace it with
//     // following
//     // vector<int> *adj = new vector<int>[V];
//     vector<Player> adj[2];
// 	adj[0].push_back(p1);
// 	adj[1].push_back(p2);
//     // Vertex numbers should be from 0 to 4.
// 	addEdge(adj);
// 	int len = *(&adj + 1) - adj;
// 	for (int i = 0; i < len; i++) {
// 		for (int j = 0; j < (int)adj[i].size(); j++) {
// 			cout << adj[i].at(j) << endl;
// 		}
// 	}
//     return 0;
// }
