// ***Problem Desc***: from an incoming stream of data, find the medium at any given time

// ***Min and Max Qs, max keeps lower half, min keeps greater; insert as per empty/max.top & balance; median as per sizes [O(logn) time insert, O(1) median | O(n) space]***:
priority_queue<int> maxFirstHalf;
priority_queue<int, vector<int>, greater<int>> minSecondHalf;
MedianFinder() {}

void addNum(int num) {
    if (maxFirstHalf.empty() || maxFirstHalf.top() >= num) maxFirstHalf.push(num);
    else minSecondHalf.push(num);
    
    if (maxFirstHalf.size() > minSecondHalf.size()+1) {
        minSecondHalf.push(maxFirstHalf.top()); maxFirstHalf.pop();
    } else if (maxFirstHalf.size() < minSecondHalf.size()) {
        maxFirstHalf.push(minSecondHalf.top()); minSecondHalf.pop();
    }
}

double findMedian() {
    if (maxFirstHalf.size() > minSecondHalf.size()) return maxFirstHalf.top();
    return (maxFirstHalf.top() + minSecondHalf.top()) / (double)2;
}
