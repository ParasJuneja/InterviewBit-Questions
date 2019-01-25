int a[] = {0, 0, 1, -1};
int b[] = {1, -1, 0, 0};
int m, n;
 
bool isSafe(vector<string> &A, vector<vector<bool> > &visited, int i, int j) {
    return (i >= 0 && i < n && j >= 0 && j < m && !visited[i][j] && A[i][j] == 'X');
}
 
void markShape(vector<string> &A, vector <vector <bool> > &visited, int i, int j) {
 
    visited[i][j] = true;
 
    for(int k = 0; k < 4; k++) {
        if(isSafe(A, visited, i + a[k], j + b[k])){
            markShape(A, visited, i + a[k], j + b[k]);
        }
    }
}
 
int Solution::black(vector<string> &A) {
    n = A.size();
    m = A[0].length();
 
    vector < vector <bool> > visited(n);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            visited[i].push_back(false);
        }
    }
 
    int blackShapeCount = 0;
 
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(visited[i][j] == false && A[i][j] == 'X') {
                markShape(A, visited, i, j);
                blackShapeCount++;
            }
        }
    }
    return blackShapeCount;
}