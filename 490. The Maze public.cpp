/*490. The Maze
There is a ball in a maze with empty spaces (represented as 0) and walls (represented as 1). The ball can go through the empty spaces by rolling up, down, left or right, but it won't stop rolling until hitting a wall. When the ball stops, it could choose the next direction.

Given the m x n maze, the ball's start position and the destination, where start = [startrow, startcol] and destination = [destinationrow, destinationcol], return true if the ball can stop at the destination, otherwise return false.

You may assume that the borders of the maze are all walls (see examples).

 

Example 1:


Input: maze = [[0,0,1,0,0],[0,0,0,0,0],[0,0,0,1,0],[1,1,0,1,1],[0,0,0,0,0]], start = [0,4], destination = [4,4]
Output: true
Explanation: One possible way is : left -> down -> left -> down -> right -> down -> right.
Example 2:


Input: maze = [[0,0,1,0,0],[0,0,0,0,0],[0,0,0,1,0],[1,1,0,1,1],[0,0,0,0,0]], start = [0,4], destination = [3,2]
Output: false
Explanation: There is no way for the ball to stop at the destination. Notice that you can pass through the destination but you cannot stop there.
Example 3:

Input: maze = [[0,0,0,0,0],[1,1,0,0,1],[0,0,0,0,0],[0,1,0,0,1],[0,1,0,0,0]], start = [4,3], destination = [0,1]
Output: false
 

Constraints:

m == maze.length
n == maze[i].length
1 <= m, n <= 100
maze[i][j] is 0 or 1.
start.length == 2
destination.length == 2
0 <= startrow, destinationrow <= m
0 <= startcol, destinationcol <= n
Both the ball and the destination exist in an empty space, and they will not be in the same position initially.
The maze contains at least 2 empty spaces.
*/
class Solution {
    bool hasPath(vector<vector<int>>& g, vector<int>& start, vector<int>& destination) {
        int n = g.size();
        int m = g[0].size();
        int X[4] = {-1, 1, 0, 0};
        int Y[4] = {0, 0, -1, 1};
        queue<pair<int, int>> q;
        vector<vector<int>> vis(n, vector<int> (m,0));
        int srcX = start[0];
        int srcY = start[1];
        int destX = destination[0];
        int destY = destination[1];
        q.push({srcX, srcY});
        vis[srcX][srcY] = 1;
        while(q.size()) {
            pair<int,int>tp = q.front();q.pop();
            if(tp.first == destX and tp.second==destY) return true;
            for(int i=0; i<4; i++) {
                int nx = tp.first+X[i];
                int ny = tp.second+Y[i];
                while(nx >= 0 and nx < n and ny >= 0 and ny < m and g[nx][ny] != 1) {
                    nx += X[i];
                    ny += Y[i];
                }
                nx -= X[i];
                ny -= Y[i];
                if(!vis[nx][ny]) {
                    q.push({nx, ny});
                    vis[nx][ny] = 1;
                }
            }
        }
        return false;
    }
};



