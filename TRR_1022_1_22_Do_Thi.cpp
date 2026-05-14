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
    vector<vector<int>> a(n + 1, vector<int>(n + 1, 10000));
    for (int i = 1; i <= m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        vao[v] += 1;
        ra[u] += 1;
        a[u][v] = w;
    }

    if (t == 1){
        for (int i = 1; i <= n; i++){
            cout << vao[i] << " " << ra[i] << "\n";
        }
    }
    if (t == 2){
        cout << n << "\n";
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= n; j++){
                if (i == j){
                    cout << 0 << " ";
                }
                else{
                    cout << a[i][j] << " ";
                }
            }
            cout << "\n";
        }
    }
    return 0;
}