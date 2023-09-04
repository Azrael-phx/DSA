#include<iostream>
#include<list>
#include<unordered_map>
using namespace std;

// class Graph{
//     public:
//         unordered_map<int, list<int>>adj;
//         void addEgdes(int u, int v, bool direction){
//             adj[u].push_back(v);
//             if(direction == 0)
//             //agar undirected graph banana hai mtlb har node mei ja skta to dono tarah rhega
//                 adj[v].push_back(u);
//         }

//         void printAdj(){
//             for(auto i : adj){
//                 cout << i.first << " ";
//                 for(auto j: i.second)
//                     cout << j << " ";
//                 cout << endl;
//             }
//         }
// };
// /*
//     example :

//     edges = {{1,2}, {3,4} , {5,6}, {4,5}};
//     here u represents the 0th index number which is the soruce node
//     v represents the 1st indexed number which is the destination node
//     i.e 1 is connected to 2, 3 (which is a node) is connected to 4 (node)
//     and we only have two columns here which represent the souce node and destination node
//     the edges vector contains m elements of such pair (2,3) 
//     for(auto i : edges ) will traverse each element which is of pair (2,3) 
// */
// int main(){
//     int n,m; // m = no.of edges , n = no. of nodes
//     cin >> n;
//     cout << " ";
//     cin >> m;

//     Graph g;
//     for(int i=0; i<m; i++){
//         int u, v;
//         cin>>u>>v;
//         g.addEgdes(u,v,1);
//     }

//     g.printAdj();
//     return 0;
// }

// Adjascency List representation
void addEdge(list<int>adj[], int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}
void displayAdjList(list<int> adj[], int v) {
    for(int i = 0; i<v; i++) {
        cout << i << "--->";
        list<int> :: iterator it;
        for(it = adj[i].begin(); it != adj[i].end(); ++it) {
            cout << *it << " ";
        }
        cout << endl;
    }
}

int main() {

  int V = 4;
  // Create an array of adjacency lists
  list<int> adj[4];
  // Add edges
  addEdge(adj, 0, 1);
  addEdge(adj, 0, 2);
  addEdge(adj, 0, 3);
  addEdge(adj, 1, 2);

  // Display the adjacency list
  displayAdjList(adj, V);
  return 0;
}