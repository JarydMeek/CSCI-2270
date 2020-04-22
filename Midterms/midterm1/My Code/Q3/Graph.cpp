#include "Graph.hpp"
#include <vector>
#include <queue>
#include <iostream>
#include <queue>


using namespace std;

void Graph::addEdge(string source, string target){
    for(unsigned int i = 0; i < vertices.size(); i++){
        if(vertices[i]->name == source){
            for(unsigned int j = 0; j < vertices.size(); j++){
                if(vertices[j]->name == target && i != j){
                    adjVertex av;
                    av.v = vertices[j];
                    vertices[i]->adj.push_back(av);
                }
            }
        }
    }
}

void Graph::addVertex(string vName){
    bool found = false;
    for(unsigned int i = 0; i < vertices.size(); i++){
        if(vertices[i]->name == vName){
            found = true;
            cout<<vertices[i]->name<<" found."<<endl;
        }
    }
    if(found == false){
        vertex * v = new vertex;
        v->name = vName;
        vertices.push_back(v);
    }
}

void Graph::display(){
    cout<<"vertex"<<":"<<"color"<<endl;
    for(unsigned int i = 0; i < vertices.size(); i++){
        cout<<vertices[i]->name<<":"<<vertices[i]->color<<endl;

    }
}


//TODO
void Graph::color(string source){
    /*First, Find the vertex that matches our start string, and store it to a storage variable*/
    vertex * start;
    for (int x = 0; x < vertices.size(); x++) {
        if (vertices[x] -> name == source) {
            start = vertices[x];
        }
    }
    
    /* Next, Preform a BFS that goes through every vertex in the attached graph and updates the distance*/
    
    //add the things to get the BFS started
    start -> visited = true;
    start -> distance = 0;
    queue <vertex*> queue;
    queue.push(start);

    //Begin the BFS to update the distances for all the vertices in the connected graph.
    vertex * current;
    while (queue.size() != 0) {
        current = queue.front();
        queue.pop();

        for (int i = 0; i < current -> adj.size(); i++) {
            if (current -> adj[i].v -> visited == false) {
                current -> adj[i].v -> distance = current -> distance + 1; //update distance
                queue.push(current -> adj[i].v); //add to queue (for BFS)
            }
        }
    }

    /* Color all the things (and by things I mean vertices :D ) */
    for (int j = 0; j < vertices.size(); j++) {
        if (vertices[j] -> distance == -1) { //The distance wasn't updated (so the vertex also wasn't visited), so must not be a part of the connected graph.
            vertices[j] -> color = "white"; //make it white
        } else {
            if (vertices[j] -> distance % 2 == 0) { 
                vertices[j] -> color = "black"; //if the distance of the vertex is an even number, make it black
            } else {
                vertices[j] -> color = "red"; //otherwise (it's an odd distance) make it red.
            }
        }
    }
}
