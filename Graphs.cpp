#include<iostream>
#include<list>
#include<unordered_map>
#include<queue>
#include<stack>
using namespace std;
/*
    example :
    n, m = no of nodes, and no. of edges
    edges = {{1,2}, {3,4} , {5,6}, {4,5}};
    here u represents the 0th index number which is the soruce node
    v represents the 1st indexed number which is the destination node
    i.e 1 is connected to 2, 3 (which is a node) is connected to 4 (node)
    and we only have two columns here which represent the souce node and destination node
    the edges vector contains m elements of such pair (2,3) 
    for(auto i : edges ) will traverse each element which is of pair (2,3) 
*/

void prepareAdjList(unordered_map<int, list<int>>&adj, vector<pair<int,int>>edges){
    for(int i=0; i<edges.size(); i++){
            int u = edges[i].first;
            int v = edges[i].second;
        //undirected graph
            adj[u].push_back(v);
            adj[v].push_back(u);
    }
}
void bfs(unordered_map<int, list<int>>adj, vector<int>&ans, 
        unordered_map<int, bool>&visited, int node){
    queue<int>q;
    q.push(node);
    visited[node] = 1;

    while(!q.empty()){
        int frontNode= q.front();
        q.pop();

        ans.push_back(frontNode);
        for(auto i : adj[frontNode] ){
            if(!visited[i]){
                q.push(i);
                visited[i] = 1;
            }
        }
    }
}
vector<int> BFSmain(int n, vector<pair<int,int>>edges ){
    unordered_map<int, list<int>>adj;
    vector<int>ans;
    unordered_map<int, bool>visited;

    prepareAdjList(adj, edges);
    for(int i=0; i<n; i++){
        if(!visited[i])
            bfs(adj, ans, visited, i);
    }
    return ans;
}

void dfs(unordered_map<int, list<int>>adj, vector<int>&ans, 
        unordered_map<int, bool>&visited, int node){
            ans.push_back(node);
            visited[node] = true;
            for(auto i: adj[node]){
                if(!visited[i]){
                    dfs(adj, ans, visited, i);
                }
            }
}

vector<vector<int>> DFSmain(int n, vector<pair<int,int>>edges){
     unordered_map<int, list<int>>adj;
    vector<vector<int>>ans; 
    unordered_map<int, bool>visited;

    prepareAdjList(adj, edges);
    for(int i=0; i<n; i++){
        if(!visited[i]){
            vector<int> comp;
            dfs(adj, comp, visited, i);
            ans.push_back(comp);
        }
    }
    return ans;
}

//cycle detection in undirected graph -- BFS

bool isCycleBFS(int i, unordered_map<int, list<int>>adj, unordered_map<int, bool> &visited){
    queue<int> q;
    unordered_map<int, int> parent;

    parent[i] = -1;
    visited[i] = true;

    q.push(i);
    while(!q.empty()){
        int frontNode = q.front();
        q.pop();

        for(auto neighbour : adj[frontNode]){
            if(visited[neighbour] == true && neighbour != parent[frontNode]){
                return true;
            }
            else if(!visited[neighbour]){
                q.push(neighbour);
                visited[neighbour] = 1;
                parent[neighbour] = frontNode;
            }
        }
    }
    return false;
}

bool cycleDetection(vector<pair<int,int>>edges, int n, int m){
    unordered_map<int, list<int>>adj;
    prepareAdjList(adj, edges);
    unordered_map<int, bool> visited;
    for(int i=0; i<n; i++){
        if(!visited[i]){
            bool ans = isCycleBFS(i, adj, visited);
            if(ans) 
                return true;
        }
    }
    return false;
}


//Cycle detection in directed graph
//using DFS
bool isCycleDFS(int node, unordered_map<int, bool>&vis, unordered_map<int, bool>&dfsvis, 
                unordered_map<int, list<int>>&adj){
    //do dfs
    vis[node] = true;
    dfsvis[node] = true; 

    for(auto neighbour : adj[node]){
        if(!vis[neighbour]){
            bool cycledetect = isCycleDFS(neighbour, vis, dfsvis, adj);
            if(cycledetect)
                return true;
        }
        else if(dfsvis[neighbour])
            return true;
    }
    //mark the node no longer in the dfs traversal 
    dfsvis[node] = false;
    return false;
}

bool detectcycleinDirectedGraph(vector<pair<int,int>>edges, int n){
    unordered_map<int, list<int>>adj;
    prepareAdjList(adj , edges );

    unordered_map<int, bool>vis;
    unordered_map<int, bool> dfsvis;

    for(int i=0; i<n; i++){
        if(!vis[i]){
            bool ans = isCycleDFS(i, vis, dfsvis, adj);
            if(ans)
                return true;
        }5
    }
    return false;
}

//Topological Sort using DFS

void topoSort(int node, unordered_map<int, list<int>>&adj,  unordered_map<int, bool> &vis, stack<int>&s){
    //apply dfs 
    vis[node] = 1;
    for(auto neighbour : adj[node]){
        if(!vis[neighbour]){
            topoSort(neighbour, adj, vis, s);
        }
    }
    s.push(node);
}

vector<int> TopoLogicalSort(vector<pair<int,int>>edges, int n){
    vector<int>ans;
    unordered_map<int, list<int>>adj;
    prepareAdjList(adj, edges);
    stack<int> s;
    unordered_map<int, bool> vis;
    //for disconnected componenets
    for(int i=0; i<n; i++){
        if(!vis[i]){
            topoSort(i, adj, vis, s);
        }
    }
    while(!s.empty()){
        ans.push_back(s.top());
        s.pop();
    }
    return ans;
}
//topo sort using kahns algo -- it uses method to find the indegree and calculates the sort

vector<int> kahnBFS(vector<pair<int, int>>edges, int n){
    queue<int> q;
    unordered_map<int, list<int>>adj;
    prepareAdjList(adj, edges);

    vector<int>indegree(n);
    //find all the indegrees
    for(auto i: adj){
        for(auto j : i.second){
            indegree[j]++;
        }
    }

    for(int i=0; i<n; i++){
        if(indegree[i] == 0)
            q.push(i);
    }
    vector<int> ans;
    while(!q.empty()){
        int front = q.front();
        q.pop();

    ans.push_back(front);
        for(auto neighbour : adj[front]){
            indegree[neighbour]--;
            if(indegree[neighbour] == 0)
                q.push(neighbour);
        }
    }  
    return ans;
}


//shortest path in undirected graph - unweighted graph - idea is to use topological sort
//BFS Gives shortest path always 

//Dijkstra's - weighted, directed or undirected graph



int main() {
    int n = 4;
    vector<pair<int, int>> edges = {{0, 1}, {1, 2}, {2, 0}, {2, 3}};
    // vector<vector<int>> result = DFSmain(5, edges); //5 is the no. of nodes
    // for (vector<int> v : result) {
    //     for(auto j : v){
    //         cout << j << " ";
    //     }
    // }

    // vector<int> ans = TopoLogicalSort(edges, n);
    // for(auto i: ans){
    //     cout << i << " ";
    // }

    cout << detectcycleinDirectedGraph(edges, n);

  return 0;
}