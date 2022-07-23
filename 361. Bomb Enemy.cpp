/*361. Bomb Enemy
Given an m x n matrix grid where each cell is either a wall 'W', an enemy 'E' or empty '0', return the maximum enemies you can kill using one bomb. You can only place the bomb in an empty cell.
The bomb kills all the enemies in the same row and column from the planted point until it hits the wall since it is too strong to be destroyed.
Example 1:
Input: grid = [["0","E","0","0"],["E","0","W","E"],["0","E","0","0"]]
Output: 3

Example 2:
Input: grid = [["W","W","W"],["0","0","0"],["E","E","E"]]
Output: 1
 

Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 500
grid[i][j] is either 'W', 'E', or '0'.
*/
class Solution {
public://361. Bomb Enemy
    int maxKilledEnemies(vector<vector<char>>& arr) {
        int i, j, n=arr.size(), m=arr[0].size(), ans=0, curr;
        if(n==0 || m==0) return 0;
        vector<vector<int>> row(n, vector<int> (m, 0)), col(n, vector<int> (m, 0));
        for(i=0;i<n;i++) { curr=0;
            for(j=0;j<m;j++) {
                if(arr[i][j]=='W') curr=0;
                else if(arr[i][j]=='E') curr++;
                else row[i][j] += curr;
            }  curr=0;
            for(j=m-1;j>=0;j--) {
                if(arr[i][j]=='W') curr=0;
                else if(arr[i][j]=='E') curr++;
                else row[i][j] += curr;
            }
        }
        for(j=0;j<m;j++) { curr=0;
            for(i=0;i<n;i++) {
                if(arr[i][j]=='W') curr=0;
                else if(arr[i][j]=='E') curr++;
                else col[i][j] += curr;
            } curr=0;
            for(i=n-1;i>=0;i--) {
                if(arr[i][j]=='W') curr=0;
                else if(arr[i][j]=='E') curr++;
                else col[i][j] += curr;
            }
        }
        for(i=0;i<n;i++) 
            for(j=0;j<m;j++) 
                ans=max(ans, row[i][j]+col[i][j]);
        return ans;
    }
};


