#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
int n;
vector<vector<int>> d, nxt;

void khoitao(){
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++){
			int x;
			cin >> x;
			// duong cheo chinh
			if (i == j){
				d[i][j] = 0;
				nxt[i][j] = i;
			}
			// co canh noi tu i -> j
			else if (x != 0 && x != 10000){
				d[i][j] = x;
				nxt[i][j] = j;
			}
			// khong co canh noi
			else{
				d[i][j] = INF;
				nxt[i][j] = -1;
			}
		}
	}
}

void floyd_warshall(){
	for (int k = 1; k <= n; k++){ // dinh trung gian
		for (int i = 1; i <= n; i++){ // dinh nguon
			for (int j = 1; j <= n; j++){ // dinh dich
				if (d[i][k] != INF && d[k][j] != INF && d[i][j] > d[i][k] + d[k][j]){
					d[i][j] = d[i][k] + d[k][j];
					nxt[i][j] = nxt[i][k];
				}
			}
		}
	}
}

void khoiphuc(){
	int maxx = -1, u = -1, v = -1;
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++){
			if (i != j && d[i][j] != INF && d[i][j] > maxx){
				maxx = d[i][j];
				u = i;
				v = j;
			}
		}
	}
	if (maxx == -1){
		cout << 0;
	}
	else{
		cout << u << " " << v << " " << maxx << endl;
		vector<int> d;
		int tmp = u;
		d.push_back(tmp);
		while (tmp != v){
			tmp = nxt[tmp][v];
			d.push_back(tmp);
		}
		for (int i : d){
			cout << i << " ";
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
	khoitao();
	floyd_warshall();
	khoiphuc();
	return 0;
}