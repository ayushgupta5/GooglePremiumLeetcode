/*266. Palindrome Permutation(Premium)
Given a string s, return true if a permutation of the string could form a palindrome.
Input: s = "code"
Output: false
Input: s = "aab"
Output: true
Input: s = "carerac"
Output: true
*/
class Solution {
public:
    bool canPermutePalindrome(string s) {
        int ans = 0;
        vector<int> A(26, 0);
        for(auto x: s) A[x - 'a']++;
        for(auto x: A) if(x&1) ans++;
        return ans <= 1;
    }
};