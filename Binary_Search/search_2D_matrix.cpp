// ***Problem Desc***: sorted matrix: each row's min > last row's max; row is sorted too

// ***Brute [O(m.n) time | O(1) space]***: search linearly

// ***Search linearly across 0..m*n [O(log(m.n)) time | O(1) space]***: convert linear index to matrix index
int getLinear(vector<vector<int>>& matrix, int index) {
    return matrix[index/matrix[0].size()][index%matrix[0].size()];
}

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int m = matrix.size(), n = matrix[0].size(), lo = 0, hi = m*n-1, mid, t;
    while (lo <= hi) {
        mid = lo + (hi-lo)/2; t = getLinear(matrix, mid);
        if (t < target) lo = mid+1;
        else if (t > target) hi = mid-1;
        else return 1;
    }
    return 0;
}


// ***Find right, then right column [O(log(m.n)) time | O(1) space]***: more variables, less neat
bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int m = matrix.size(), n = matrix[0].size();
    int lo_r = 0, hi_r = m-1, lo_c = 0, hi_c = n-1, mid_r, mid_c;
    while (lo_r <= hi_r && lo_c <= hi_c) {
        mid_r = lo_r + (hi_r-lo_r)/2;
        if (matrix[mid_r][lo_c] <= target && matrix[mid_r][hi_c] >= target) {
            mid_c = lo_c + (hi_c-lo_c)/2;
            if (matrix[mid_r][mid_c] < target) lo_c = mid_c + 1;
            else if (matrix[mid_r][mid_c] > target) hi_c = mid_c - 1;
            else return 1;
        } else if (matrix[mid_r][lo_c] > target) hi_r = mid_r - 1;
        else lo_r = mid_r + 1;
    }
    return 0;
}
