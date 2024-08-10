// #include<iostream>
// #include<queue>
// using namespace std;

// void bfs(int G[][7],int start,int n){
//     int i=start,j;
//     bool visited[n]={0};
//     cout<<i<<" ";
//     queue<int> q;
//     q.push(i);

//     while(!q.empty()){
//         i=q.front();
//         q.pop();
//         for(int j=1;j<n;j++){
//             if(G[i][j]==1 and visited[j]==0){
//                 cout<<j<<" ";
//                 q.push(j);
//                 visited[j]=1;
//             }
//         }
//     }
    

// }
// int main(){
//      int G[7][7]={{0,0,0,0,0,0,0},
//                  {0,0,1,1,0,0,0},
//                  {0,1,0,0,1,0,0},
//                  {0,1,0,0,1,0,0},
//                  {0,0,1,1,0,1,1},
//                  {0,0,0,0,1,0,0},
//                  {0,0,0,0,1,0,0}};
//     bfs(G,4,7);
//     return 0;
// }

// #include<iostream>
// #include<vector>

// using namespace std;

// class Graph{
//     private:
//     int V;
//     vector<vector<int>> adjMatrix;
//     public:
//     Graph(int V){
//     this->V=V;
//     adjMatrix.resize(V,vector<int>(3,0));
//     }
//     void addEdge(int u,int v){
//         adjMatrix[u][v]=1;
//         adjMatrix[v][u]=1;
//     }
//     void printGraph(){
//         for(int i=0;i<V;i++){
//             for(int j=0;j<V;j++){
//                 cout<<adjMatrix[i][j]<<" ";
//             }
//             cout<<endl;
//         }
        
//     }
// };
// int main(){
//        Graph g(4);
//     g.addEdge(0, 1);
//     g.addEdge(0, 2);
//     g.addEdge(1, 2);
//     g.addEdge(2, 3);

//     g.printGraph();
//     return 0;
// }

// #include<iostream>
// #include<vector>
// #include<list>
// using namespace std;
// class Graph{
//     private:
//     int V;
//     vector<list<int>>adjList;
//     public:
//     Graph(int v){
//         this->V=v;
//         adjList.resize(V);
//     }

//     void addEdge(int u,int v){
//     adjList[u].push_back(v);
//     adjList[v].push_back(u);
//     }

//     void printGraph() {
//         for (int i = 0; i < V; i++) {
//             cout << "Vertex " << i << ":";
//             for (int vertex : adjList[i]) {
//                 cout << " -> " << vertex;
//             }
//             cout << endl;
//         }
//     }
// };
// int main(){
//       Graph g(4);
//     g.addEdge(0, 1);
//     g.addEdge(0, 2);
//     g.addEdge(1, 2);
//     g.addEdge(2, 3);

//     g.printGraph();
//     return 0;
// }

// 

#include<iostream>

using namespace std;

void dfs(int G[][7],int start,int n){
    
    static int visited[7]={0};
    int j;
    if(visited[start]==0){
     cout<< start<<endl;
     visited[start]=1;

     for(j=0;j<n;j++){
        if(G[start][j]==1 &&  visited[j]==0)
            dfs(G,j,n);
     }
    }
}
int main(){
        int G[7][7]={{0,0,0,0,0,0,0},
                 {0,0,1,1,0,0,0},
                 {0,1,0,0,1,0,0},
                 {0,1,0,0,1,0,0},
                 {0,0,1,1,0,1,1},
                 {0,0,0,0,1,0,0},
                 {0,0,0,0,1,0,0}};
    dfs(G,4,7);
    return 0;
}