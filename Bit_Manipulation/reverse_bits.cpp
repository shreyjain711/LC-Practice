// ***Problem Desc***: reverse bits of an unsigned int binary rep

// ***32 times, shift ans left(multiply 2), set ans' unit as per curr unit of n, shift n right 1(div by 2) [O(logn) time | O(1) space***:
uint32_t reverseBits(uint32_t n) {
    uint32_t a=0, c=32; 
    while(c--) {a<<=1; a|=n&1; n>>=1;} return a;
}
