/*247. Strobogrammatic Number II(Premium)
Given an integer n, return all the strobogrammatic numbers that are of length n. 
You may return the answer in any order.

A strobogrammatic number is a number that looks the same 
when rotated 180 degrees (looked at upside down).

Input: n = 2
Output: ["11","69","88","96"]
Input: n = 1
Output: ["0","1","8"]
*/
class Solution {
public:
    vector<string> helper(int n, int m)  {
        if(n==0) return {""};
        if(n==1) return {"0", "1", "8"}; 
        vector<string> list = helper(n-2, n); 
        vector<string> res;
        for(auto& num: list) {
            if(n!=m) res.push_back("0" + num + "0");

            res.push_back("1" + num + "1");
            res.push_back("6" + num + "9");
            res.push_back("8" + num + "8");
            res.push_back("9" + num + "6");
        }        
        return res;
    }
    vector<string> findStrobogrammatic(int n) {
        // n=1: 0, 1, 6, 8, 9 
        // n=3:  111, 161, 181, 191,   .... 616, 666, 686 ...
        vector<string> res = helper(n, n);
        return res;
    }
};


