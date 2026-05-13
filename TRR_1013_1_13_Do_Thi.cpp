#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    // freopen("DT.INP", "r", stdin);
    // freopen("DT.OUT", "w", stdout);

    int t, n;
    cin >> t >> n;
    vector<vector<int>> dinhke(n + 1);
    vector<int> vao(n + 1, 0);
    vector<int> ra(n + 1, 0);
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            int x;
            cin >> x;
            if (x == 1){
                vao[i] += 1;
                ra[j] += 1;
                dinhke[i].push_back(j);
            }
        }
    }

    if (t == 1){
        for (int i = 1; i <= n; i++){
            cout << ra[i] << " " << vao[i] << "\n";
        }
    }
    if (t == 2){
        cout << n << "\n";
        for (int i = 1; i < (int)dinhke.size(); i++){
            cout << dinhke[i].size() << " ";
            for (int j : dinhke[i]){
                cout << j << " ";
            }
            cout << "\n";
        }
    }
    
    return 0;
}