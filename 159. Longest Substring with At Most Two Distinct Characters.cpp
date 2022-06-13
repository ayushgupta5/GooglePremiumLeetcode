/*
159. Longest Substring with At Most Two Distinct Characters(Premium)
Given a string s, 
return the length of the longest substring that contains 
at most two distinct characters.

Example 1:

Input: s = "eceba"
Output: 3
Explanation: The substring is "ece" which its length is 3.
Example 2:

Input: s = "ccaabbb"
Output: 5
Explanation: The substring is "aabbb" which its length is 5.
 

Constraints:

1 <= s.length <= 105
s consists of English letters.
*/
class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int lo=0, hi=0, n=s.size(), ans=0;
        unordered_map<char, int> mp;
        while(hi<n) {
            mp[s[hi]]++;
            hi++;
            while(mp.size()>2) {
                mp[s[lo]]--;
                if(mp[s[lo]]==0) mp.erase(s[lo]);
                lo++;
            }
            ans=max(ans, hi-lo);
        }
        return ans;
    }
};