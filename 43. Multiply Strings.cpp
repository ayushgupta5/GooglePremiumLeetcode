/*
43. Multiply Strings
Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2, also represented as a string.

Note: You must not use any built-in BigInteger library or convert the inputs to integer directly.

 

Example 1:

Input: num1 = "2", num2 = "3"
Output: "6"
Example 2:

Input: num1 = "123", num2 = "456"
Output: "56088"
 

Constraints:

1 <= num1.length, num2.length <= 200
num1 and num2 consist of digits only.
Both num1 and num2 do not contain any leading zero, except the number 0 itself.
*/
class Solution {
public:
    string multiply(string a, string b) {
        int i, j;
        if(a == "0" || b == "0") return "0";
        vector<int> ans(a.size() + b.size(), 0);
        for(i=a.size()-1; i>=0; i--) {
            for(j=b.size()-1; j>=0; j--) {
                ans[i+j+1] += ((a[i]-'0')*(b[j]-'0'));
                ans[i+j] += (ans[i+j+1]/10);
                ans[i+j+1] %= 10;
            }
        }
        i=0;
        while(i<ans.size() && ans[i]==0) i++;
        string res="";
        while(i<ans.size()) res += (ans[i++]+'0');
        return res;
    }
};