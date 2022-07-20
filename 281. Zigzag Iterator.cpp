/*281. Zigzag Iterator
Given two vectors of integers v1 and v2, implement an iterator to return their elements alternately.
Implement the ZigzagIterator class:

ZigzagIterator(List<int> v1, List<int> v2) initializes the object with the two vectors v1 and v2.
boolean hasNext() returns true if the iterator still has elements, and false otherwise.
int next() returns the current element of the iterator and moves the iterator to the next element.

Input: v1 = [1,2], v2 = [3,4,5,6]
Output: [1,3,2,4,5,6]
Explanation: By calling next repeatedly until hasNext returns false, the order of elements returned by next should be: [1,3,2,4,5,6].

Input: v1 = [1], v2 = []     Output: [1]

Input: v1 = [], v2 = [1]     Output: [1]
*/
class ZigzagIterator {
private:
    //use a queue to record iterators
    queue<pair<vector<int>::iterator, vector<int>::iterator>>q; 
public:
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        if (v1.size()) { q.push(make_pair(v1.begin(), v1.end())); }
        if (v2.size()) { q.push(make_pair(v2.begin(), v2.end())); }
    }
    int next() {
        auto p = q.front(); q.pop();
        int val = *(p.first++);                 // get the next value
        if (p.first != p.second) { q.push(p); } // only put next iterator back to queue if it's valid
        return val;
    }
    bool hasNext() {
        return q.size();
    }
};




