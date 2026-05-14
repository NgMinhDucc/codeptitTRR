#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> a;
vector<bool> visited;
vector<int> tplt;
vector<vector<int>> finall;

void dfs(int u){
    visited[u] = true;
    tplt.push_back(u);
    for (int i = 1; i <= n; i++){
        if (!visited[i] && a[u][i] == 1){
            dfs(i);
        }
    }
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

    for (int i = 1; i <= n; i++){
        if (!visited[i]){
            tplt.clear();
            dfs(i);
            sort(tplt.begin(), tplt.end());
            finall.push_back(tplt);
        }
    }

    cout << finall.size() << "\n";
    for (int i = 0; i < (int)finall.size(); i++){
        for (int j : finall[i]){
            cout << j << " ";
        }
        cout << "\n";
    }
    return 0;
}