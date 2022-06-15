/*
Given an integer array nums, return the length of the longest strictly increasing subsequence.

A subsequence is a sequence that can be derived from an array by deleting some or no elements without changing the order of the remaining elements. For example, [3,6,2,7] is a subsequence of the array [0,3,1,6,2,2,7].

 

Example 1:

Input: nums = [10,9,2,5,3,7,101,18]
Output: 4
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.
Example 2:

Input: nums = [0,1,0,3,2,3]
Output: 4
Example 3:

Input: nums = [7,7,7,7,7,7,7]
Output: 1
 

Constraints:

1 <= nums.length <= 2500
-10^4 <= nums[i] <= 10^4
 

Follow up: Can you come up with an algorithm that runs in O(n log(n)) time complexity?
*/

//TC - O(n*Log(n))
class Solution {
public:
    int lengthOfLIS(vector<int>& a) {
        int i, n = a.size(), ind;
        vector<int> lis;
        lis.push_back(a[0]);
        for(i=1; i<n; i++){
            if(a[i] > lis.back()) lis.push_back(a[i]);
            else {
                ind = lower_bound(lis.begin(), lis.end(), a[i]) - lis.begin();
                lis[ind] = a[i];
            }
        }
        return lis.size();
    }
};



class Solution {
public:
    int lengthOfLIS(vector<int>& a) {
        int i, prev, n = a.size(), ans = 1, lastIndex = 0, ind = 1;
        vector<int> dp(n, 1), hash(n);
        for(i=0; i<n; i++) {
            hash[i] = i;
            for(prev=0; prev<i; prev++) {
                if(a[prev] < a[i] && dp[i] < 1+dp[prev]) {
                    dp[i] = 1 + dp[prev];
                    hash[i] = prev;
                }
            }
            if(ans < dp[i]) {
                ans = dp[i];
                lastIndex = i;
            }
        }
        int lis[ans];
        lis[0]=a[lastIndex];
        while(hash[lastIndex] != lastIndex) {
            lastIndex = hash[lastIndex];
            lis[ind++] = a[lastIndex];
        }
        reverse(lis, lis + ans);
        for(i=0;i<ans;i++) cout<<lis[i]<<" "; cout<<endl;
        return ans;
    }
};

//DP Approach
class Solution {
public:
    int lengthOfLIS(vector<int>& a) {
        int i, prev, n = a.size(), ans = 1;
        vector<int> dp(n, 1);
        for(i=0; i<n; i++) {
            for(prev=0; prev<i; prev++) {
                if(a[prev] < a[i]) {
                    dp[i] = max(dp[i], 1 + dp[prev]);
                }
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};



//Recursive Approach DP
class Solution {
public:
    int f(int ind, int prevInd, vector<int> &a, int n, vector<vector<int>> &dp) {
        if(ind == n) return 0;
        if(dp[ind][prevInd+1] != -1) return dp[ind][prevInd+1];
        int len = f(ind + 1, prevInd, a, n, dp);
        if(prevInd == -1 || a[ind] > a[prevInd]) {
            len=max(len, 1 + f(ind + 1, ind, a, n, dp));
        }
        return dp[ind][prevInd+1] = len;
    }
    int lengthOfLIS(vector<int>& a) {
        int n=a.size();
        vector<vector<int>> dp(n, vector<int> (n+1, -1));
        return f(0, -1, a, n, dp);
    }
};