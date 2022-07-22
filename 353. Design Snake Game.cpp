class SnakeGame {//353. Design Snake Game
private:
    vector<vector<int>> target;
    int i=0, column=0, row=0, m, n;
    deque<int> q;
public:
    SnakeGame(int width, int height, vector<vector<int>>& food) {
        m = height - 1;  n = width - 1;  target = food;
        q.emplace_back(0);
    }
    int move(string direction) {
		// moving 
        if (direction == "U") {  -- row; }
        else if (direction == "D") { ++ row; }
        else if (direction == "L") { -- column; }
        else {  ++ column; }
        
        // check if current position out of boundary
        if (column < 0 || column > n || row < 0 || row > m) { return -1; }
        
        // check if snake eats the food
        if (i < target.size() && row == target[i][0] && column == target[i][1]) { ++ i; }
        
        // pop front if snake does not eat the food
        else {  q.pop_front(); }
        
        // check if snake touches itself 
        if (find(q.begin(), q.end(), row * (n + 1) + column) != q.end()) {
            return -1;
        }
        
        // always emplace_back every steps
        q.emplace_back(row * (n + 1) + column);
        return i;
    }
};


