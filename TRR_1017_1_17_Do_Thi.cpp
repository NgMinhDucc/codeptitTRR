#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("DT.INP", "r", stdin);
    freopen("DT.OUT", "w", stdout);

    int t, n, m;
    cin >> t >> n >> m;
    vector<int> vao(n + 1, 0);
    vector<int> ra(n + 1, 0);
    vector<vector<int>> lt(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= m; i++){
        int u, v;
        cin >> u >> v;
        vao[v] += 1;
        ra[u] += 1;
        lt[u][i] = 1;
        lt[v][i] = -1;
    }

    if (t == 1){
        for (int i = 1; i <= n; i++){
            cout << vao[i] << " " << ra[i] << "\n";
        }
    }
    if (t == 2){
        cout << n << " " << m << "\n";
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= m; j++){
                cout << lt[i][j] << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}