/*487. Max Consecutive Ones II
Given a binary array nums, return the maximum number of consecutive 1's in the array if you can flip at most one 0.
Input: nums = [1,0,1,1,0]
Output: 4
Explanation: Flip the first zero will get the maximum number of consecutive 1s. After flipping, the maximum number of consecutive 1s is 4.
Input: nums = [1,0,1,1,0,1]
Output: 4   */
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& a) {
        int i = 0, j = 0, k = 1, n = a.size(), cnt = 0, ans = 0;
        while(i < n) {
            if(a[i] == 0) cnt++;
            while(cnt > k) {
                if(a[j] == 0) cnt--;
                j++;
            }
            ans = max(ans, (i - j + 1));
            i++;
        }
        return ans;
    }
};



