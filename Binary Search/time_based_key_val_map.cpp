// ***Problem Desc***: for each key, at diff timestamps diff vals will be set. when get called for a particular timestamp, return val at its lower_bound ts

// ***Brute [O(n) time | O(1) space]***: search linearly for the right time

// ***binary search for lower bound [O(logn) time | O(1) space]***:
unordered_map<string, vector<pair<int, string>>> cache;
TimeMap() {
    cache.clear();
}

void set(string key, string value, int timestamp) {
    cache[key].push_back({timestamp, value});
}

string get(string key, int timestamp) {
    return search(cache[key], timestamp);

}

string search(vector<pair<int, string>> &list, int timestamp) {
    string ans;
    int lo = 0, hi = list.size()-1, mid;
    while (lo <= hi) {
        mid = lo + (hi-lo)/2;
        if (list[mid].first < timestamp) {
            ans = list[mid].second;
            lo = mid + 1;
        } else if (list[mid].first > timestamp) {
            hi = mid - 1;
        } else {
            ans = list[mid].second;
            break;
        }
    }
    return ans;
}
