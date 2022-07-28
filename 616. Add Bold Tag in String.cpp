/*616. Add Bold Tag in String
You are given a string s and an array of strings words. You should add a closed pair of bold tag <b> and </b> to wrap the substrings in s that exist in words. If two such substrings overlap, you should wrap them together with only one pair of closed bold-tag. If two substrings wrapped by bold tags are consecutive, you should combine them.

Return s after adding the bold tags.
Input: s = "abcxyz123", words = ["abc","123"]
Output: "<b>abc</b>xyz<b>123</b>"
Input: s = "aaabbcc", words = ["aaa","aab","bc"]
Output: "<b>aaabbc</b>c"   */
class Solution {
public:
    string addBoldTag(string s, vector<string>& dict) {
        int n = s.length();
        vector<pair<int,int>> pos;
        for(const auto& w: dict) {
            int c = w.length();
            for(size_t i = 0; (i = s.find(w,i)) != string::npos; ++i) {
                pos.emplace_back(i, i+c);
            }
        }
        int m = pos.size();
        sort(pos.begin(), pos.end());
        //for(auto xt : pos) cout<<xt.first<<" "<<xt.second<<endl;
        //cout<<endl;
        vector<pair<int,int>> merged;
        for(int i = 0; i < m;++i) {
            if(merged.empty() || merged.back().second < pos[i].first)  merged.push_back(pos[i]);
            else merged.back().second = max(merged.back().second, pos[i].second);
        }
        //for(auto xt : merged) cout<<xt.first<<" "<<xt.second<<endl;
        for(auto it = merged.rbegin(); it != merged.rend(); ++it) {
            s.insert(it->second, "</b>");
            s.insert(it->first, "<b>");
        }
        return s;
    }
};


