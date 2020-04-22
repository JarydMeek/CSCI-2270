#include "Graph.hpp"
#include <iostream>
#include <queue>

using namespace std;
//Good
void Graph::addEdge(string v1, string v2) {
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
    vertices[v1Index]->adj.push_back(adj2);
    adjVertex adj1;
    adj1.v = vertices[v1Index];
    vertices[v2Index]->adj.push_back(adj1);
}
//Good
void Graph::addVertex(string name) {
    vertex * temp = new vertex;
    temp -> name = name;
    vertices.push_back(temp);
}
//Good
void Graph::displayEdges() {
    for (int i = 0; i < vertices.size(); i++) {
        cout << vertices[i] -> name << " --> ";
        for (int j = 0; j < vertices[i] -> adj.size(); j++) {
            cout << vertices[i] -> adj[j].v -> name << " ";
        }
        cout << endl;
    }
}

void Graph::breadthFirstTraverse(string sourceVertex) {
    int index = -1;
    for (int j = 0; j < vertices.size(); j++) {
        if (vertices[j] -> name == sourceVertex) {
            index = j;
            break;
        }
    }

    queue<vertex*> q;
    // Enqueue the source vertex

    cout<< "Starting vertex (root): " << sourceVertex << "-> ";
    vertex *n;
    q.push(vertices[index]);
    while(!q.empty()){
        n = q.front();
        q.pop();
        
        // go to all the adjacent vertices of n
        for( int x = 0; x < n->adj.size(); x++ )
        {
            if (n -> adj[x].v -> visited == false && n -> adj[x].v -> name != sourceVertex) {
                n -> adj[x].v -> visited = true;
                q.push(n -> adj[x].v);
                n -> adj[x].v -> distance = n -> distance + 1;
                cout << n->adj[x].v->name <<"("<< n->adj[x].v->distance <<")"<< " ";
            }
        }

    }
}
int Graph::getConnectedComponents() {
    queue<vertex*> q;
    vertex *n;
    q.push(vertices[0]);
    vector<vertex*> queue2;
    bool visitedAll = false;
    int count = 0;
    while (!visitedAll) {
        while(!q.empty()){
            n = q.front();
            string sourceVertex = n -> name;
            bool newplace = true;
            for (int i = 0; i < queue2.size(); i++){
                if (queue2[i] -> name == n -> name){
                    newplace = false;
                }
            }
            if (newplace == true){
                queue2.push_back(n);
            }

            q.pop();
            
            // go to all the adjacent vertices of n
            for( int x = 0; x < n->adj.size(); x++ )
            {
                if (n -> adj[x].v -> visited == false && n -> adj[x].v -> name != sourceVertex) {
                    n -> adj[x].v -> visited = true;
                    q.push(n -> adj[x].v);

                }
            }
        }
        count++;
        if (queue2.size() == vertices.size()) {
            visitedAll = true;
        } else {
            for (int i = 0; i < vertices.size(); i++) {
                bool foundName = false;
                for (int j = 0; j < queue2.size(); j++) {
                    if (vertices[i] -> name == queue2[j] -> name) {
                        foundName = true;
                        break;
                    }
                }
                if (foundName == false) {
                    q.push(vertices[i]);
                    break;
                }
            } 
        }
    }
    return count;
}