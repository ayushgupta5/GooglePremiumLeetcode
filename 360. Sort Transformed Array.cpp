/*360. Sort Transformed Array
Given a sorted integer array nums and three integers a, b and c, apply a quadratic function of the form f(x) = ax2 + bx + c to each element nums[i] in the array, and return the array in a sorted order.
Input: nums = [-4,-2,2,4], a = 1, b = 3, c = 5
Output: [3,9,15,33]
Input: nums = [-4,-2,2,4], a = -1, b = 3, c = 5
Output: [-23,-5,1,7]
*/
class Solution {
public:
    vector<int> sortTransformedArray(vector<int>& arr, int a, int b, int c) {
        int i, lo = 0, hi = arr.size()-1, n = arr.size(), end = (a >= 0) ? (n-1) : (0);
        vector<int> ans(n, 0);
        for(i=0; i<n; i++) arr[i] = a*arr[i]*arr[i] + b*arr[i] + c;
        while(lo <= hi) {
            if(a >= 0) ans[end--] = (arr[lo] > arr[hi]) ? (arr[lo++]) : (arr[hi--]);
            else ans[end++] = (arr[lo] < arr[hi]) ? (arr[lo++]) : (arr[hi--]);
        }
        return ans;
    }
};

