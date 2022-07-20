/*253. Meeting Rooms II
Given an array of meeting time intervals intervals where intervals[i] = [starti, endi], return the minimum number of conference rooms required.
Input: intervals = [[0,30],[5,10],[15,20]]
Output: 2
Input: intervals = [[7,10],[2,4]]
Output: 1
*/
class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        priority_queue<int , vector<int> , greater<int>>pq;
        int maxi = -1 , overlappedTime  = -1;
        for(auto xt : intervals) {
            if(!pq.empty() and pq.top()<=xt[0])   pq.pop();
            pq.push(xt[1]);
            if(maxi < (int)pq.size()) {
                overlappedTime = xt[0];
            }
            maxi = max(maxi , (int)pq.size());
        }
        return maxi;
    }
};