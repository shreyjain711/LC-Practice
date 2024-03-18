// ***Problem Desc***: given a square matrix, rotate it 90deg clockwise

// ***Take 4 corners, rotate, next cell adjoinging the corners is done next till next corner reached and then corner pointers decremented[O(n<sup>2</sup>) time | O(1) space]***:

// ***reverse the rows and then transpose [O(n<sup>2</sup>) time | O(1) space]***:
void rotate(vector<vector<int>>& matrix) {
    int n=matrix.size(); reverse(begin(matrix), end(matrix));
    for (int i=0; i<n; ++i)
        for (int j=i+1; j<n; j++)
            swap(matrix[i][j], matrix[j][i]);
}
