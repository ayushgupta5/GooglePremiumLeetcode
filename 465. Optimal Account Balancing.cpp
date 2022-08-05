/*465. Optimal Account Balancing
You are given an array of transactions transactions where transactions[i] = [fromi, toi, amounti] indicates that the person with ID = fromi gave amounti $ to the person with ID = toi.
Return the minimum number of transactions required to settle the debt.

Example 1:

Input: transactions = [[0,1,10],[2,0,5]]
Output: 2
Explanation:
Person #0 gave person #1 $10.
Person #2 gave person #0 $5.
Two transactions are needed. One way to settle the debt is person #1 pays person #0 and #2 $5 each.
Example 2:

Input: transactions = [[0,1,10],[1,0,1],[1,2,5],[2,0,5]]
Output: 1
Explanation:
Person #0 gave person #1 $10.
Person #1 gave person #0 $1.
Person #1 gave person #2 $5.
Person #2 gave person #0 $5.
Therefore, person #1 only need to give person #0 $4, and all debt is settled.
 

Constraints:

1 <= transactions.length <= 8
transactions[i].length == 3
0 <= fromi, toi < 12
fromi != toi
1 <= amounti <= 100
*/
class Solution {
public:
    int dfs(vector<int>& lders, vector<int>&bwers, int m, int n){
		if (m == lders.size()) return 0;
		if (m == lders.size() - 1) return bwers.size() - n;
		if (n == bwers.size() - 1) return lders.size() - m;
		int minVal = INT_MAX;
		for (int i = m; i < lders.size(); i++) {
		        if (lders[i] == bwers[n])
				return 1 + dfs(lders, bwers, m+1, n + 1);
			if (lders[i] > bwers[n]) {
				lders[i] -= bwers[n];
				minVal = min(minVal, 1 + dfs(lders, bwers, m, n + 1));
				lders[i] += bwers[n];
			} else {
				bwers[n] -= lders[i];
				minVal = min(minVal, 1 + dfs(lders, bwers, m + 1, n));
				bwers[n] += lders[i];
			}
		}
		return minVal;
	}
	int minTransfers(vector<vector<int>>& transactions) {
		unordered_map<int, int> gaps;
		for (auto& tr : transactions) {
			gaps[tr[0]] -= tr[2]; 
			gaps[tr[1]] += tr[2];
		}
		vector<int> lenders, borrowers;
		for (auto& pr : gaps)
			if (pr.second < 0) lenders.push_back(-pr.second);
			else if (pr.second > 0) borrowers.push_back(pr.second);
		return dfs(lenders, borrowers, 0, 0);
	}
};


