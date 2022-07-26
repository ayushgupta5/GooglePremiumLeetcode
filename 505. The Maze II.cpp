/*505. The Maze II
There is a ball in a maze with empty spaces (represented as 0) and walls (represented as 1). The ball can go through the empty spaces by rolling up, down, left or right, but it won't stop rolling until hitting a wall. When the ball stops, it could choose the next direction.

Given the m x n maze, the ball's start position and the destination, where start = [startrow, startcol] and destination = [destinationrow, destinationcol], return the shortest distance for the ball to stop at the destination. If the ball cannot stop at destination, return -1.

The distance is the number of empty spaces traveled by the ball from the start position (excluded) to the destination (included).

You may assume that the borders of the maze are all walls (see examples).

 

Example 1:


Input: maze = [[0,0,1,0,0],[0,0,0,0,0],[0,0,0,1,0],[1,1,0,1,1],[0,0,0,0,0]], start = [0,4], destination = [4,4]
Output: 12
Explanation: One possible way is : left -> down -> left -> down -> right -> down -> right.
The length of the path is 1 + 1 + 3 + 1 + 2 + 2 + 2 = 12.
Example 2:


Input: maze = [[0,0,1,0,0],[0,0,0,0,0],[0,0,0,1,0],[1,1,0,1,1],[0,0,0,0,0]], start = [0,4], destination = [3,2]
Output: -1
Explanation: There is no way for the ball to stop at the destination. Notice that you can pass through the destination but you cannot stop there.
Example 3:

Input: maze = [[0,0,0,0,0],[1,1,0,0,1],[0,0,0,0,0],[0,1,0,0,1],[0,1,0,0,0]], start = [4,3], destination = [0,1]
Output: -1
*/
class Solution {
    const vector<vector<int>> Dirs = {{0, -1}, {0, 1}, {1, 0}, {-1, 0} };
    bool isValid(int x, int y, const vector<vector<int>>& maze) {
        return x >= 0 && x < maze.size() && 
               y >= 0 && y < maze[0].size() &&
               maze[x][y] <= 0; 
    }
	// each element has x, y, and the total distance
    using P = vector<int>;
    struct Comparator {
        bool operator()(const P& a, const P& b) {
            return a[2] > b[2]; // need a min heap based on distance
        }  
    };
public:
    int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& dest) {
        if (maze.empty()) return false;  
        priority_queue<P, vector<P>, Comparator> q;
        q.push({start[0], start[1], 0});
        while (!q.empty()) {
            auto p = q.top();  q.pop();
            if (p[0] == dest[0] && p[1] == dest[1]) return p[2];
            if (maze[p[0]][p[1]] == -1) continue;
			// maze is modifiable and since we will never use this position again, we mark it as visited (-1)
            maze[p[0]][p[1]] = -1;
            for (const auto& d : Dirs) {
                int steps = 0, x = p[0], y = p[1];
                while (isValid(x + d[0], y + d[1], maze)) {
                    x += d[0]; y += d[1];   steps++;
                }
                if (maze[x][y] == 0) { q.push({x, y, p[2] + steps}); }
            }        
        }
        return -1;        
    }
};



