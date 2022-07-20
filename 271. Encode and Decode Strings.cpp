/*271. Encode and Decode Strings

Design an algorithm to encode a list of strings to a string. The encoded string is then sent over the network and is decoded back to the original list of strings.

Machine 1 (sender) has the function:

string encode(vector<string> strs) {
  // ... your code
  return encoded_string;
}
Machine 2 (receiver) has the function:
vector<string> decode(string s) {
  //... your code
  return strs;
}

So Machine 1 does:

string encoded_string = encode(strs);
and Machine 2 does:

vector<string> strs2 = decode(encoded_string);
strs2 in Machine 2 should be the same as strs in Machine 1.

Implement the encode and decode methods.

You are not allowed to solve the problem using any serialize methods (such as eval).

Input: dummy_input = ["Hello","World"]
Output: ["Hello","World"]
Explanation:
Machine 1:
Codec encoder = new Codec();
String msg = encoder.encode(strs);
Machine 1 ---msg---> Machine 2

Machine 2:
Codec decoder = new Codec();
String[] strs = decoder.decode(msg);

Input: dummy_input = [""]
Output: [""]
*/
class Codec {
public:
    string encode(vector<string>& strs, string encoded = "") {
        for (string &s : strs) encoded += to_string(s.size()) + '.' + s;
        return encoded;
    }

    vector<string> decode(string s, vector<string> decoded = {}) {
        for (int i = 0, n = 0; i < s.size(); i += n, n = 0) {
            while (isdigit(s[i])) n = 10 * n + (s[i++] - '0');
            decoded.push_back(s.substr(++i, n));
        }
        return decoded;
    }
};