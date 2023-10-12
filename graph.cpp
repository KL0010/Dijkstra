#include <iostream>
#include <cassert>
#include <string>
#include <array>
#include <stdlib.h>

using namespace std;

class Graph{
public:
    int index;
    int Edge1;
    int Edge2;
    int Edge3;
    int Edge4;
    int Edge5;
    int Edge6;
    int Edge7;
    int Edge8;
    int distance_edge1;
    int distance_edge2;
    int distance_edge3;
    int distance_edge4;
    int distance_edge5;
    int distance_edge6;
    int distance_edge7;
    int distance_edge8;
    int visited = -1;

    Graph(){ // default constructor
        index = -1;
        Edge1 = -1;
        Edge2 = -1;
        Edge3 = -1;
        Edge4 = -1;
        Edge5 = -1;
        Edge6 = -1;
        Edge7 = -1;
        Edge8 = -1;
        distance_edge1 = -1;
        distance_edge2 = -1;
        distance_edge3 = -1;
        distance_edge4 = -1;
        distance_edge5 = -1;
        distance_edge6 = -1;
        distance_edge7 = -1;
        distance_edge8 = -1;
        visited = -1;
        };
};
