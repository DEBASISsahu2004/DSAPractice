class NumMatrix {
public:
    vector<vector<int>> ps;
    NumMatrix(vector<vector<int>>& matrix) {
        ps = matrix;
        int row = matrix.size();
        int col = matrix[0].size();
        for(int i=0; i<row; i++){
            for(int j = 1; j<col; j++){
                ps[i][j] += ps[i][j-1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum = 0;
        for(int i=row1; i<=row2; i++){
            sum += ps[i][col2];

            if(col1 > 0){
                sum -= ps[i][col1 - 1];
            }
        }

        return sum;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */