#include <vector>
#include <string>
#include "Player.h"
#include <iostream>
#include <list>
using namespace std;

// A utility function to add an edge in an
// undirected graph.
static void addEdge(vector<Player> adj[])
{
	int len = *(&adj + 1) - adj;
	for (int i = 0; i < len; i++) {
		for (int j = 0; j < len; j++) {
			if (adj[i].at(0).getName() != adj[j].at(0).getName()) {
				if (adj[i].at(0).getTeam() == adj[j].at(0).getTeam()) {
					if (adj[i].at(0).getYear() == adj[j].at(0).getYear()) {
						adj[i].push_back(adj[j].at(0));
						// adj[j].push_back(adj[i].at(0));
					}
				}
			}
		}
	}
}

void BFS(int s, int V, vector<Player> adj[])
{
    // Mark all the vertices as not visited
    vector<bool> visited;
    visited.resize(V,false);
 
    // Create a queue for BFS
    list<Player> queue;
 
    // Mark the current node as visited and enqueue it
    visited[s] = true;
	Player p = adj[0].at(0);
    queue.push_back(p);
 
    while(!queue.empty())
    {
        // Dequeue a vertex from queue and print it
        Player p = queue.front();
        cout << p << endl;
        queue.pop_front();
 
        // Get all adjacent vertices of the dequeued
        // vertex s. If a adjacent has not been visited,
        // then mark it visited and enqueue it
        int len2 = *(&adj + 1) - adj;
		for (int i = 0; i < len2; i++) {
			if (adj[i].at(i) == p) {
				for (int j = 0; j < (int)adj[i].size(); i++) {
					queue.push_back(adj[i].at(j));
				}
			}
		}
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
