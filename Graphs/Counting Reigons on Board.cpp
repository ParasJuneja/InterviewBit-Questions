#include <bits/stdc++.h>

using namespace std;

int a[] = {0, 0, 1, -1};
int b[] = {1, -1, 0, 0};
int m, n;

bool isSafe(vector<vector<char> > &A, vector<vector<bool> > &visited, int i, int j) {
    return (i >= 0 && i < n && j >= 0 && j < m && !visited[i][j] && A[i][j] == 'O');
}

void markShape(vector<vector<char> > &A, vector <vector <bool> > &visited, vector < vector <bool> > &f, int i, int j) {

    visited[i][j] = true;
    f[i][j] = false;

    for(int k = 0; k < 4; k++) {
        if(isSafe(A, visited, i + a[k], j + b[k])){
            markShape(A, visited, f, i + a[k], j + b[k]);
        }
    }
}

void  crob(vector<vector<char> > &A) {
    n = A.size();
    m = A[0].size();

    vector < vector <bool> > visited(n);
    vector <vector <bool> > f(n);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            visited[i].push_back(false);
            f[i].push_back(true);
        }
    }

    for (int i = 0; i < n || i < m; i++) {
        if (i < n && visited[i][0] == false && A[i][0] == 'O') {
            markShape(A, visited, f, i, 0);
        }
        if (i < m && visited[0][i] == false && A[0][i] == 'O') {
            markShape(A, visited, f, 0, i);
        }
        if (i < m && visited[n - 1][i] == false && A[n - 1][i] == 'O') {
            markShape(A, visited, f, n - 1, i);
        }
        if (i < n && visited[i][m - 1] == false && A[i][m - 1] == 'O') {
            markShape(A, visited, f, i, m - 1);
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(f[i][j] == true && A[i][j] == 'O') {
                A[i][j] = 'X';
            }
        }
    }
}

int main() {
    vector<vector<char> > A = {{'O', 'O', 'X', 'X', 'X', 'X', 'X', 'O', 'X', 'O'},
                               {'O', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X'},
                               {'X', 'X', 'O', 'O', 'O', 'X', 'X', 'O', 'X', 'X'},
                               {'X', 'O', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'O'},
                               {'X', 'O', 'X', 'O', 'X', 'X', 'X', 'X', 'O', 'X'},
                               {'X', 'X', 'X', 'X', 'O', 'O', 'X', 'X', 'X', 'X'},
                               {'X', 'O', 'X', 'O', 'O', 'X', 'X', 'O', 'O', 'X'},
                               {'O', 'X', 'X', 'O', 'O', 'X', 'X', 'X', 'O', 'X'},
                               {'X', 'O', 'X', 'O', 'X', 'X', 'X', 'O', 'X', 'O'}};
    crob(A);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}


