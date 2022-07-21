/*294. Flip Game II
You are playing a Flip Game with your friend.

You are given a string currentState that contains only '+' and '-'. You and your friend take turns to flip two consecutive "++" into "--". The game ends when a person can no longer make a move, and therefore the other person will be the winner.

Return true if the starting player can guarantee a win, and false otherwise.
Input: currentState = "++++"
Output: true
Explanation: The starting player can guarantee a win by flipping the middle "++" to become "+--+".
Input: currentState = "+"
Output: false
*/
class Solution {
public:
    bool canWin(string s) {
        for(int i = 0;i<s.length();i++) {
            if(s[i] == '+' && s[i+1] == '+') {
                s[i] = '-';
                s[i + 1] = '-';
                bool possible = canWin(s);
                if(!possible) return true;
                s[i] = '+';
                s[i + 1] = '+';
            }
        }
        return false;
    }
};



