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

vector<Player> BFS(vector<Player> adj[], int len, Player source, Player target) {
	vector<Player> path;
	path.push_back(source);
	vector<vector<Player>> allPaths;
	allPaths.push_back(path);
	while((int)allPaths.size() != 0) {
		cout << (int)allPaths.size() << endl;
		vector<Player> tempPath = allPaths.at(0);
		allPaths.erase(allPaths.begin());
		Player lastItem = tempPath.back();
		if(lastItem.equals(target)) {
			return tempPath;
		}
		else {
			// add new paths to the allPaths
			for(int i = 0; i < len; i++) {
				// cout << "gird" << endl;
				// cout << adj[i].at(0) << endl;
				// cout << lastItem << endl;
				if(adj[i].at(0).equals(lastItem)) {
					// cout << "gird2" << endl;
					for(int j = 1; j < (int)adj[i].size(); j++) {
						// cout << "inff" << endl;
						if(search(tempPath, adj[i].at(j)) == -1) {
							vector<Player> newPath = tempPath;
							newPath.push_back(adj[i].at(j));
							allPaths.push_back(newPath);
						}
					}
				}
			}
		}
	}
	return path;
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
