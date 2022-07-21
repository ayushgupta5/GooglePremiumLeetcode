/*320. Generalized Abbreviation
A word's generalized abbreviation can be constructed by taking any number of non-overlapping and non-adjacent substrings and replacing them with their respective lengths.
For example, "abcde" can be abbreviated into:
"a3e" ("bcd" turned into "3")
"1bcd1" ("a" and "e" both turned into "1")
"5" ("abcde" turned into "5")
"abcde" (no substrings replaced)
However, these abbreviations are invalid:
"23" ("ab" turned into "2" and "cde" turned into "3") is invalid as the substrings chosen are adjacent.
"22de" ("ab" turned into "2" and "bc" turned into "2") is invalid as the substring chosen overlap.
Given a string word, return a list of all the possible generalized abbreviations of word. Return the answer in any order.
Input: word = "word"
Output: ["4","3d","2r1","2rd","1o2","1o1d","1or1","1ord","w3","w2d","w1r1","w1rd","wo2","wo1d","wor1","word"]
Input: word = "a"
Output: ["1","a"]   */
class Solution {
public:
    void generateAbbreviations(vector<string>& result, string word, int pos) {
        for (int i = pos; i<word.length(); i++) {
            for (int j = 1; i + j<=word.length(); j++) {
                string t = word.substr(0, i);
                t += to_string(j) + word.substr(i + j);
                result.push_back(t);
                generateAbbreviations(result, t, i + 1 + to_string(j).length());
            }
        }
    }

    vector<string> generateAbbreviations(string word) {
        vector<string> result;
        result.push_back(word);
        generateAbbreviations(result, word, 0);
        return result;
    }
};

