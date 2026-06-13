#include <bits/stdc++.h>
using namespace std;

struct edge{
    int u, v, w;
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("DT.INP", "r", stdin);
    freopen("DT.OUT", "w", stdout);

    int t, n;
    cin >> t >> n;
    vector<int> bac(n + 1, 0);
    vector<edge> canh;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            int x;
            cin >> x;
            if (x != 10000 && x != 0){
                bac[i] += 1;
                if (i < j){
                    canh.push_back({i, j, x});
                }
            }
        }
    }
    if (t == 1){
        for (int i = 1; i <= n; i++){
            cout << bac[i] << " ";
        }
    }
    if (t == 2){
        int m = canh.size();
        cout << n << " " << m << endl;
        for (int i = 0; i < m; i++){
            cout << canh[i].u << " " << canh[i].v << " " << canh[i].w << endl;
        }
    }
    return 0;
}