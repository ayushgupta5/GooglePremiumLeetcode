/*340. Longest Substring with At Most K Distinct Characters
Given a string s and an integer k, return the length of the longest substring of s that contains at most k distinct characters.
Input: s = "eceba", k = 2
Output: 3
Explanation: The substring is "ece" with length 3.
Input: s = "aa", k = 1
Output: 2
Explanation: The substring is "aa" with length 2.     */
class Solution {
public:
    int f(vector<int> &A, int k) {
        int ans = 0;
        for(auto x: A) if(x>0) ans++;
        return ans;
    }
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        int lo = 0, hi = 0, n = s.size(), ans = 0;
        vector<int> A(256, 0);
        while(hi < n) {
            A[s[hi]]++;
            while(f(A, k) > k) {
                A[s[lo]]--;
                lo++;
            }
            ans = max(ans, hi - lo + 1);
            hi++;
        }
        return ans;
    }
};



