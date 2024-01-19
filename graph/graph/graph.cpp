#include <iostream>
#include <stack>
#include <queue>

using namespace std;

class Graph {
private:
    bool** adjMatrix;
    int numVertices;

public:
    // Initialize the matrix to zero
    Graph(int numVertices) {
        this->numVertices = numVertices;
        adjMatrix = new bool* [numVertices];
        for (int i = 0; i < numVertices; i++) {
            adjMatrix[i] = new bool[numVertices];
            for (int j = 0; j < numVertices; j++)
                adjMatrix[i][j] = false;
        }
    }

    // Add edges
    void addEdge(int i, int j) {
        adjMatrix[i][j] = true;
        adjMatrix[j][i] = true;
    }

    // Remove edges
    void removeEdge(int i, int j) {
        adjMatrix[i][j] = false;
        adjMatrix[j][i] = false;
    }
    
    void markVertex(int j) {

        for (int i = 0; i < 9; i++) {
            adjMatrix[i][j] = 0;
        }
    }

    void BFS() {

        queue<int> que;
        int strtNode = 0;
        cout << strtNode << " ";
        markVertex(strtNode);
        que.push(strtNode);

        while (!que.empty()) {

            int i = que.front();

            for (int j = 0; j < 9; j++) {

                if (adjMatrix[i][j] == 1) {
                    que.push(j);
                    cout << j << " ";
                    removeEdge(i, j);
                    markVertex(j);
                }

            }
       
            que.pop();

        }

    }

    void DFS() {
        stack<int>st;
        int strtNode = 5;
        cout << strtNode;
        markVertex(strtNode);
        st.push(strtNode);

        while (!st.empty()) {

            int i = st.top();
            int temp = 0;
            for (int j = 0; j < 9; j++) {

                if (adjMatrix[i][j] == 1) {
                    cout << j;
                    st.push(j);
                    removeEdge(i, j);
                    markVertex(j);
                    i = j;
                    j = -1;
                }

            }
            st.pop();

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

    g.addEdge(0, 1);
    g.addEdge(0, 8);
    g.addEdge(8, 6);
    g.addEdge(8, 2);
    g.addEdge(8, 5);
    g.addEdge(6, 7);
    g.addEdge(6, 5);
    g.addEdge(4, 7);
    g.addEdge(2, 4);
    g.addEdge(2, 3);

  
  //  g.DFS();
    g.BFS();
  //  g.toString();
}