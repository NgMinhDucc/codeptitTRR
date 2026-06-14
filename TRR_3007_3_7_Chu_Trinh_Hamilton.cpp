#include <bits/stdc++.h>
using namespace std;

int n, u;
vector<vector<int>> a;
vector<bool> visited;
vector<int> d;
vector<vector<int>> res;

void hamilton(int pos, int cur){
	if (pos == n){
		if (a[cur][u]){
			res.push_back(d);
		}
		return;
	}
	for (int i = 1; i <= n; i++){
		if (a[cur][i] && !visited[i]){
			visited[i] = true;
			d[pos + 1] = i;
			hamilton(pos + 1, i);
			visited[i] = false;
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("CT.INP", "r", stdin);
	freopen("CT.OUT", "w", stdout);

	cin >> n >> u;
	a.assign(n + 1, vector<int>(n + 1));
	visited.assign(n + 1, false);
	d.assign(n + 1, 0);
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++){
			cin >> a[i][j];
		}
	}
	d[1] = u;
	visited[u] = true;
	hamilton(1, u);
	if ((int)res.size() == 0){
		cout << 0;
	}
	else{
		for (int i = 0; i < (int)res.size(); i++){
			for (int j = 1; j <= n; j++){
				cout << res[i][j] << " ";
			}
			cout << u << endl;
		}
		cout << res.size();
	}
	return 0;
}