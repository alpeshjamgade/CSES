#include <bits/stdc++.h>

using namespace std;

const int mxN = 1e3;
const int di[4] = {1, 0, -1, 0}, dj[4] = {0, 1, 0, -1};
int n, m;
string adj[mxN];

bool isValid(int i, int j) {
    return (i >= 0 && j >= 0 && i < n && j < m && adj[i][j]=='.');
}

void DFS(int i, int j) {
    adj[i][j] = '#';

    for (int k = 0; k < 4; k++) {
        if (isValid(i + di[k], j + dj[k])) {
            DFS(i + di[k], j + dj[k]);
        }

    }
}

int countRooms() {
    int rooms = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (adj[i][j] == '.') {
                DFS(i, j);
                rooms++;
            }
        }
    }

    return rooms;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> adj[i];
    }

    cout << countRooms() << '\n';

    return 0;
}
