// ***Problem Desc***: if num is happy then after n ops (op => take sum of sq of all digits) val reaches 1; if not then it will end up in a cycle

// ***Using set to store each op result [O(logn) time | O(logn) space]***:
int helper(int n) {int a=0; while(n) {int x=n%10; a+=x*x; n/=10;} return a;}
bool isHappy(int n) {
    unordered_set<int> s;
    while (n!=1) {
        if (s.count(n)) return 0;
        s.insert(n); n = helper(n);
    }
    return n==1;
}

// ***Using slow fast approach, slow = n, fast = op(n) then keep jumping till they not same, return if in end it is 1 [O(logn) time | O(1) space]***:
int helper(int n) {int a=0; while(n) {int x=n%10; a+=x*x; n/=10;} return a;}
bool isHappy(int n) {
    int slow=n, fast=helper(n);
    while (slow != fast) {
        slow=helper(slow); fast=helper(helper(fast));
    } return slow == 1;
}
