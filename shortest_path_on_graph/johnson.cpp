#include <iostream>
#include <vector>

//delete ................
#include <ctime>
//.......................

#include "johnson.h"

#define INF 999999

using namespace std;

vector<vector<int>> SPGJohnsonTable(vector<vector<int>> distances_matrix)
{
    int number_of_vertex = distances_matrix.size();
    vector<vector<int>> map;
    map.resize(number_of_vertex,vector<int>(number_of_vertex, 0));
    //.............
    clock_t t;
    //.............
    
    for (int i = 0; i < number_of_vertex; i++)
        for (int j = 0; j < number_of_vertex; j++) {
            if (i == j)
                map[i][j] = 0;
            else if (distances_matrix[i][j] == 0)
                map[i][j] = INF;
            else
                map[i][j] = distances_matrix[i][j];
            }
    //.............
    t = clock();
    //.............
    for (int k = 0; k < number_of_vertex; k++)
      for (int i = 0; i < number_of_vertex; i++)
         for (int j = 0; j < number_of_vertex; j++)
            map[i][j] = min(map[i][j], map[i][k] + map[k][j]);
    //.............
    t = clock() - t;
    //.............
    cout<<"Time: "<<((float)t)/CLOCKS_PER_SEC<<" seconds"<<endl;
    return map;
}

void SPGJohnsonTablePrint(vector<vector<int>> distances_matrix)
{
    int number_of_vertices = distances_matrix.size();
    vector<vector<int>> SPG_johnson_table;
    SPG_johnson_table = SPGJohnsonTable(distances_matrix);
    
    for (int j = 0; j < number_of_vertices; j++) {
        for (int l = 0; l < number_of_vertices; l++)
             cout<<SPG_johnson_table[j][l]<<", ";
        cout<<"\n"; 
        }
}