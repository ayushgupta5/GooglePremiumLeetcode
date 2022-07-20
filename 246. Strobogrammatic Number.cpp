/*246. Strobogrammatic Number(Premium)

Given a string num which represents an integer, 
return true if num is a strobogrammatic number.
A strobogrammatic number is a number that looks the 
same when rotated 180 degrees (looked at upside down).

Input: num = "69"
Output: true

Input: num = "88"
Output: true

Input: num = "962"
Output: false
*/
class Solution {
public:
    bool isStrobogrammatic(string num) {
        vector<char> m{'0', '1', '$',  '$', '$', '$', '9', '$', '8', '6'};
        for (int i = 0; i <= num.size()/2; i++) {    
            if (m[num[i]-'0'] == '$' || m[num[i]-'0'] != num[num.size()-i-1]) {
                return false;
            }
        }
        return true;
    }
};