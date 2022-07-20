/*276. Paint Fence(Premium)
You are painting a fence of n posts with k different colors. You must paint the posts following these rules:

Every post must be painted exactly one color.
There cannot be three or more consecutive posts with the same color.
Given the two integers n and k, return the number of ways you can paint the fence.

Input: n = 3, k = 2
Output: 6
Explanation: All the possibilities are shown.
Note that painting all the posts red or all the posts green is invalid because there cannot be three posts in a row with the same color.

Input: n = 1, k = 1
Output: 1

Input: n = 7, k = 2
Output: 42
*/
class Solution {
public:
    int numWays(int n, int k) {
        if(n <= 1 || k == 0)return n*k;
        int a = k,b = k * (k - 1), c = 0, d = 0;
        for(int i=2; i<n; i++){
            d = (k - 1) * (a + b);
            a = b; b = d;
        }
        return a + b;
    }
};


