# Graph algorithms
Comparison of minimal spanning tree and shortest path algorithms

* Version 1.03

### main.cpp
### graph.cpp
### dijkstra.cpp
### floyd_warshall.cpp
### johnson.cpp
### prim.cpp
### kruskal.cpp

---

## Test results

| No. of vertices, no. of edges (n) | Dijkstra (s) | Floyd-Warshall (s) | Johnson (s) |
| :---:      | :---:    | :---:    | :---:    |
| 10, 25     | 0.000014 | 0.000005 | 0.000002 | 
| 100, 300   | 0.005641 | 0.001973 | 0.001855 | 
| 200, 900   | 0.037381 | 0.011839 | 0.008906 | 
| 500, 2600  | 0.404049 | 0.138268 | 0.109359 | 
| 1000, 5000 | 3.408931 | 1.265471 | 0.951216 | 