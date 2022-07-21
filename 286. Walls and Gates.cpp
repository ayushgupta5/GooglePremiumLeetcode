/*286. Walls and Gates
You are given an m x n grid rooms initialized with these three possible values.
-1 A wall or an obstacle.
0 A gate.
INF Infinity means an empty room. We use the value 231 - 1 = 2147483647 to represent INF as you may assume that the distance to a gate is less than 2147483647.
Fill each empty room with the distance to its nearest gate. If it is impossible to reach a gate, it should be filled with INF.
Input: rooms = [[2147483647,-1,0,2147483647],[2147483647,2147483647,2147483647,-1],[2147483647,-1,2147483647,-1],[0,-1,2147483647,2147483647]] 
Output: [[3,-1,0,1],[2,2,1,-1],[1,-1,2,-1],[0,-1,3,4]]
Input: rooms = [[-1]]   Output: [[-1]]
*/
class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        const int row = rooms.size();
        if (row == 0) return;
        const int col = rooms[0].size();
        queue<pair<int, int>> canReach;  // save all element reachable
        vector<pair<int, int>> dirs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}}; // four directions for each reachable
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(0 == rooms[i][j])
                    canReach.emplace(i, j);
            }
        }
        while(!canReach.empty()){
            int r = canReach.front().first, c = canReach.front().second;
            canReach.pop();
            for (auto dir : dirs) {
                int x = r + dir.first,  y = c + dir.second;
                // if x y out of range or it is obstasle, or has small distance aready
                if (x < 0 || y < 0 || x >= row || y >= col || rooms[x][y] < INT_MAX) continue;
                rooms[x][y] = rooms[r][c] + 1;
                canReach.emplace(x, y);
            }
        }
    }
};



