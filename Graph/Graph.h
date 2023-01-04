// Graph.h
// Helping class for Graph algorithms.
// Might be removed. If so, use algorihtms directly, without Graph and inherited classes.
// for version 1.32

#pragma once

#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

class Graph {
  typedef std::vector<std::vector<int>> vector;
  typedef std::vector<int> vector1d;
  typedef std::string string;

protected:
  vector AdjacencyMatrix;
  vector DistancesMatrix;
  void ClearGraph();

public:
  explicit Graph();
  explicit Graph(Graph &grph);
  virtual ~Graph();

  void GenerateGraph(int vertices = 5, int edges = 7, int power = 10);
  void CustomGraph(int vertices = 5);
  void LoadGraph(string filename = "test.txt");
  void SaveGraph(string filename = "test.txt");

  void PrintAdjacencyMatrix();
  void PrintDistancesMatrix();
  void PrintEdgesList();

  vector GetAdjacencyMatrix();
  vector GetDistancesMatrix();
  vector GetEdgesList();
};

Graph::Graph() {}

Graph::Graph(Graph &grph) {
  AdjacencyMatrix = grph.GetAdjacencyMatrix();
  DistancesMatrix = grph.GetDistancesMatrix();
}

Graph::~Graph() {}

void Graph::GenerateGraph(int vertices, int edges, int power) {
  ClearGraph();
  AdjacencyMatrix.resize(vertices, vector1d(vertices, 0));
  DistancesMatrix.resize(vertices, vector1d(vertices, 0));
  int eachEdge = 0, summerDistance = 1, src, dst;

  srand((int)time(0));
  while (eachEdge < edges) {
    src = rand() % (AdjacencyMatrix.size());
    dst = rand() % (AdjacencyMatrix.size());
    if ((AdjacencyMatrix[src][dst] != 1) && (src != dst)) {
      AdjacencyMatrix[src][dst] = 1;
      AdjacencyMatrix[dst][src] = 1;
      eachEdge++;
    }
  }
  srand((int)time(0));
  for (int row = 0; row < DistancesMatrix.size(); row++) {
    for (int col = 0; col < DistancesMatrix.size(); col++) {
      summerDistance = rand() % power + 1;
      DistancesMatrix[row][col] = AdjacencyMatrix[row][col] * summerDistance;
      DistancesMatrix[col][row] = AdjacencyMatrix[row][col] * summerDistance;
    }
  }
}

void Graph::LoadGraph(string filename) {
  Graph::ClearGraph();
  int countEdges = 0, eachVertex;
  std::ifstream file;

  file.open(filename);
  if (!file) {
    std::cout << "No such file";
  } else {
    file >> eachVertex;
    AdjacencyMatrix.resize(eachVertex, vector1d(eachVertex, 0));
    DistancesMatrix.resize(eachVertex, vector1d(eachVertex, 0));
    for (int row = 0; row < eachVertex; row++) {
      for (int col = 0; col < eachVertex; col++) {
        file >> DistancesMatrix[row][col];
        AdjacencyMatrix[row][col] = static_cast<bool>(DistancesMatrix[row][col]);
        countEdges += static_cast<bool>(DistancesMatrix[row][col]);
      }
    }
  }
  file.close();
}

void Graph::CustomGraph(int vertices) {
  Graph::ClearGraph();
  AdjacencyMatrix.resize(vertices, vector1d(vertices, 0));
  DistancesMatrix.resize(vertices, vector1d(vertices, 0));
  int countEdge = 0, thisEdge = 0;
  
  for (int row = 0; row < vertices; row++) {
    for (int col = row + 1; col < vertices; col++) {
      std::cout << "Input value of edge " << row << " -> " << col << ":";
      std::cin >> thisEdge;
      if (thisEdge != 0) {
        DistancesMatrix[row][col] = thisEdge;
        DistancesMatrix[col][row] = thisEdge;
        AdjacencyMatrix[row][col] = static_cast<bool>(DistancesMatrix[row][col]);
        AdjacencyMatrix[col][row] = static_cast<bool>(DistancesMatrix[col][row]);
        countEdge++;
      }
    }
  }
}

void Graph::SaveGraph(string filename) {
  std::ofstream file;
  file.open(filename, std::ios::trunc);
  if (!file) {
    std::cout << "No such file";
  } else {
    file << DistancesMatrix.size() << "\n";
    for (int row = 0; row < DistancesMatrix.size(); row++) {
      for (int col = 0; col < DistancesMatrix.size(); col++) {
        file << DistancesMatrix[row][col] << " ";
      }
      file << "\n";
    }
  }
  file.close();
}

void Graph::ClearGraph() {
  DistancesMatrix.clear();
  AdjacencyMatrix.clear();
}

void Graph::PrintAdjacencyMatrix() {
  std::cout << "Adjacency matrix:\n";
  for (int row = 0; row < AdjacencyMatrix.size(); row++) {
    std::cout << "\t";
    for (int col = 0; col < AdjacencyMatrix[row].size(); col++) {
      std::cout << std::setw(3) << std::left << AdjacencyMatrix[row][col];
    }
    std::cout << "\n";
  }
}

void Graph::PrintDistancesMatrix() {
  std::cout << "Distances matrix:\n";
  for (int row = 0; row < DistancesMatrix.size(); row++) {
    std::cout << "\t";
    for (int col = 0; col < DistancesMatrix.size(); col++) {
      std::cout << std::setw(3) << std::left << DistancesMatrix[row][col];
    }
    std::cout << "\n";
  }
}

void Graph::PrintEdgesList() {
  std::cout << "Edges list:\n";
  vector edges_list = GetEdgesList();
  for (int eachEdge = 0; eachEdge < edges_list.size(); eachEdge++) {
    std::cout << "\t";
    std::cout << "I:" << std::left << std::setw(3) << eachEdge << " "
              << std::setw(3) << edges_list[eachEdge][1] << " -  "
              << std::setw(3) << edges_list[eachEdge][2] << " with weight "
              << std::setw(2) << edges_list[eachEdge][0] << "\n";
  }
}

std::vector<std::vector<int>> Graph::GetEdgesList() {
  vector edgesList;
  for (int row = 0; row < DistancesMatrix.size(); row++)
    for (int col = row; col < DistancesMatrix.size(); col++)
      if (DistancesMatrix[row][col] != 0) {
        edgesList.push_back({DistancesMatrix[row][col], row, col});
      }
  return edgesList;
}

std::vector<std::vector<int>> Graph::GetAdjacencyMatrix() {
  return AdjacencyMatrix;
}

std::vector<std::vector<int>> Graph::GetDistancesMatrix() {
  return DistancesMatrix;
}