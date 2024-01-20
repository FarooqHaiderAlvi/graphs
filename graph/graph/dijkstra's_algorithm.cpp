
#include <iostream>
#include <stack>
#include <queue>

using namespace std;
class Graph;

class Vertex {
    friend class Graph;
    int data;
    int parent;
    bool mark;
public:

    Vertex() {
        data = INT_MAX;
        parent = -1;
        mark = false;
    }

 
};



class Graph {
private:
    int** adjMatrix;
    int numVertices;
    Vertex* arr;

public:
    // Initialize the matrix to zero
    Graph(int numVertices) {
        this->numVertices = numVertices;
        adjMatrix = new int* [numVertices];
        for (int i = 0; i < numVertices; i++) {
            adjMatrix[i] = new int[numVertices];
            for (int j = 0; j < numVertices; j++)
                adjMatrix[i][j] = -1;
        }

        arr = new Vertex[numVertices];
      
        
    }

    // Add edges
    void addEdge(int i, int j,int w) {
        adjMatrix[i][j] = w;
        adjMatrix[j][i] = w;
    }

    // Remove edges
    void removeEdge(int i, int j) {
        adjMatrix[i][j] = -1;
        adjMatrix[j][i] = -1;
    }

    void markVertex(int j) {

        for (int i = 0; i < 9; i++) {
            adjMatrix[i][j] = -1;
        }
    }
    void swap(int& a, int& b) {
        if (a != b) {
            a = a + b;
            b = a - b;
            a = a - b;
        }
    }
    void BFS() {

        queue<int> que;
        int startVertex = 1;
        arr[startVertex].data = 0;
        que.push(startVertex);

        while (!que.empty()) {
            int i = que.front();

            for (int j = 0; j < 9; j++) {

                if (adjMatrix[i][j] != -1 && arr[j].mark==false) {
                    que.push(j);
                  //  cout << j << " ";
                    int temp = adjMatrix[i][j] + arr[i].data;    
                    if (temp<arr[j].data) {
                        arr[j].data = temp;
                        arr[j].parent = i;
                    }
                }
            }
            que.pop();
            arr[i].mark = true;

        }
        cout << "V"<<" "<< "VV" << " " << "VP" << endl;
        for (int i = 0; i < 9; i++) {
            cout <<i<<" "<< arr[i].data << " " << arr[i].parent << endl;
        }

    }

 

    ~Graph() {
        for (int i = 0; i < numVertices; i++)
            delete[] adjMatrix[i];
        delete[] adjMatrix;
    }
};

int main() {
    Graph g(9);

    g.addEdge(0, 1,4);
    g.addEdge(0, 2,2);
    g.addEdge(1, 2,4);
    g.addEdge(1, 3,5);
    g.addEdge(2, 4,7);
    g.addEdge(2, 5,9);
    g.addEdge(3, 4,1);
    g.addEdge(3, 6,4);
    g.addEdge(3, 7,3);
    g.addEdge(3, 7,3);
    g.addEdge(4, 5,1);
    g.addEdge(5, 7,11);
    g.addEdge(6, 7,6);
    g.addEdge(6, 8,2);
    g.addEdge(7, 8,5);
   


    //  g.DFS();
    g.BFS();
    //  g.toString();
}