/*370. Range Addition
You are given an integer length and an array updates where updates[i] = [startIdxi, endIdxi, inci].

You have an array arr of length length with all zeros, and you have some operation to apply on arr. In the ith operation, you should increment all the elements arr[startIdxi], arr[startIdxi + 1], ..., arr[endIdxi] by inci.

Return arr after applying all the updates.

Input: length = 5, updates = [[1,3,2],[2,4,3],[0,2,-2]]
Output: [-2,0,3,5,3]

Input: length = 10, updates = [[2,4,6],[5,6,8],[1,9,-4]]
Output: [0,-4,2,2,2,4,4,-4,-4,-4]
*/
class Solution {
public:
    vector<int> getModifiedArray(int n, vector<vector<int>>& up) {
        vector<int>a(n,0);
        for(auto xt : up) {
            int l = xt[0];
            int r = xt[1];
            a[l]+=xt[2];
            if((r+1)<n) a[r+1]-=xt[2];
        }
        for(int i=1;i<n;i++)
            a[i]+=a[i-1];
        return a;
    }
};

