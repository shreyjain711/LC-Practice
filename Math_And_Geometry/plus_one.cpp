// ***Problem Desc***: given a number whose digits are in form of a vector with n-1th digit being the units; add 1 to it and return the result 

// ***Add a spare 0 in front, keep adding 1 from the last digit; at end remove first elem if it is 0 [O(n) time | O(1) space]***:
vector<int> plusOne(vector<int>& digits) {
    int n=digits.size(); digits.insert(digits.begin(), 0); digits[n]+=1;
    while (n) {digits[n-1]+=digits[n]/10; digits[n--]%=10;}
    if (!digits[0]) digits.erase(begin(digits));
    return digits;
}
