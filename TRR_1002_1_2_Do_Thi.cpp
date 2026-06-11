#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("DT.INP", "r", stdin);
    freopen("DT.OUT", "w", stdout);

    int t, n;
    cin >> t >> n;
    vector<int> deg(n + 1);
    vector<vector<int>> a(n + 1);
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            int x;
            cin >> x;
            if (x == 1){
                if (i < j){
                    a[i].push_back(j);
                    a[j].push_back(i);
                }
                deg[i] += 1;
            }
        }
    }
    if (t == 1){
        for (int i = 1; i <= n; i++){
            cout << deg[i] << " ";
        }
    }
    if (t == 2){
        cout << n << endl;
        for (int i = 1; i <= n; i++){
            cout << a[i].size() << " ";
            for (int j = 0; j < (int)a[i].size(); j++){
                cout << a[i][j] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}