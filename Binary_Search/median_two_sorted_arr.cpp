// ***Problem Desc***: two arrays are sorted, find median if the two were merged
// ***Brute [O(m+n) time | O(m+n) space]***: actually merge the arrays and then find
/*
***Binary search for the merge point in arr1, mathematically get arr2's point [O(logn) time | O(1) space]***:
  - make sure arr1 is shorter or equal to arr2
  - after finding m1, determine val of m2 ( = total/2 - m1)
  - then the pts of split will be m1-1, m1 and m2-1, m2 (if they exist, else INT_MIN/MAX)
  - determine if positions aren't median satisfying i.e. if val[m1-1] > val[m2] (move leftwards) or val[m1] < val[m2-1] (move right)
*/
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int m=nums1.size(), n=nums2.size(); 
    if (m>n) return findMedianSortedArrays(nums2,nums1);
    int l1=0, h1=m, m1, m2;
    while (l1<=h1) {
        m1 = (h1+l1)/2;
        m2 = (n+m)/2 - m1; 
        int a1 = m1>0 ? nums1[m1-1] : INT_MIN,
            b1 = m1<m ? nums1[m1] : INT_MAX,
            a2 = m2>0 ? nums2[m2-1] : INT_MIN,
            b2 = m2<n ? nums2[m2] : INT_MAX;
        if (a1 > b2) {
            h1 = m1-1;
        } else if (a2 > b1) {
            l1 = m1+1;
        } else {
            return (m+n)%2 ? min(b1, b2) : (max(a1, a2) + min(b1, b2))/2.0;
        }
    } return 0;
}
