#include <iostream>
#include <vector>
#include <ctime>

#include "floyd_warshall.h"
#include "limits.h"

using namespace std;

void SPGFloyd(vector<vector<int>> distances_matrix) 
{
    int number_of_vertex = distances_matrix.size();
    int map[number_of_vertex][number_of_vertex], i, j, k;
    clock_t t;
    
    for (i = 0; i < number_of_vertex; i++)
        for (j = 0; j < number_of_vertex; j++) {
                if (i == j)
                    map[i][j] = 0;
                else if (distances_matrix[i][j] == 0)
                    map[i][j] = INT_MAX;
                else
                    map[i][j] = distances_matrix[i][j];
                }
    t = clock();
    for (k = 0; k < number_of_vertex; k++)
        for (i = 0; i < number_of_vertex; i++)
            for (j = 0; j < number_of_vertex; j++)  {
                    if (map[i][j]>(map[i][k]+map[k][j])&&
                        (map[k][j]!=INT_MAX && map[i][k]!=INT_MAX))
                        map[i][j]=map[i][k]+map[k][j];
                }
    t = clock() - t;
    cout<<"3.2 Floyd-Warshall's SPG\n";  
    for (i = 0; i < number_of_vertex; i++)  {
            for (k = 0; k < number_of_vertex; k++)
                cout<<map[i][k]<<", ";
            cout<<endl; 
        }
    cout<<"Time: "<<((float)t)/CLOCKS_PER_SEC<<" seconds"<<endl;
}
