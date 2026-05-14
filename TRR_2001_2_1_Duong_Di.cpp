#include <bits/stdc++.h>
using namespace std;

int t, n, u, v;
vector<vector<int>> a;
vector<int> parent;
vector<bool> visited;

void dfs(int u){
    visited[u] = true;
    for (int v = 1; v <= n; v++){
        if (!visited[v] && a[u][v] == 1){
            parent[v] = u;
            dfs(v);
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("TK.INP", "r", stdin);
    freopen("TK.OUT", "w", stdout);

    int cnt = 0;
    cin >> t >> n >> u >> v;
    a.assign(n + 1, vector<int>(n + 1));
    parent.assign(n + 1, 0);
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
        dfs(u);
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