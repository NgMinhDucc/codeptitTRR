#include <bits/stdc++.h>
using namespace std;

int t, n, u, v;
vector<vector<int>> a;
vector<int> parent;
vector<bool> visited;

void bfs(int u){
    queue<int> qu;
    qu.push(u);
    visited[u] = true;
    while (!qu.empty()){
        int v = qu.front();
        qu.pop();
        for (int i = 1; i <= n; i++){
            if (!visited[i] && a[v][i] == 1){
                qu.push(i);
                visited[i] = true;
                parent[i] = v;
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("TK.INP", "r", stdin);
    freopen("TK.OUT", "w", stdout);

    cin >> t >> n >> u >> v;
    int cnt = 0;
    a.assign(n + 1, vector<int>(n + 1));
    parent.resize(n + 1);
    visited.assign(n + 1, false);
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            cin >> a[i][j];
        }
    }

    if (t == 1){
        for (int i = 1; i <= n; i++){
            if (i != u && i != v && a[u][i] && a[i][v]){
                cnt += 1;
            }
        }
        cout << cnt;
    }
    if (t == 2){
        bfs(u);
        vector<int> path;
        if (!visited[v]){
            cout << 0;
        }
        else{
            while (u != v){
                path.push_back(v);
                v = parent[v];
            }
            path.push_back(u);
            for (int i = path.size() - 1; i >= 0; i--){
                cout << path[i] << " ";
            }
        }
    }
    return 0;
}