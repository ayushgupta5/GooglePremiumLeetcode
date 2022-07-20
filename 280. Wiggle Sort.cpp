/*280. Wiggle Sort
Given an integer array nums, reorder it such that nums[0] <= nums[1] >= nums[2] <= nums[3]....
You may assume the input array always has a valid answer.

Input: nums = [3,5,2,1,6,4]
Output: [3,5,1,6,2,4]
Explanation: [1,6,2,5,3,4] is also accepted.

Input: nums = [6,6,5,6,3,8]
Output: [6,6,5,6,3,8]
*/
class Solution {
public: 
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        for (int i = 1; i < n; i++)
            if (((i & 1) && nums[i] < nums[i - 1]) || (!(i & 1) && nums[i] > nums[i - 1]))
                swap(nums[i], nums[i - 1]);
    } 
};


