/*358. Rearrange String k Distance Apart
Given a string s and an integer k, rearrange s such that the same characters are at least distance k from each other. If it is not possible to rearrange the string, return an empty string "".
Input: s = "aabbcc", k = 3
Output: "abcabc"
Explanation: The same letters are at least a distance of 3 from each other.
Input: s = "aaabc", k = 3
Output: ""
Explanation: It is not possible to rearrange the string.
Input: s = "aaadbbcc", k = 2
Output: "abacabcd"
Explanation: The same letters are at least a distance of 2 from each other.  */
class Solution {
public:
    string rearrangeString(string s, int k) {
        int cnt[26] = {};
        priority_queue<pair<int, int>> pq;
        queue<pair<int, int>> q;
        for (auto ch : s)
            ++cnt[ch - 'a'];
        for (auto i = 0; i < 26; ++i)
            if (cnt[i] != 0)
                pq.push({cnt[i], i});
        string res = "";
        while (!pq.empty()) {
            auto p = pq.top(); pq.pop();
            res += 'a' + p.second;
            q.push({p.first - 1, p.second});
            if (q.size() >= k) {
                auto p = q.front(); q.pop();
                if (p.first)
                    pq.push({p.first, p.second});
            }
        }
        return res.size() == s.size() ? res : "";
    }
};




