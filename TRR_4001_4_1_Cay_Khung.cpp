#include <bits/stdc++.h>
using namespace std;

int t, n, s;
vector<vector<int>> a;
vector<bool> visited;
vector<pair<int, int>> tree;

void in(){
    if ((int)tree.size() < n - 1){
        cout << 0;
    }
    else{
        cout << n - 1 << "\n";
        for (auto it : tree){
            cout << min(it.first, it.second) << " " << max(it.first, it.second) << "\n";
        }
    }
}

void dfs(int u){
    visited[u] = true;
    for (int v : a[u]){
        if (!visited[v]){
            tree.push_back({u, v});
            dfs(v);
        }
    }
}

void bfs(int u){
    queue<int> qu;
    qu.push(u);
    visited[u] = true;
    while (!qu.empty()){
        int s = qu.front();
        qu.pop();
        for (int v : a[s]){
            if (!visited[v]){
                visited[v] = true;
                tree.push_back({s, v});
                qu.push(v);
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("CK.INP", "r", stdin);
    freopen("CK.OUT", "w", stdout);

    cin >> t >> n >> s;
    a.resize(n + 1);
    visited.assign(n + 1, false);
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            int x;
            cin >> x;
            if (x == 1){
                a[i].push_back(j);
                a[j].push_back(i);
            }
        }
    }
    if (t == 1){
        dfs(s);
        in();
    }
    else if (t == 2){
        bfs(s);
        in();
    }
    return 0;
}