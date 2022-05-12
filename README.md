# cp5-seg-fault-beta

# Analysis

## Case 1 
We created vector to keep all the players that input file indicates.
For this case we are going through all the players in one loop and print every player.
Since we have N player, with on for loop iteration, our time complexity is **O(N)**. N represents the number of players in the input file. Vector data structure contributes the runtime complexity. 

## Case 2

### *Case 2a*
We push the required player objects to the temporary vector by checking allPlayers vector with a single for loop. After that, if there is no player in the allPlayers vector, we simply return and it prevents an additional for loop that is unnecessary in that case. If there is any player in the tempVec, we sort the tempVec with bubble sort and print that vector with single for loop. Worst case time complexity of bubble sort is **O(N²)**. Overall time complexity for this case is: N + N² + N = **O(N²)**. Our nested for loops for iterating vectors contributes to the time complexity. N represents the number of player objects in the input file.


### *Case 2b*
This case is similar to the case 2a. The only difference is we check if the specified team matches with the specified player's team. Overall this differentiated if statement does not change the worst case time complexity which is **O(N²)**. N represents the number of player objects in the input file.


## Case 3
Firstly, we pushed the players who played for the specified team into an vector called tempPlayers. It costs **O(N)** in terms of complexity. After that, we discriminate the all of the unique players from tempPlayers vector and pushed them into the uniquePlayer vector. While pushing the players we increment the Appear data member of the player to understand who appeared how many times in the vector. Probability of all of the players being unique makes our worst case time complexity: **O(N²)**. After this operation, firstly we bubble sort the unique players alphabetically (bubble sort time complexity is **O(N²)**), than we count sort the players according to how many times each player appeared. Reason why we use count sort is to not change the alphatically bubble sorted players while we are sorting them by their appearence (We used the feature of count sort which is being a stable sorting algorithm). Time complexity of count sort is **O(N)**. Even tough it does not change the overall time complexity, in many cases, it makes our implementation slightly faster. Finally, we use a single for loop to iterate over sorted uniquePlayer vector and print the elements.  Our overall time complexity is: N + N² + N² + N + N = 2N² + 3N = **O(N²)**. The runtime complexity is increased by our nested for loops for iterating vectors. N represents the number of player objects in the input file. 

## Case 4
First of all, we create source and target player objects. We iterate on allPlayers vector to find the source and target parameters. If players found, we assign those object that we created above. If any of the source or target are not found inf the vector, we basically return to prevent the algorithm to create an unnecessary graph object. If source and target are found, we start to create a graph. To decide which of the node have edges between them, we need to check every other node for each node. If the names or teams and years are same for two different nodes, we treat these two nodes as connected (creating an edge). Since we have N nodes and we need to check N-1 nodes for each node, it costs us N * (N - 1) to create a graph. Thats why it costs us **O(N²)** time complexity to create the whole graph. After that, we create two vectors called current path and shortest path in order to keep track of these data. We modified the regular DFS implementation for also finding the shortest path rather than just traversing the graph. This additional operation did not change the normal worst case time complexity of DFS which is **O(V + E)**. After that, we have a single for loop to count unique players in the shortest path, and another single for loop to print the shortest path. Overall worst case time complexity of this algorithm is: V + V² + (V+E) + V + V = **O(V²)**. Creating our graph data structure contributes to the overall time complexity in our algorithm. N represents the number of player objects in the input file. Furthermore, V's represents vertices and E's represents edges. Vertices contain of Player objects which are created according to input file. Edges created if the two players' names are the same, or two players' team and years are the same. 
