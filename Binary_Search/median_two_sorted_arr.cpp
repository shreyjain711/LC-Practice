// ***Problem Desc***: two arrays are sorted, find median if the two were merged
// ***Brute [O(m+n) time | O(m+n) space]***: actually merge the arrays and then find
/*
***Binary search for the merge point in arr1, mathematically get arr2's point [O(logn) time | O(1) space]***:
  - make sure arr1 is shorter or equal to arr2
  - after finding m1, determine val of m2
  - then the pts of split will be m1-1, m1 and m2-1, m2 (if they exist, else INT_MIN/MAX)
  - determine if positions aren't median satisfying i.e. if val[m1-1] > val[m2] (move leftwards) or val[m1] < val[m2-1] (move right)
*/
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int lo = 0, hi = nums1.size(), m1, m2;
    int m = nums1.size(), n = nums2.size(); 
    if (n<m) return findMedianSortedArrays(nums2, nums1);
    while (lo <= hi) {
        m1 = (lo+hi)/2; m2 = (m+n+1)/2 - m1;

        int i1A = m1>0 ? nums1[m1-1] : INT_MIN;
        int i1B = m1<m ? nums1[m1] : INT_MAX;
        int i2A = m2>0 ? nums2[m2-1] : INT_MIN;
        int i2B = m2<n ? nums2[m2] : INT_MAX;

        if (i1B < i2A) lo = m1 + 1;
        else if (i1A > i2B) hi = m1-1;
        else return (m+n)%2 ? 
                    max(i1A, i2A) : 
                    (max(i1A, i2A)/(double) 2 + min(i1B, i2B)/(double)2);
    }
    return -1;
}
