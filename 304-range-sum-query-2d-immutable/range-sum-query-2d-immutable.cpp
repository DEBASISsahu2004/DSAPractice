class NumMatrix {
public:
    vector<vector<int>> ps;
    NumMatrix(vector<vector<int>>& matrix) {
        // ps = matrix;
        int row = matrix.size();
        int col = matrix[0].size();

        ps = vector<vector<int>>(row + 1, vector<int>(col + 1, 0));
        for (int i = 1; i <= row; i++) {
            for (int j = 1; j <= col; j++) {
                // ps[i][j] += ps[i][j-1];
                ps[i][j] = matrix[i - 1][j - 1] + ps[i - 1][j] + ps[i][j - 1] -
                           ps[i - 1][j - 1];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        // int sum = 0;
        // for(int i=row1; i<=row2; i++){
        // sum += ps[i][col2];

        // if(col1 > 0){
        //     sum -= ps[i][col1 - 1];
        // }
        // }

        // return sum;

        return ps[row2 + 1][col2 + 1] - ps[row1][col2+1] - ps[row2+1][col1] + ps[row1][col1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */