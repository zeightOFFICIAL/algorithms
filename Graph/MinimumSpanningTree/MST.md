# Kruskal
Kruskal's algorithm is a greedy algorithm that finds the minimum spanning tree (MST) of a weighted undirected graph. The algorithm starts by sorting all the edges in ascending order of their weights. It then adds the edge with the smallest weight to the MST if it does not create a cycle. It repeats this process until all the vertices are included in the MST.

The algorithm uses a disjoint-set data structure to keep track of which vertices are connected. It starts with each vertex in its own set, and as edges are added to the MST, the sets are merged until all the vertices are in the same set.

Kruskal's algorithm has a time complexity of O(E log E), where E is the number of edges in the graph. This makes it one of the fastest algorithms for finding the MST of a graph, and it is commonly used in practice.

# Prim
Prim's algorithm is a greedy algorithm used to find the minimum spanning tree (MST) of a connected, weighted, undirected graph. The algorithm starts with an arbitrary node in the graph and adds the minimum-weight edge from the node to a new tree. It then considers all the edges that connect the new tree to the remaining nodes and adds the minimum-weight edge. This process is repeated until all the nodes are part of the MST.

The algorithm maintains a set of nodes that are already in the MST and a set of nodes that are not yet in the MST. At each step, the algorithm selects the node with the minimum distance from the MST and adds it to the MST. The distances are updated as new nodes are added to the MST.

The main advantage of Prim's algorithm over Kruskal's algorithm is that it can be implemented more efficiently for dense graphs, i.e., graphs where the number of edges is close to the maximum number of edges possible in the graph. In such graphs, Kruskal's algorithm can take a long time to sort the edges. However, for sparse graphs, Kruskal's algorithm can be more efficient.

Overall, Prim's algorithm has a time complexity of O(E log V), where E is the number of edges and V is the number of nodes in the graph. This makes it a very efficient algorithm for finding the MST of a graph.