#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;

int n, s, t;
vector<vector<pair<int, int>>> a;
vector<int> parent;

void shortest_path(int dodai){
    if (dodai == INF){
        cout << 0;
    }
    else{
        vector<int> path;
        cout << dodai << "\n";
        while (t != s){
            path.push_back(t);
            t = parent[t];
        }
        path.push_back(s);
        for (int i = path.size() - 1; i >= 0; i--){
            cout << path[i] << " ";
        }
    }
}

void dijkstra(){
    vector<int> d(n + 1, INF);
    d[s] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, s}); // {khoang cach hien tai, dich nguon}
    while (!pq.empty()){
        pair<int, int> top = pq.top();
        pq.pop();
        int kc = top.first;
        int u = top.second;
        if (kc > d[u]){
            continue;
        }
        // relaxation
        for (auto it : a[u]){
            int v = it.first; // dinh dich
            int w = it.second; // khoang cach u-v
            if (d[v] > d[u] + w){
                d[v] = d[u] + w; // cap nhat khoang cach ngan hon
                pq.push({d[v], v});
                parent[v] = u;
            }
        }
    }
    shortest_path(d[t]);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("DN.INP", "r", stdin);
    freopen("DN.OUT", "w", stdout);
    cin >> n >> s >> t;
    a.resize(n + 1);
    parent.assign(n + 1, 0);
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            int x;
            cin >> x;
            if (x != 0 && x != 10000){
                a[i].push_back({j, x}); // {dinh dich, khoang cach u-v}
            }
        }
    }

    dijkstra();
    return 0;
}