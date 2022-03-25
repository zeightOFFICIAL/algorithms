#include <iostream>
#include <vector>
#include <ctime>

#include "johnson.h"

#define INF 999999

using namespace std;

void SPGJohnson(vector<vector<int>> distances_matrix)
{
    int number_of_vertex = distances_matrix.size();
    int Map[number_of_vertex][number_of_vertex];
    clock_t t;
    
    for (int i = 0; i < number_of_vertex; i++)
        for (int j = 0; j < number_of_vertex; j++) {
            if (i == j)
                Map[i][j] = 0;
            else if (distances_matrix[i][j] == 0)
                Map[i][j] = INF;
            else
                Map[i][j] = distances_matrix[i][j];
            }
    t = clock();
    for (int k = 0; k < number_of_vertex; k++)
      for (int i = 0; i < number_of_vertex; i++)
         for (int j = 0; j < number_of_vertex; j++)
            Map[i][j] = min(Map[i][j], Map[i][k] + Map[k][j]);

    t = clock() - t;
    cout<<"3.3 Johnsons's SPG\n";  
    for (int i = 0; i < number_of_vertex; i++)  {
            for (int k = 0; k < number_of_vertex; k++)
                cout<<Map[i][k]<<", ";
            cout<<endl; 
        }
    cout<<"Time: "<<((float)t)/CLOCKS_PER_SEC<<" seconds"<<endl;
}