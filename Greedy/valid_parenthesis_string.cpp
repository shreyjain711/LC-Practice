// ***Problem Desc***: given str with (, ), * chars, * can be either of () or empty; possible to form valid paren expr

// ***Brute [O(n.3<sup>n</sup>) time | O(n) space]***: try backtracking with each val of *

// ***Go forward, open+star count should never be < close; then go back, close+star can never be < open [O(n) time | O(1) space]***:
bool checkValidString(string s) {
    int n=s.size(), openStarC=0, closeStarC=0;
    for(int i=0; i<n; ++i) {
        if(s[i] == ')') openStarC--;
        else openStarC++;
        if (openStarC < 0) return 0;
    } 
    for(int i=n-1; ~i; --i) {
        if(s[i] == '(') closeStarC--;
        else closeStarC++;
        if (closeStarC < 0) return 0;
    } return 1;
}

// ***Iterate starting min max range of open counts; if openMin ever -ve, make it 0 assuming it'll fix later, openMax shouldn't be -ve as then valid impossible [O(n) time | O(1) space]***:
bool checkValidString(string s) {
    int openMin=0, openMax=0;
    for(int i=0; i<s.size(); ++i) {
        if(s[i] == ')') {openMin--;openMax--;}
        else if(s[i] == '(') {openMin++;openMax++;}
        else {openMin--; openMax++;}
        if (openMax < 0) return 0;
        openMin = max(openMin, 0);
    } return !openMin;
}
