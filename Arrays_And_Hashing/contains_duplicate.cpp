// Problem desc: return true if array contains a duplicate (value appears at least twice) else false

// Brute [O(n^2) time | O(1) space]: pick each element and iterate through next ones
bool containsDuplicate(vector<int>& nums) {
    for (int i = 0; i<nums.size(); ++i) {
        for (int j = i+1; j<nums.size(); ++j) {
            if (nums[i] == nums[j]) return true;
        }
    }
    return false;
}

// Sort and compare [O(n.logn) time | O(1) space]: sort and compare adjoining elements
bool containsDuplicate(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    for (int i = 0; i<nums.size()-1; ++i) 
        if (nums[i] == nums[i+1]) return true;
    return false;
}

// Hashset [O(nlogn) time | O(n) space]: insert into set (or initiate with), insert takes O(logn) time

// Hashmap [O(n) time | O(n) space]: keep saving in unordered set
bool containsDuplicate(vector<int>& nums) {
    unordered_map<int, bool> m;
    for (int i = 0; i<nums.size(); ++i) {
        if (m.find(nums[i]) != m.end()) return true;
        m[nums[i]] = true;
    }
    return false;
}
