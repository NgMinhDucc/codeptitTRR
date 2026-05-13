#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t, n;
    cin >> t >> n;
    vector<int> deg(n + 1, 0);
    vector<pair<int, int>> edge;
    for (int i = 1; i <= n; i++){
        int k;
        cin >> k;
        deg[i] = k;
        for (int j = 1; j <= k; j++){
            int x;
            cin >> x;
            if (i < x){
                edge.push_back({i, x});
            }
        }
    }

    if (t == 1){
        for (int i = 1; i <= n; i++){
            cout << deg[i] << " ";
        }
    }
    if (t == 2){
        int m = edge.size();
        vector<vector<int>> lt(n + 1, vector<int>(m + 1, 0));
        for (int i = 0; i < m; i++){
            lt[edge[i].first][i + 1] = 1;
            lt[edge[i].second][i + 1] = 1;
        }

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