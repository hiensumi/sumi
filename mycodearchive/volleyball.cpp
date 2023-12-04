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
typedef priority_queue<int, vector<int>, greater<int>> sus;
const int oo = 1000111000;
typedef pair<int, int> ii;
struct point{
	int x, y;
};
struct edge{
	int u, v;
    vector<int> par;
    void init(int n) {
        par.resize(n + 5, 0);
        fod(i,1,n) par[i] = i;
    }
    int find(int u) {
        if (par[u] == u) return u;
        return par[u] = find(par[u]);
    }
    bool join(int u, int v) {
        int paru = find(u), parv = find(v);
        if (paru == parv) return false;
        par[parv] = paru;
        return true;
    }	
};
const int base = 1e6 + 5;
int  t;
signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(name".inp", "r")){
	    freopen(name".inp", "r", stdin);
	    freopen(name".out", "w", stdout);
	}
	cin >> t;
	while(t--){
		int k, x, y; cin >> k >> x >> y;
		int mi = min(x,y), ma = max(x,y);
		if(ma >= k){
			// ma - mi >= 2;
			if(ma - mi >= 2){
				cout << 0 << " ";
				continue;
			}else{
				int diff = ma - mi;
				cout << abs(2 - diff) << " ";
				continue;
			}
		}else{
			int res = k - ma;
			ma = k;
			if(ma - mi >= 2){
				cout << res << " ";
				continue;
			}else{
				int diff = ma - mi;
				cout << res + abs(2 - diff) << " ";
				continue;
			}
		}
	}
	return 0;
}
