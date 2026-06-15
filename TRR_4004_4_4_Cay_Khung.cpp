#include <bits/stdc++.h>
using namespace std;

struct edge{
	int u, v, w;
};

int n, s;
vector<vector<pair<int, int>>> a;
vector<bool> visited;

void prim(){
	vector<edge> mst;
	int d = 0; // tong trong so
	visited[s] = true;
	while ((int)mst.size() < n - 1){
		int minw = 1e9;
		int x, y;
		for (int i = 1; i <= n; i++){
			if (visited[i]){ // duyet cac dinh ke cua dinh i
				for (auto it : a[i]){
					int v = it.first, w = it.second;
					if (!visited[v] && w < minw){
						minw = w;
						x = v;
						y = i;
					}
				}
			}
		}
		mst.push_back({x, y, minw});
		d += minw;
		visited[x] = true;
	}
	cout << d << "\n";
	for (edge e : mst){
		cout << min(e.u, e.v) << " " << max(e.u, e.v) << " " << e.w << "\n";
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("CK.INP", "r", stdin);
	freopen("CK.OUT", "w", stdout);

	cin >> n >> s;
	a.resize(n + 1);
	visited.assign(n + 1, false);
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++){
			int x;
			cin >> x;
			if (i < j && x != 0 && x != 10000){
				a[i].push_back({j, x});
				a[j].push_back({i, x});
			}
		}
	}
	prim();
	return 0;
}