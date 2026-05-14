#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("DT.INP", "r", stdin);
    freopen("DT.OUT", "w", stdout);

    int t, n;
    cin >> t >> n;
    vector<int> vao(n + 1, 0);
    vector<int> ra(n + 1, 0);
    vector<pair<int, int>> edge;
    for (int i = 1; i <= n; i++){
        int k;
        cin >> k;
        for (int j = 1; j <= k; j++){
            int x;
            cin >> x;
            vao[x] += 1;
            ra[i] += 1;
            edge.push_back({i, x});
        }
    }
    
    if (t == 1){
        for (int i = 1; i <= n; i++){
            cout << vao[i] << " " << ra[i] << "\n";
        }
    }
    if (t == 2){
        int m = edge.size();
        cout << n << " " << m << "\n";
        vector<vector<int>> a(n + 1, vector<int>(m + 1, 0));
        for (int i = 1; i <= m; i++){
            a[edge[i - 1].first][i] = 1;
            a[edge[i - 1].second][i] = -1;
        }
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= m; j++){
                cout << a[i][j] << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}