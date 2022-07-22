/*346. Moving Average from Data Stream
Given a stream of integers and a window size, 
calculate the moving average of all integers in the sliding window.
Implement the MovingAverage class:
MovingAverage(int size) Initializes the object with the size of the window size.
double next(int val) Returns the moving average of the last size values of the stream.

Input
["MovingAverage", "next", "next", "next", "next"]
[[3], [1], [10], [3], [5]]
Output
[null, 1.0, 5.5, 4.66667, 6.0]

*/
class MovingAverage {
public:
    queue<int> q;
    int avergeSize;  double sum;
    MovingAverage(int size) { avergeSize = size; sum = 0.0; }
    double next(int val) {
        sum += val;
        q.push(val);
        int queueSize = q.size();
        if(queueSize <= avergeSize) {
            return sum / queueSize;
        }
        else{
            sum -= q.front();
            q.pop();
            return sum / avergeSize;
        }
    }
};



