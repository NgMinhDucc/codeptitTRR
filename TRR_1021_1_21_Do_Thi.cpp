#include <bits/stdc++.h>
using namespace std;

struct Edge{
    int u, v, w;
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("DT.INP", "r", stdin);
    freopen("DT.OUT", "w", stdout);

    int t, n;
    cin >> t >> n;
    vector<int> vao(n + 1, 0);
    vector<int> ra(n + 1, 0);
    vector<Edge> edge;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            int x;
            cin >> x;
            if (x != 0 && x != 10000){
                vao[j] += 1;
                ra[i] += 1;
                edge.push_back({i, j, x});
            }
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
        for (int i = 0; i < m; i++){
            cout << edge[i].u << " " << edge[i].v << " " << edge[i].w << "\n";
        }
    }
    return 0;
}