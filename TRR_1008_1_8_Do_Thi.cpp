#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    freopen("DT.INP", "r", stdin);
    freopen("DT.OUT", "w", stdout);

    int t, n;
    cin >> t >> n;
    vector<pair<int, int>> edge;
    vector<int> degree(n + 1);
    for (int i = 1; i <= n; i++){
        int k;
        cin >> k;
        for (int j = 1; j <= k; j++){
            int x;
            cin >> x;
            if (i < x){
                edge.push_back({i, x});
            }
        }
        degree[i] = k;
    }

    if (t == 1){
        for (int i = 1; i <= n; i++){
            cout << degree[i] << " ";
        }
    }

    if (t == 2){
        int m = edge.size();
        cout << n << " " << m << endl;
        for (int i = 0; i < m; i++){
            cout << edge[i].first << " " << edge[i].second << endl;
        }
    }
    return 0;
}