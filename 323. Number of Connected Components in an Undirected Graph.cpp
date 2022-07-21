/*323. Number of Connected Components in an Undirected Graph
You have a graph of n nodes. You are given an integer n and an array edges where 
edges[i] = [ai, bi] indicates that there is an edge between ai and bi in the graph.
Return the number of connected components in the graph.
Input: n = 5, edges = [[0,1],[1,2],[3,4]]
Output: 2
Input: n = 5, edges = [[0,1],[1,2],[2,3],[3,4]]
Output: 1
*/
class Solution {
public:
    int find(vector<int> &parent, int vertex) {
        if (vertex == parent[vertex]) {
            return vertex;
        }
        return parent[vertex] = find(parent, parent[vertex]);
    }
    int combine(vector<int> &parent, int vertex1, int vertex2) {
        vertex1 = find(parent, vertex1);
        vertex2 = find(parent, vertex2);
        if (vertex1 == vertex2) return 0;
        else {
            parent[vertex2] = vertex1;
            return 1;
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<int> parent(n);
        for (int i = 0; i < n; i++) parent[i] = i;
        int components = n;
        for (int i = 0; i < edges.size(); i++) {
            components -= combine(parent, edges[i][0], edges[i][1]);
        }
        return components;
    }
};

