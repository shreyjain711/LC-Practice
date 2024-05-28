// ***Problem Desc***: reverse int. return 0 if on reversing num out of 32 bit signed int range. Can’t use 64 bit num

// ***check if current rev val isn't >INT_MAX/10 or <INT_MIN/10 then regular reverse flow [O(logn) time | O(1) space***:
int reverse(int x) {
    int rev = 0;
    while (x) {
        if (rev > INT_MAX/10 || rev < INT_MIN/10) return 0;
        rev = rev*10 + x%10; x /= 10;
    } return rev;
}
