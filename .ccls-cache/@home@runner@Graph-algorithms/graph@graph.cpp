#include <iostream>
#include <fstream>
#include <random>
#include <vector>
#include <string>

#include "graph.h"

using std::cout, std::vector, std::string, std::ifstream, std::ofstream, std::ios;

Graph::Graph() { number_of_vertices = 0; number_of_edges = 0; }

Graph::~Graph() {}

void Graph::GenerateGraph(int number_of_vertices, int number_of_edges, int power)
{
    adjacency_matrix.resize(number_of_vertices,vector<int>(number_of_vertices, 0));
    distances_matrix.resize(number_of_vertices,vector<int>(number_of_vertices, 0));
    int k = 0, summer_for_distance = 1, start_point, end_point;
    srand((int)time(0));
    while (k<(number_of_edges))  {
            start_point = rand()%(adjacency_matrix.size());
            end_point = rand()%(adjacency_matrix.size());
            if ((adjacency_matrix[start_point][end_point]!=1) && (start_point!=end_point))  {
                    adjacency_matrix[start_point][end_point]=1;
                    adjacency_matrix[end_point][start_point]=1;
                    k++;
                }
        }
    srand((int)time(0));    
    for (int i = 0; i < distances_matrix.size(); i++)
        for (int j = 0; j < distances_matrix.size(); j++)  {
                summer_for_distance=rand()%power+1;
                distances_matrix[i][j]=adjacency_matrix[i][j]*summer_for_distance;
                distances_matrix[j][i]=adjacency_matrix[i][j]*summer_for_distance;
            }
}

void Graph::LoadGraph(string filename)
{
    int count_edges = 0;
    ifstream file;
    file.open(filename);
	if (!file)
		cout << "No such file.";
	else  {
            file >> number_of_vertices;
            adjacency_matrix.resize(number_of_vertices,vector<int>(number_of_vertices, 0));
            distances_matrix.resize(number_of_vertices,vector<int>(number_of_vertices, 0));
            for (int i = 0; i < number_of_vertices; i++)
                for (int j = 0; j < number_of_vertices; j++) {
                        file >> distances_matrix[i][j];
                        adjacency_matrix[i][j]=static_cast<bool>(distances_matrix[i][j]);
                        count_edges += static_cast<bool>(distances_matrix[i][j]);
                    }
        }
    number_of_edges = count_edges/2;
    file.close();
}

void Graph::SaveGraph(string filename)
{
    ofstream file;
    file.open(filename, ios::trunc);
	if (!file)
		cout << "No such file.";
	else  {
        file << distances_matrix.size() << "\n";
        for (int i = 0; i < distances_matrix.size(); i++) {
            for (int j = 0; j < distances_matrix.size(); j++)
                    file << distances_matrix[i][j] << " ";
                file <<"\n";
            }
        }
    file.close();
}

void Graph::ClearGraph() {
    distances_matrix.clear();
    adjacency_matrix.clear();
    number_of_vertices = 0;
    number_of_edges = 0;
}

void Graph::PrintAdjacencyMatrix()
{
    cout<<"\tAdjacency matrix:\n";
    for (int i = 0; i < adjacency_matrix.size(); i++)  {
            cout<<"\t";
            for (int j = 0; j < adjacency_matrix[i].size(); j++)
                    cout<<adjacency_matrix[i][j]<<", ";
            cout << "\n";
        }
}

void Graph::PrintDistancesMatrix()
{
    cout<<"\tDistances matrix:\n";
    for (int i = 0; i < distances_matrix.size(); i++)    {
            cout<<"\t";
            for (int j = 0; j < distances_matrix.size(); j++)
                cout<<distances_matrix[i][j]<<", ";
            cout<<"\n";
        }
}

void Graph::PrintEdgesList()
{
    vector<vector<int>> edges_list = GetEdgesList();
    for (int i = 0; i < number_of_edges; i++)
            cout << "I:" << i << "  " << edges_list[i][1] << " - " << edges_list[i][2] << " with weight " << edges_list[i][0] << "\n";                
}

vector<vector<int>> Graph::GetEdgesList()
{
    vector<vector<int>> edges_list;
    for (int i = 0; i < number_of_vertices; i++)
        for (int j = i; j < number_of_vertices; j++)
            if (distances_matrix[i][j]!=0)
                edges_list.push_back({distances_matrix[i][j],i,j});
    return edges_list;
}

int Graph::GetNumberVertices() {return number_of_vertices;}
int Graph::GetNumberEdges()    {return number_of_edges;}
vector<vector<int>> Graph::GetAdjacencyMatrix() {return adjacency_matrix;}
vector<vector<int>> Graph::GetDistancesMatrix() {return distances_matrix;}