// ***Problem Desc***: given points on a grid, count num of squares possible if a point is given as a vertice

// ***Points x -> multiset(y); for given point, for each y pt on the same x, use it as vectical edge, form squares on its right and left [O(n<sup>2</sup>) time | O(n) space]***:
unordered_map<int, multiset<int>> xs; 
DetectSquares() {}
void add(vector<int> point) {xs[point[0]].insert(point[1]);}
int count(vector<int> point) {
    int sqs = 0;
    for (auto y: xs[point[0]]) {
        int sideLen = abs(y-point[1]); if (!sideLen) continue;
        int x1 = point[0] + sideLen, x2 = point[0] - sideLen;
        sqs += (xs[x1].count(point[1]) * xs[x1].count(y));
        sqs += (xs[x2].count(point[1]) * xs[x2].count(y));
    }
    return sqs;
}

// ***Points X -> {Y -> count}; for given point, for each y pt on the same x, use it as vectical edge, form squares on its right and left [O(n) time | O(n) space]***:
unordered_map<int, unordered_map<int,int>> counter; 
DetectSquares() {}
void add(vector<int> point) {counter[point[0]][point[1]]++;}
int count(vector<int> point) {
    int sqs = 0;
    for (auto y: counter[point[0]]) {
        int sideLen = abs(y.first-point[1]); if (!sideLen) continue;
        int x1 = point[0] + sideLen, x2 = point[0] - sideLen;
        sqs += (counter[x1][point[1]] * counter[x1][y.first] * y.second);
        sqs += (counter[x2][point[1]] * counter[x2][y.first] * y.second);
    }
    return sqs;
}
