#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    // freopen("DT.INP", "r", stdin);
    // freopen("DT.OUT", "w", stdout);

    int t, n;
    cin >> t >> n;
    vector<vector<int>> a(n + 1, vector<int>(n + 1, 0));
    int m = 0;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            int x;
            cin >> x;
            if (x != 0 && x != 10000 && i < j){
                m += 1;
                a[i][j] = a[j][i] = x;
            }
        }
    }

    if (t == 1){
        for (int i = 1; i <= n; i++){
            int deg = 0;
            for (int j = 1; j <= n; j++){
                if (a[i][j]){
                    deg += 1;
                }
            }
            cout << deg << " ";
        }
    }
    if (t == 2){
        cout << n << " " << m << "\n";
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= n; j++){
                if (a[i][j] && i < j){
                    cout << i << " " << j << " " << a[i][j] << "\n";
                }
            }
        }
    }
    return 0;
}