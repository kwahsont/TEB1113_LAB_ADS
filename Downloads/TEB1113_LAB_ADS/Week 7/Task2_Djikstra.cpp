// i made two djikstra implementations for learning purposes. one uses adjacency list and the other uses adjacency matrix. both are in c++17. the first one is more efficient and uses priority queue, while the second one is more straightforward and uses a simple array to keep track of distances.

#include <iostream>
#include <string>
#include <iomanip>
#define INF 1e9                     

using namespace std;

struct Vertex {             // represents an edge in the adjacency list
    string dest;            // dest and weight of the edge
    int weight;       
    Vertex* next = NULL;    // set default to NULL
};

void insertEdge(Vertex*& head, string dest, int weight) {       // adding an edge to a vertex's adjacency list
    Vertex* newVertex = new Vertex();       // create a new vertex for the edge
    newVertex->dest = dest;                 // fill in the destination and weight
    newVertex->weight = weight;
    newVertex->next = head;                 // point the new vertex's next to the current head of the list
    head = newVertex;                       // overwrite head so it holds address of new vertex
}

struct VertexState {
    string name;
    int distance;                           // current best known distance from source (starts at INF)
    bool visited;                           // checks if the vertex has been visited (starts at false)
};

string distStr(int d) {                     // convert distance to string, if INF return "INF". cuz i used #define INF 1e9
    if (d == INF) {
    return "INF";
} 
    else {
    return to_string(d);
}       
}

int main() {
    const int numVertices = 4;
    string vertices[numVertices] = {"Nadia", "Farid", "Wei Ling", "Harith"};

    Vertex* adjList[numVertices] = {NULL};      

    // build the graph
    insertEdge(adjList[0], "Farid", 4);         // Nadia -> Farid (weight 4)
    insertEdge(adjList[0], "Wei Ling", 2);      // Nadia -> Wei Ling (weight 2)

    insertEdge(adjList[1], "Harith", 3);        // Farid -> Harith (weight 3)

    insertEdge(adjList[2], "Farid", 1);         // Wei Ling -> Farid (weight 1)
    insertEdge(adjList[2], "Harith", 5);        // Wei Ling -> Harith (weight 5)


    VertexState state[numVertices];             // array to hold the state of each vertex (distance, visited, name)
    for (int i = 0; i < numVertices; i++) {
        state[i].name = vertices[i];
        state[i].distance = INF;
        state[i].visited = false;
    }

    state[0].distance = 0;      // Nadia is the source vertex, so its distance is 0

    cout << "===================================\n";
    cout << " Dijkstra's Algorithm  (source: " << state[0].name << ")\n";
    cout << "===================================\n\n";

    for (int count = 0; count < numVertices - 1; count++) {             // runs 3 times because source vertex is already visited, so we only need to visit the other 3 vertices

        int minDistance = INF;      // start assuming nothing is close
        int u = -1;                 // no vertex chosen yet

        for (int i = 0; i < numVertices; i++) {                                 // scans through every vertex
            if (!state[i].visited && state[i].distance < minDistance) {         // 2 conditions: vertex not visited yet, and distance is less than current minDistance
                minDistance = state[i].distance;
                u = i;
            }
        }

        if (u == -1) {
            cout << "No more reachable vertices. Stopping early.\n\n";
            break;
        }

        state[u].visited = true;

        cout << "Round " << (count + 1) << ": visiting \"" << state[u].name
             << "\" (distance = " << state[u].distance << ")\n";

        Vertex* currentEdge = adjList[u];

        if (currentEdge == NULL) {
            cout << "   (no outgoing edges)\n";
        }

        while (currentEdge != NULL) {
            string destinationName = currentEdge->dest;
            int edgeWeight = currentEdge->weight;

            int v = -1;
            for (int i = 0; i < numVertices; i++) {
                if (state[i].name == destinationName) {
                    v = i;
                    break;
                }
            }

            if (v != -1 && !state[v].visited) {
                int candidate = state[u].distance + edgeWeight;
                cout << "   -> " << destinationName << " via weight " << edgeWeight
                     << "  (candidate = " << state[u].distance << " + " << edgeWeight
                     << " = " << candidate << ")";

                if (candidate < state[v].distance) {
                    cout << "   updated: " << distStr(state[v].distance)
                         << " -> " << candidate << "\n";
                    state[v].distance = candidate;
                } else {
                    cout << "   no change (stays " << distStr(state[v].distance) << ")\n";
                }
            }

            currentEdge = currentEdge->next;
        }

        cout << "\n";
    }

    cout << "===================================\n";
    cout << " Final shortest distances from " << state[0].name << "\n";
    cout << "===================================\n";
    cout << left << setw(12) << "Vertex" << "Distance\n";
    cout << "-----------------------\n";
    for (int i = 0; i < numVertices; i++) {
        cout << left << setw(12) << state[i].name << distStr(state[i].distance) << "\n";
    }

    for (int i = 0; i < numVertices; i++) {
        Vertex* current = adjList[i];
        while (current != NULL) { 
            Vertex* temp = current;
            current = current->next;
            delete temp;
        }
    }

    return 0;
};