// ***Problem Desc***: add two ints without + or - ops.

// ***Imagine addition of binary bits, addition happens by XOR-ing and the carry is seen with AND-ing it and shifting bits left 1 [O(logn) time | O(1) space***:
int getSum(int a, int b) {
    int t; while(b) {
        t = a^b; b=(a&b)<<1; a=t;
    } return a;
}
