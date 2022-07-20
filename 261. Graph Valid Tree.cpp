/*261. Graph Valid Tree(Premium)
You have a graph of n nodes labeled from 0 to n - 1. You are given an integer n and a list of edges where edges[i] = [ai, bi] indicates that there is an undirected edge between nodes ai and bi in the graph.

Return true if the edges of the given graph make up a valid tree, and false otherwise.
Input: n = 5, edges = [[0,1],[0,2],[0,3],[1,4]]
Output: true
*/
class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<int> nodes(n, 0);
        for(int i=0; i<n; i++) nodes[i] = i;
        for(int i=0; i<edges.size(); i++) {
            int first = edges[i][0];
            int second = edges[i][1];
            while(nodes[first] != first) first = nodes[first];
            while(nodes[second] != second) second = nodes[second];
            if(nodes[first] == nodes[second]) return 0;
            nodes [second] = first;
        }
        return edges.size() == n-1;
    }
};


