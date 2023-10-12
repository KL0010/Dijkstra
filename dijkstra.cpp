#include<iostream>
#include<stdio.h>
#include <graphics.h>
#include <string>
#include <array>
#include <list>
#include "enums.cpp"
#include "graph.cpp"



using namespace std;

void diplay_Graph(Graph g[MAX_NUMBER][MAX_NUMBER]) // function displays graph
{
    int x = 10, y = 60; // Set x,y default values.
    char number[4];
    char values[4];

    for(int i = 0; i < MAX_NUMBER; ++i){
        x = 200; y += 80;
        for(int j = 0; j < MAX_NUMBER; ++j){
            ostringstream strs;
            ostringstream sides1;
            ostringstream sides2;
            ostringstream sides3;
            strs << g[i][j].index;
            string sd = strs.str();
            strcpy(number, sd.data());
            sides1<< HORIZONTAL;
            string stringing = sides1.str();
            setcolor(LIGHTGRAY);
            setfillstyle(SOLID_FILL,LIGHTGRAY);setbkcolor(LIGHTGRAY);

            if(j != MAX_NUMBER-1 && i != MAX_NUMBER-1){
                setbkcolor(BLACK);
                line(x+15, y, x+135, y);
                strcpy(values, stringing.data());
                outtextxy(x+80,y-5,values);
                line(x+15, y, x+135, y+80);
                sides2 << DIAGONAL;
                stringing = sides2.str();
                strcpy(values, stringing.data());
                outtextxy(x+70,y+30,values);
                line(x, y+65, x, y);
                sides3 << VERTICLE;
                stringing = sides3.str();
                strcpy(values, stringing.data());
                outtextxy(x-5,y+35,values);
            }
            if(i > 0 && j < MAX_NUMBER-1){
                setbkcolor(BLACK);
                line(x+15, y, x+135, y-80);
            }
            if(j == MAX_NUMBER-1 && i != MAX_NUMBER-1){
                setbkcolor(BLACK);
                line(x, y+65, x, y);
                sides3 << VERTICLE;
                stringing = sides3.str();
                strcpy(values, stringing.data());
                outtextxy(x,y+35,values);
            }
            if(i == MAX_NUMBER-1 && j != MAX_NUMBER-1){
                setbkcolor(BLACK);
                line(x+15, y, x+135, y);
                sides3 << VERTICLE;
                stringing = sides3.str();
                strcpy(values, stringing.data());
                outtextxy(x+78,y-5,values);
            }
            if(g[i][j].visited == 0){
                setfillstyle(SOLID_FILL,LIGHTGREEN);setbkcolor(LIGHTGREEN);
            }
            setbkcolor(LIGHTGRAY);
            circle(x,y,15);
            floodfill(x+1,y+1,LIGHTGRAY);
            setcolor(BLACK);
            outtextxy(x-5,y-7,number);
            x += 150;
        }
    }
}

void get_total_vertices(Graph graph[MAX_NUMBER][MAX_NUMBER]){ // funtion couNts the number of egdes for the grid size
    int counting = 0;
    for(int i = 0; i < MAX_NUMBER; i++){
        for(int j = 0; j < MAX_NUMBER; j++){
            if(graph[i][j].Edge1 != -1){ counting++; }
            if(graph[i][j].Edge2 != -1){ counting++; }
            if(graph[i][j].Edge3 != -1){ counting++; }
            if(graph[i][j].Edge4 != -1){ counting++; }
            if(graph[i][j].Edge5 != -1){ counting++; }
            if(graph[i][j].Edge6 != -1){ counting++; }
            if(graph[i][j].Edge7 != -1){ counting++; }
            if(graph[i][j].Edge8 != -1){ counting++; }
        }
    }
    cout << "Number of Egdes: " << counting << " active edges for a " << MAX_NUMBER << "x" << MAX_NUMBER << endl;
}

void printing(Graph g[MAX_NUMBER][MAX_NUMBER]){ //function prints statistics to each vertice
    for(int i = 0; i < MAX_NUMBER; i++){
        for(int j = 0; j < MAX_NUMBER; j++){
            cout << "index: " << g[i][j].index << ", eg1: " << g[i][j].Edge1 << ", distance: " << g[i][j].distance_edge1 << ", eg2: " << g[i][j].Edge2 << ", distance: " << g[i][j].distance_edge2 << endl;
            cout << "eg3: " << g[i][j].Edge3 << ", distance: " << g[i][j].distance_edge3 << ", eg4: " << g[i][j].Edge4 << ", distance: " << g[i][j].distance_edge4 <<endl;
            cout << "eg4: " << g[i][j].Edge5 << ", distance: " << g[i][j].distance_edge5 << ", eg4: " << g[i][j].Edge6 << ", distance: " << g[i][j].distance_edge6 <<endl;
            cout << "eg7: " << g[i][j].Edge7 << ", distance: " << g[i][j].distance_edge7 << ", eg8: " << g[i][j].Edge8 << ", distance: " << g[i][j].distance_edge8 <<endl;
            cout << endl;
        }
    }
}

//function below creates the dynamic grid. Currently the application only accepts grids of equal size.
//This makes the application dynamic and can displayed any length in grid size.
void get_neighbors(Graph graph[MAX_NUMBER][MAX_NUMBER]){ //function sets the edges to the vertices

    for(int i = 0; i < MAX_NUMBER; i++){
        for(int j = 0; j < MAX_NUMBER; j++){
            if(i == 0 && j == 0){ //left top corner
                graph[i][j].Edge1 = graph[i][j+1].index; j-1; //move forward one, y axis.
                graph[i][j].Edge2 = graph[i+1][j+1].index; i-1;j-1; // diagonal bottom right x,y
                graph[i][j].Edge3 = graph[i+1][j].index;i-1; // doen one, x axis
                graph[i][j].distance_edge1 = HORIZONTAL; // weight for edge horizontal
                graph[i][j].distance_edge2 = DIAGONAL; // weight for edge diagonal
                graph[i][j].distance_edge3 = VERTICLE; // weight for verticle
            }
            else if(i == 0 && j == MAX_NUMBER-1){ //right top corner
                graph[i][j].Edge4 = graph[i][j-1].index;j+1; //move back one, y axis.
                graph[i][j].Edge8 = graph[i+1][j-1].index;i-1;j+1; // diagonal bottm left x,y
                graph[i][j].Edge6 = graph[i+1][j].index;i-1;  // down one, x axis
                graph[i][j].distance_edge4 = HORIZONTAL; // weight for edge horizontal
                graph[i][j].distance_edge8 = DIAGONAL; // weight for edge diagonal
                graph[i][j].distance_edge6 = VERTICLE; // weight for verticle
            }
            else if(i == MAX_NUMBER-1 && j == 0){ //left bottom corner
                graph[i][j].Edge1 = graph[i][j+1].index;j-1; //move forward one, y axis.
                graph[i][j].Edge2 = graph[i-1][j+1].index;i+1;j-1; // diagonal top right x,y
                graph[i][j].Edge3 = graph[i-1][j].index;i+1; // move up one, x axis
                graph[i][j].distance_edge1 = HORIZONTAL; // weight for edge horizontal
                graph[i][j].distance_edge2 = DIAGONAL; // weight for edge diagonal
                graph[i][j].distance_edge3 = VERTICLE; // weight for verticle
            }
            else if(i == MAX_NUMBER-1 && j == MAX_NUMBER-1){ // bottm right corner
                graph[i][j].Edge1 = graph[i][j-1].index;j+1; // back one y axis
                graph[i][j].Edge2 = graph[i-1][j-1].index;i+1;j+1; // diagonal top left x,y
                graph[i][j].Edge3 = graph[i-1][j].index;i+1;  // move up one, x axis
                graph[i][j].distance_edge1 = HORIZONTAL; // weight for edge horizontal
                graph[i][j].distance_edge2 = DIAGONAL; // weight for edge diagonal
                graph[i][j].distance_edge3 = VERTICLE; // weight for verticle
            }

            else if(i == 0 && j < MAX_NUMBER-1){ //top edges
                graph[i][j].Edge1 = graph[i][j+1].index;j-1; // move forward one, y axis
                graph[i][j].Edge2 = graph[i+1][j+1].index;i-1;j-1; // diagonal bottom right x,y
                graph[i][j].Edge3 = graph[i+1][j].index;i-1; // move down one, x axis
                graph[i][j].Edge4 = graph[i][j-1].index;j+1; // move left one, y axis
                graph[i][j].Edge5 = graph[i+1][j-1].index;i+1;j-1; // // diagonal bottom left x,y
                graph[i][j].distance_edge1 = HORIZONTAL; // weight for edge horizontal
                graph[i][j].distance_edge2 = DIAGONAL; // weight for edge diagonal
                graph[i][j].distance_edge3 = VERTICLE; // weight for edge verticle
                graph[i][j].distance_edge4 = HORIZONTAL;   // weight for edge horizontal
                graph[i][j].distance_edge5 = DIAGONAL; // weight for edge verticle
            }
            else if(i == MAX_NUMBER-1 && j < MAX_NUMBER-1){ //bottom edges
                graph[i][j].Edge1 = graph[i][j+1].index;j-1; // move forward one, y axis
                graph[i][j].Edge5 = graph[i-1][j+1].index;i+1;j-1; // diagonal top right x,y
                graph[i][j].Edge6 = graph[i-1][j].index;i+1; //move up one, x axis
                graph[i][j].Edge4 = graph[i][j-1].index;j+1; // move back one, y axis
                graph[i][j].Edge5 = graph[i-1][j-1].index;i+1;j+1; // diagonal top left x,y
                graph[i][j].distance_edge1 = HORIZONTAL; // weight for edge horizontal
                graph[i][j].distance_edge5 = DIAGONAL; // weight for edge diagonal
                graph[i][j].distance_edge6 = VERTICLE; // weight for verticle
                graph[i][j].distance_edge4 = HORIZONTAL; // weight for edge horizontal
                graph[i][j].distance_edge7 = DIAGONAL; // weight for edge diagonal
            }
            else if(i > 0 && i < MAX_NUMBER-1 && j == 0){ //left side edges
                graph[i][j].Edge1 = graph[i][j+1].index;j-1; //right one y axis
                graph[i][j].Edge2 = graph[i+1][j+1].index;i-1;j-1; // diagonal bottom left x,y
                graph[i][j].Edge3 = graph[i+1][j].index;i-1; // down one x axis
                graph[i][j].Edge5 = graph[i-1][j+1].index;i+1;j-1; // diagonal bottom left x,y
                graph[i][j].Edge6 = graph[i-1][j].index;i+1; // up one x axis
                graph[i][j].distance_edge1 = HORIZONTAL; // weight for edge horizontal
                graph[i][j].distance_edge2 = DIAGONAL; // weight for edge diagonal
                graph[i][j].distance_edge3 = VERTICLE; // weight for verticle
                graph[i][j].distance_edge5 = DIAGONAL; // weight for edge diagonal
                graph[i][j].distance_edge6 = VERTICLE;// weight for verticle
            }
            else if(i > 0 && i < MAX_NUMBER-1 && j == MAX_NUMBER-1){ //right side edges
                graph[i][j].Edge1 = graph[i][j-1].index;j+1; //left one y axis
                graph[i][j].Edge2 = graph[i+1][j-1].index;i-1;j+1; // diagonal bottom left x,y
                graph[i][j].Edge3 = graph[i+1][j].index;i-1;  // down one x axis
                graph[i][j].Edge4 = graph[i-1][j-1].index;i+1;j+1; // diagonal topleft x,y
                graph[i][j].Edge5 = graph[i-1][j].index;i+1; // up one x axis
                graph[i][j].distance_edge1 = HORIZONTAL; // weight for edge horizontal
                graph[i][j].distance_edge2 = DIAGONAL; // weight for edge diagonal
                graph[i][j].distance_edge3 = VERTICLE; // weight for verticle
                graph[i][j].distance_edge4 = DIAGONAL; // weight for edge diagonal
                graph[i][j].distance_edge5 = VERTICLE; // weight for verticle
            }
            else if (i > 0 && i < MAX_NUMBER-1 && j > 0 && j < MAX_NUMBER-1){ //everything inbetween
                graph[i][j].Edge1 = graph[i][j+1].index;j-1; //right one y axis
                graph[i][j].Edge2 = graph[i+1][j+1].index;i-1;j-1; //diagonal down right x,y
                graph[i][j].Edge3 = graph[i+1][j].index;i-1; //down one x axis
                graph[i][j].Edge4 = graph[i][j-1].index;j+1; // back one y axis
                graph[i][j].Edge5 = graph[i-1][j+1].index;i+1;j-1; //diagonal up right x,y
                graph[i][j].Edge6 = graph[i-1][j].index;i+1; // up one x axis
                graph[i][j].Edge7 = graph[i-1][j-1].index;i+1,j+1; //diagonal top left x,y
                graph[i][j].Edge8 = graph[i+1][j-1].index;i+1;j-1; //diagonal bottom left x,y
                graph[i][j].distance_edge1 = HORIZONTAL; // weight for edge horizontal
                graph[i][j].distance_edge2 = DIAGONAL; // weight for edge diagonal
                graph[i][j].distance_edge3 = VERTICLE; // weight for edge horizontal
                graph[i][j].distance_edge4 = HORIZONTAL;// weight for edge horizontal
                graph[i][j].distance_edge5 = DIAGONAL; // weight for edge diagonal
                graph[i][j].distance_edge6 = VERTICLE; // weight for edge horizontal
                graph[i][j].distance_edge7 = DIAGONAL; // weight for edge diagonal
                graph[i][j].distance_edge8 = DIAGONAL; // weight for edge diagonal
            }
        }
    }
}

// The two functions below was inspired by https://www.geeksforgeeks.org/dijkstras-shortest-path-algorithm-greedy-algo-7/
int minimum_distance(int distance[], bool visited[]) // Function to find minimum distance
{
    int minimum = INT_MAX, index;
    for(int i = 0; i < MAX_NUMBER*MAX_NUMBER; i++){
        if(visited[i] == false && distance[i] <= minimum){
            minimum = distance[i];
            index = i;
        }
    }
    return index;
}

void Dijkstra(int graph[MAX_NUMBER*MAX_NUMBER][MAX_NUMBER*MAX_NUMBER],int start){ // Function to find neighbors
    int distance[MAX_NUMBER*MAX_NUMBER]; // array to store and calculate the minimum distance for each vertice to source
    bool visited[MAX_NUMBER*MAX_NUMBER];// boolean array to store vertices visited
    for(int i = 0; i < MAX_NUMBER*MAX_NUMBER; i++){
        distance[i] = INT_MAX; //record distance as maximum distance for each vertice
        visited[i] = false; // record each verticle visited as false
    }
    distance[start] = 0;   // Start vertice distance is set to 0
    for(int i = 0; i <MAX_NUMBER*MAX_NUMBER; i++){
        int minimum = minimum_distance(distance,visited); //get minimum distance to vertice from start vertice
        visited[minimum] = true; // set vertice visited to true
        for(int i = 0; i <MAX_NUMBER*MAX_NUMBER; i++){
            if(!visited[i] && graph[minimum][i] && distance[minimum] != INT_MAX && // if visited and current vertice and min distance not equal to max int
               graph[minimum][i] + distance[minimum] < distance[i]) // and current vertice and min distance is less than distance
                distance[i] = graph[minimum][i] + distance[minimum]; // set distance as current vertice
        }
    }
    cout << "Vertices\t\tDistance from: " << distance[start] << endl;
    int counting = 0;
    for(int i = 0; i <MAX_NUMBER*MAX_NUMBER; i++){
        cout << counting <<"\t\t\t" << distance[i] << endl;
        counting++;
    }
}

// function below inserts the distance of each vertice to the current vertice in the for loop.
// It does this by looping through the graph array and uses a counter for the neighbors array and inserts to the correct postion
// of the neighbor by the value of the edge.
void insert_into_array(Graph g[MAX_NUMBER][MAX_NUMBER], int n[MAX_NUMBER*MAX_NUMBER][MAX_NUMBER*MAX_NUMBER]){
    int counting =0;
    for(int i = 0; i < MAX_NUMBER; i++){
        for(int j = 0; j < MAX_NUMBER; j++){
            if(g[i][j].Edge1 != -1){
                n[counting][g[i][j].Edge1] = g[i][j].distance_edge1; //insert into n array the distance by usng the counting and the value of
            }                                                        //the edge: n[counting][g[i][j].edge] = g[i][j].whatever matching distance edge
            if(g[i][j].Edge2 != -1){
                n[counting][g[i][j].Edge2] = g[i][j].distance_edge2;
            }
            if(g[i][j].Edge3 != -1){
                n[counting][g[i][j].Edge3] = g[i][j].distance_edge3;
            }
            if(g[i][j].Edge4 != -1){
                n[counting][g[i][j].Edge4] = g[i][j].distance_edge4;
            }
            if(g[i][j].Edge5 != -1){
                n[counting][g[i][j].Edge5] = g[i][j].distance_edge5;
            }
            if(g[i][j].Edge6 != -1){
                n[counting][g[i][j].Edge6] = g[i][j].distance_edge6;
            }
            if(g[i][j].Edge7 != -1){
                n[counting][g[i][j].Edge7] = g[i][j].distance_edge7;
            }
            if(g[i][j].Edge8 != -1){
                n[counting][g[i][j].Edge8] = g[i][j].distance_edge8;
            }
            counting++;
        }
    }
}

void assign_index(Graph g[MAX_NUMBER][MAX_NUMBER]){ //function assigns the index number to each vertice
    int position = 0;
    for(int i = 0; i < MAX_NUMBER; i++){
        for(int j = 0; j < MAX_NUMBER; j++){
            g[i][j].index = position;
            position++;
        }
    }
}

int main()
{
    Graph graph[MAX_NUMBER][MAX_NUMBER]; // construct default graph
    assign_index(graph); // assign index number of each vertice
    get_neighbors(graph); // assign neighbors and the edges
    int neighbors[MAX_NUMBER*MAX_NUMBER][MAX_NUMBER*MAX_NUMBER] = {}; //construct default neighbors array for Dijkstra algorithm
    insert_into_array(graph,neighbors); // insert the edges for each vertice into the neighbors array using the gragh array
    Dijkstra(neighbors,STARTING_VERTICE); // calculate distance using Dijkstra algorithm

    int gd=DETECT,gm; //begin graphics.h
    initwindow(SCREENSIZE_X, SCREENSIZE_Y); //set size of screen
    diplay_Graph(graph); // display graph
    getch();
    closegraph();
    return 0;
}
