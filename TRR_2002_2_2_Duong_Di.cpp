#include <bits/stdc++.h>
using namespace std;

int t, n, u, v;
vector<vector<int>> a;
vector<bool> visited;
vector<int> par;

void bfs(int u){
    queue<int> qu;
    qu.push(u);
    visited[u] = true;
    while (!qu.empty()){
        int s = qu.front();
        qu.pop();
        for (int i = 1; i <= n; i++){
            if (!visited[i] && a[s][i]){
                qu.push(i);
                visited[i] = true;
                par[i] = s;
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
    a.assign(n + 1, vector<int>(n + 1));
    visited.assign(n + 1, false);
    par.assign(n + 1, 0);
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            cin >> a[i][j];
        }
    }
    if (t == 1){
        int cnt = 0;
        for (int i = 1; i <= n; i++){
            if (u != i && i != v && a[u][i] && a[i][v]){
                cnt += 1;
            }
        }
        cout << cnt;
    }
    else{
        bfs(u);
        if (!visited[v]){
            cout << 0;
        }
        else{
            vector<int> d;
            while (u != v){
                d.push_back(v);
                v = par[v];
            }
            d.push_back(u);
            for (int i = d.size() - 1; i >= 0; i--){
                cout << d[i] << " ";
            }
        }
    }
    return 0;
}