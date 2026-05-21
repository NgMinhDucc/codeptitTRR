#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;

int n;
vector<vector<int>> d;
vector<vector<int>> nxt;

void floyd(){
    for (int k = 1; k <= n; k++){ // dinh trung gian
        for (int i = 1; i <= n; i++){ // dinh nguon
            for (int j = 1; j <= n; j++){ // dinh tiep theo
                if (d[i][k] != INF && d[k][j] != INF && d[i][j] > d[i][k] + d[k][j]){
                    d[i][j] = d[i][k] + d[k][j];
                    nxt[i][j] = nxt[i][k];
                }
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("DN.INP", "r", stdin);
    freopen("DN.OUT", "w", stdout);

    cin >> n;
    d.assign(n + 1, vector<int>(n + 1));
    nxt.assign(n + 1, vector<int>(n + 1));
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            int x;
            cin >> x;
            if (i == j){
                d[i][j] = 0; // khoang cach tu 1 dinh toi chinh no = 0
                nxt[i][j] = i;
            }
            else if (x != 0 && x != 10000){
                d[i][j] = x; // co canh noi
                nxt[i][j] = j; // dinh tiep theo
            }
            else{
                d[i][j] = INF; // khong co canh noi
                nxt[i][j] = -1;
            }
        }
    }
    floyd();
    int maxx = -1, u = -1, v = -1;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            if (d[i][j] != INF && i != j){
                if (maxx < d[i][j]){
                    maxx = d[i][j];
                    u = i;
                    v = j;
                }
                else if (d[i][j] == maxx){
                    if (i < u || (i == u && j < v)){
                        u = i;
                        v = j;
                    }
                }
            }
        }
    }
    if (maxx == -1){
        cout << 0;
        return 0;
    }
    cout << u << " " << v << " " << maxx << "\n";
    int tmp = u;
    while (tmp != v){
        cout << tmp << " ";
        tmp = nxt[tmp][v];
    }
    cout << v << " ";
    return 0;
}