#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;

struct edge{
    int u, v, w;
};

int n, s, t;
vector<edge> a;
vector<int> parent;

void shortest_path(int dodai){
    if (dodai == INF){
        cout << 0;
    }
    else{
        vector<int> path;
        while (t != s){
            path.push_back(t);
            t = parent[t];
        }
        path.push_back(s);

        cout << dodai << "\n";
        for (int i = path.size() - 1; i >= 0; i--){
            cout << path[i] << " ";
        }
    }
}

void bellmanford(){
    vector<int> d(n + 1, INF);
    d[s] = 0;
    // mac dinh lap n - 1 lan
    for (int i = 1; i < n; i++){
        for (edge e : a){
            int u = e.u, v = e.v, w = e.w;
            if (d[u] != INF && d[v] > d[u] + w){
                d[v] = d[u] + w;
                parent[v] = u;
            }
        }
    }
    // lap lan thu n de kiem tra chu trinh am
    bool neg = false;
    for (edge e : a){
        int u = e.u, v = e.v, w = e.w;
        if (d[u] != INF && d[v] > d[u] + w){
            d[v] = d[u] + w;
            neg = true;
            break;
        }
    }
    if (!neg){
        shortest_path(d[t]);
    }
    else{
        cout << -1;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("BN.INP", "r", stdin);
    freopen("BN.OUT", "w", stdout);

    cin >> n >> s >> t;
    parent.assign(n + 1, 0);
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            int x;
            cin >> x;
            if (x != 0 && x != 10000){
                a.push_back({i, j, x});
            }
        }
    }

    bellmanford();
    return 0;
}