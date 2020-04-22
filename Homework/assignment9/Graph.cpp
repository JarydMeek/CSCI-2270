#include "Graph.hpp"
#include <iostream>
#include <stack>

using namespace std;

    void Graph::addEdge(string v1, string v2, int num){
        int v1Index = -1;
        int v2Index = -1;

        for (int i = 0; i < vertices.size(); i++) {
            if (vertices[i] -> name == v1) {
                v1Index = i;
                break;
            }
        }
        for (int j = 0; j < vertices.size(); j++) {
            if (vertices[j] -> name == v2) {
                v2Index = j;
                break;
            }
        }
        adjVertex adj2;
        adj2.v = vertices[v2Index];
        adj2.weight = num;
        vertices[v1Index]->adj.push_back(adj2);
        adjVertex adj1;
        adj1.v = vertices[v1Index];
        adj1.weight = num;
        vertices[v2Index]->adj.push_back(adj1);
    }

    void Graph::addVertex(string name){
        vertex * temp = new vertex;
        temp -> name = name;
        vertices.push_back(temp);
    }

    void Graph::displayEdges(){
        for (int i = 0; i < vertices.size(); i++) {
            cout << vertices[i] -> name << " --> ";
            for (int j = 0; j < vertices[i] -> adj.size(); j++) {
                cout << vertices[i] -> adj[j].v -> name << " ";
            }
            cout << endl;
        }
    }

    void DFTraversal(vertex *n){
        n->visited = true;
        cout << n->name << " -> ";
        stack<vertex*> stack;

        stack.push(n);

        for(int x = 0; x < n->adj.size(); x++ )
        {
            if (n -> adj[x].v -> visited == false) {
                DFTraversal(n->adj[x].v);
            }
        }
    }

    void Graph::depthFirstTraversal(string sourceVertex){
        vertex * start;
        for (int x = 0; x < vertices.size(); x++) {
            if (vertices[x] -> name == sourceVertex) {
                start = vertices[x];
            }
        }

        DFTraversal(start);
        cout << "DONE";
        
    }
void Graph::dijkstraTraverse(string sourceVertex){
        vertex * start;
        for (int i = 0; i < vertices.size(); i++) {
            if (vertices[i] -> name == sourceVertex){
                start = vertices[i];
            }
        }

        start->visited = true;
        start->distance = 0;
        vector<vertex*> solvedList;
        solvedList.push_back(start);

        bool allSolved = false;

        while(!allSolved){
            int minDist = 999999;
            vertex *solvedV = nullptr;
            allSolved = true;
            // iterate across list of solved vertices
            for(int i = 0; i<solvedList.size(); i++){
                vertex *s = solvedList[i];
                // now iterate s's adj list
                for(int j = 0; j<s->adj.size(); j++){
                    if(!s->adj[j].v->visited){
                        // calculate the distance from vStart
                        int dist = s->distance + s->adj[j].weight;
                        // check if the distance is less than 
                        // smallest distance thus far
                        if(dist<minDist){
                            solvedV = s->adj[j].v;
                            minDist = dist;
                        }
                        allSolved = false;
                    }
                }
            }

            if(!allSolved){
                // Update the new vertex shorest path
                solvedV->distance = minDist;
                // Mark vertex as solved
                solvedV->visited = true;

                // Append the solved vertex to "solved list"
                solvedList.push_back(solvedV);
            }
        }
    }

    void Graph::shortestPath(string start, string end){
        vertex * vStart;
        for (int i = 0; i < vertices.size(); i++) {
            if (vertices[i] -> name == start){
                vStart = vertices[i];
            }
        }

        vertex * vEnd;
        for (int i = 0; i < vertices.size(); i++) {
            if (vertices[i] -> name == end){
                vEnd = vertices[i];
            }
        }

        dijkstraTraverse(start);

        vertex * current = vEnd;
        vertex * previous;
        vector<vertex*> storage;

        while (previous != vStart) {
            storage.push_back(current);
            previous = current;
            current = current -> pred;

        }

        for (int i = storage.size(); i > 0; i--) {
            cout << storage[i-1] -> name << " -> ";
        }
        cout << "DONE [" << vEnd -> distance  << "]" << endl;
    }