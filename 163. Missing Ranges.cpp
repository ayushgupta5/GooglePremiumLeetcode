/*
163. Missing Ranges
You are given an inclusive range [lower, upper] and a sorted unique integer array nums, where all elements are in the inclusive range.

A number x is considered missing if x is in the range [lower, upper] and x is not in nums.

Return the smallest sorted list of ranges that cover every missing number exactly. That is, no element of nums is in any of the ranges, and each missing number is in one of the ranges.

Each range [a,b] in the list should be output as:

"a->b" if a != b
"a" if a == b
 

Example 1:

Input: nums = [0,1,3,50,75], lower = 0, upper = 99
Output: ["2","4->49","51->74","76->99"]
Explanation: The ranges are:
[2,2] --> "2"
[4,49] --> "4->49"
[51,74] --> "51->74"
[76,99] --> "76->99"
Example 2:

Input: nums = [-1], lower = -1, upper = -1
Output: []
Explanation: There are no missing ranges since there are no missing numbers.
 

Constraints:

-109 <= lower <= upper <= 109
0 <= nums.length <= 100
lower <= nums[i] <= upper
All the values of nums are unique.
*/
class Solution {
public:
    string getRange(int lo, int hi) {
        return (lo == hi) ? (to_string(lo)) : (to_string(lo) + "->" + to_string(hi));
    }
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<string> ans;
        int i, prev=lower-1, curr;
        for(i=0;i<=nums.size();i++) {
            curr = ((i==nums.size()) ? (upper+1) : (nums[i]));
            if(curr - prev >= 2) ans.push_back(getRange(prev+1, curr-1));
            prev = curr;
        }
        return ans;
    }
};