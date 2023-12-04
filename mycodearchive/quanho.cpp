#include <bits/stdc++.h>
#define fod(i,a,b) for(int i = a;i <= b; i++)
#define fok(i,a,b) for(int i = a;i >= b; i--)
#define ll long long
#define int long long
#define fi first
#define se second
#define name ""
#define pb push_back
using namespace std;
typedef pair<int,int> ii;
typedef priority_queue<int, vector<int>, greater<int>> sus;
const int oo = 1000111000;
const int base = 1e6 + 5;
struct bg{
	int v, val, cake;
}dis[base];
int n, a[base], dd[base], m;
vector <ii> adj[base];
struct cmp{
	bool operator() (bg a, bg b){
		if(a.val == b.val) return a.cake < b.cake;
		return a.val > b.val;
	}
};
void ditstra(){
	fod(i,1,n) dis[i].val = 1e18, dis[i].cake = -1e18;
	dis[1].val = 0;
	dis[1].cake = a[1];
	priority_queue <bg, vector<bg>, cmp> dq;
	dq.push({1,0,a[1]});
	while(!dq.empty()){
		bg t = dq.top(); dq.pop();
		int u = t.v, curw = t.val, curv = t.cake;
		if(dd[u]) continue;
		dd[u] = 1;
		for(auto edge : adj[u]){
			int v = edge.fi, w = edge.se;
			if(dis[v].val > curw + w){
				dis[v].val = curw + w;
				dis[v].cake = curv + a[v];
				dq.push({v,dis[v].val,dis[v].cake});
			}
			if(dis[v].val == curw + w and dis[v].cake < curv + a[v]){
				dis[v].cake = curv + a[v];
				dq.push({v,dis[v].val,dis[v].cake});
			}
		}
	}
}
signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(name".inp", "r")){
	    freopen(name".inp", "r", stdin);
	    freopen(name".out", "w", stdout);
	}
	cin >> n;
	fod(i,1,n) cin >> a[i];
	cin >> m;
	fod(i,1,m){
		int u, v, c; cin >> u >> v >> c;
		adj[u].pb({v,c});
		adj[v].pb({u,c});
	}
	ditstra();
	// fod(i,1,n){
	// 	cout << dis[i].val << " " << dis[i].cake << endl;
	// }
	if(dis[n].val >= 1e18) cout << "impossible";
	else cout << dis[n].val << " " << dis[n].cake;
	return 0;
}
