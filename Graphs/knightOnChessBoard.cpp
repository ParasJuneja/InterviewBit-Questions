#include <bits/stdc++.h>
#include <queue>

using namespace std;

class cord {
    public:
        int x, y, l;
        cord(){}
        cord(int x, int y) {
            this->x = x;
            this->y = y;
            this->l = 0;
        }
};

int N, M;
int a[] = {2, 2, -2, -2, 1, -1, 1, -1};
int b[] = {1, -1, 1, -1, 2, 2, -2, -2};

bool isSafe(int x, int y, vector < vector <bool> > &visited) {
    return (x > 0 && y > 0 && x <= N && y <= M && !visited[x][y]);
}

int knight (int n, int m, int sx, int sy, int dx, int dy) {
    N = n;
    M = m;
    queue<cord> q;

    vector <vector <bool> > visited(n+1);
    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= m; j++) {
            visited[i].push_back(false);
        }
    }

    cord ob(sx, sy);
    visited[sx][sy] = true;
    q.push(ob);

    while(!q.empty()) {
        cord o = q.front();
        q.pop();

        for( int i = 0; i < 8; i++) {
            if (o.x == dx && o.y == dy) {
                return o.l;
            }
            if (isSafe((o.x + a[i]), (o.y + b[i]), visited)) {
                ob.x = o.x + a[i];
                ob.y = o.y + b[i];
                ob.l = o.l + 1;
                visited[ob.x][ob.y] = true;
                q.push(ob);
            }
        }
    }
    return -1;
}

int main() {
    cout << knight(8, 8, 1, 1, 8, 8);
    return 0;
}
