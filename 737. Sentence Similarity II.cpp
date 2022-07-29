/*737. Sentence Similarity II
We can represent a sentence as an array of words, for example, the sentence "I am happy with leetcode" can be represented as arr = ["I","am",happy","with","leetcode"].

Given two sentences sentence1 and sentence2 each represented as a string array and given an array of string pairs similarPairs where similarPairs[i] = [xi, yi] indicates that the two words xi and yi are similar.

Return true if sentence1 and sentence2 are similar, or false if they are not similar.

Two sentences are similar if:

They have the same length (i.e., the same number of words)
sentence1[i] and sentence2[i] are similar.
Notice that a word is always similar to itself, also notice that the similarity relation is transitive. For example, if the words a and b are similar, and the words b and c are similar, then a and c are similar.

 

Example 1:

Input: sentence1 = ["great","acting","skills"], sentence2 = ["fine","drama","talent"], similarPairs = [["great","good"],["fine","good"],["drama","acting"],["skills","talent"]]
Output: true
Explanation: The two sentences have the same length and each word i of sentence1 is also similar to the corresponding word in sentence2.
Example 2:

Input: sentence1 = ["I","love","leetcode"], sentence2 = ["I","love","onepiece"], similarPairs = [["manga","onepiece"],["platform","anime"],["leetcode","platform"],["anime","manga"]]
Output: true
Explanation: "leetcode" --> "platform" --> "anime" --> "manga" --> "onepiece".
Since "leetcode is similar to "onepiece" and the first two words are the same, the two sentences are similar.
Example 3:

Input: sentence1 = ["I","love","leetcode"], sentence2 = ["I","love","onepiece"], similarPairs = [["manga","hunterXhunter"],["platform","anime"],["leetcode","platform"],["anime","manga"]]
Output: false
Explanation: "leetcode" is not similar to "onepiece".
*/
class Solution {
public:
    string find(map<string, string> &m, string s) {
        if (m.find(s)==m.end()) {
            m[s] = s;
        }
        while(m[s]!=s) {
            s=m[s];
        }
        return m[s];
    }
    void uni(map<string, string> &m, string s1, string s2) {
        if (find(m,s1) != find(m,s2)) {
            m[find(m, s1)] = find(m,s2);            
        }
    }
    bool areSentencesSimilarTwo(vector<string>& words1, vector<string>& words2, vector<vector<string>>& pairs) {
        
        if (words1.size()!= words2.size()) {
            return false;
        }
        map<string, string> m;
        for (int i = 0; i < pairs.size(); i++) {
            uni(m, pairs[i][0], pairs[i][1]);
        }
        for(int i = 0; i < words1.size(); i++) {
            
            if (find(m, words1[i]) != find(m, words2[i]))
                return false;
        }
        return true;
    }
};