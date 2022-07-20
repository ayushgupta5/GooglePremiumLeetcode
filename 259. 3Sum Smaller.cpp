/*259. 3Sum Smaller(Premium)
Given an array of n integers nums and an integer target, find the number of index triplets i, j, k with 0 <= i < j < k < n that satisfy the condition nums[i] + nums[j] + nums[k] < target.

Input: nums = [-2,0,1,3], target = 2
Output: 2
Explanation: Because there are two triplets which sums are less than 2:
[-2,0,1]
[-2,0,3]

Input: nums = [], target = 0
Output: 0

Input: nums = [0], target = 0
Output: 0
*/
class Solution {
public:
    int threeSumSmaller(vector<int>& a, int target) {
        sort(a.begin(),a.end());
        int i, left, right, n = a.size(), diff = INT_MAX, ans = 0, sum;
        for(i=0;i<n-2;i++) {
            left = i+1;   right = n-1;
            while(left < right) {
                sum = a[i] + a[left] + a[right];
                if(sum < target) {
                    ans += (right - left);
                    left++;
                }
                else right--;
            }
        }
        return ans;
    }
};
