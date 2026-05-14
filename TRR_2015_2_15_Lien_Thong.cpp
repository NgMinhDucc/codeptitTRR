#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> a;
vector<bool> visited;
vector<int> path;

void dfs(int u){
    visited[u] = true;
    path.push_back(u);
    for (int i = 1; i <= n; i++){
        if (!visited[i] && a[u][i]){
            dfs(i);
        }
    }
}
void dfs_undirected(int u){
    visited[u] = true;
    for (int i = 1; i <= n; i++){
        if (!visited[i] && (a[u][i] || a[i][u])){
            dfs_undirected(i);
        }
    }
}

string check(){
    int cnt = 0;
    for (int i = 1; i <= n; i++){
        if (!visited[i]){
            cnt += 1;
            dfs_undirected(i);
        }
    }
    if (cnt > 1){
        return "0"; // neither strongly nor weakly connected
    }
    for (int i = 1; i <= n; i++){
        visited.assign(n + 1, false);
        path.clear();
        dfs(i);
        if ((int)path.size() != n){
            return "2"; // weakly connected
        }
    }
    return "1"; // strongly connected
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("TK.INP", "r", stdin);
    freopen("TK.OUT", "w", stdout);

    cin >> n;
    a.assign(n + 1, vector<int>(n + 1));
    visited.assign(n + 1, false);
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            cin >> a[i][j];
        }
    }

    cout << check();
    return 0;
}