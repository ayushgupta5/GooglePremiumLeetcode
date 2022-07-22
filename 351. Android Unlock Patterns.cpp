class Solution {
public://351. Android Unlock Patterns
    vector<bool> used;
    int numberOfPatterns(int m, int n) {
        int res = 0;
        vector<bool> u(9,false);
        used = u;
        for(int i = m;i<=n;i++) {
            res += calc(-1,i);
            vector<bool> u1(9,false);
            used = u1;
        }
        return res;
    }
    int calc(int x, int len) {
        if(len == 0)return 1;
        int sum = 0;
        for(int i = 0;i<9;i++) {
            if(isValid(x,i)) {
                used[i] = true;
                sum += calc(i,len - 1);
                used[i] = false;
            }
        }
        return sum;
    }
    bool isValid(int p, int n) {
        if(used[n])return false;
        if(p == -1)return true;
        if((n+p)%2 == 1)return true;
        int mid = (p + n)/2;
        if(mid == 4)return used[mid];
        if((n%3 != p%3 )&& (n/3 != p/3)) return true;
        return used[mid];
    }
};


