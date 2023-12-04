#include <bits/stdc++.h>
#define fod(i,a,b) for(int i = a;i <= b; i++)
#define fok(i,a,b) for(int i = a;i >= b; i--)
#define ll long long
#define int long long
#define fi first
#define se second
#define name "FLIGHTS"
#define pb push_back
using namespace std;
typedef priority_queue<int, vector<int>, greater<int>> sus;
const int oo = 1000111000;
typedef pair<int, int> ii;
struct bg{
	int v, w, left;
};
const int base = 1e6 + 5;
const int N = 2e5 + 5;
int n, m, k, dis[N][101], dd[N][101];
vector <ii> adj[base];
struct cmph{
	bool operator() (bg a, bg b){
		return a.w > b.w;
	}
};
void djikstra(){
	priority_queue<bg, vector <bg>, cmph> pq;
	pq.push({1,0,k});
	dis[1][k] = 0;
	while(!pq.empty()){
        bg tp = pq.top(); pq.pop();
        int from = tp.v, kk = tp.left, dist = tp.w;
        if(dis[from][kk] < dist) continue;
        for(auto p : adj[from]){
            int to = p.fi, weight = p.se;
            if(dist + weight < dis[to][kk]){
                dis[to][kk] = dist + weight;
                pq.push({to,dis[to][kk], kk});
            }   
            if(kk > 0 and dist - weight < dis[to][kk-1]){
                dis[to][kk-1] = dist - weight;
                pq.push({to, dis[to][kk-1], kk-1});
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
	cin >> n >> m >> k;
	fod(i,1,m){
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].pb({v,w});
	}
	fod(i,1,n) fod(j,0,k) dis[i][j] = 1e18;
	djikstra();
	// fod(i,1,n){
	// 	fod(j,0,k) cout << dis[i][j] << " ";
	// 	cout << endl; 
	// }
	int res = 1e18;
	fod(j,0,k) res = min(res, dis[n][j]);
	cout << res;
	return 0;
}
