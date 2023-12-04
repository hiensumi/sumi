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
	int n, q, a[base], f[base];
	void sub(int l, int r){
		int res = -1e18;
		int x, y ;  
		deque <int> dq; 
		fod(i,l,n){
			while(!dq.empty() and dq.front() < i-r) dq.pop_front();
			while(!dq.empty() && f[dq.back()] >= f[i-l]) dq.pop_back() ; 
			dq.pb(i-l);
			if(res < f[i] - f[dq.front()]){
				res = f[i] - f[dq.front()];
				x = dq.front() + 1;
				y = i;
			}
		}
		cout << res << endl;
		cout << x << " " << y << endl;
	}
	signed main(){
		ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
		if(fopen(name".inp", "r")){
		    freopen(name".inp", "r", stdin);
		    freopen(name".out", "w", stdout);
		}
		cin >> n >> q;
		fod(i,1,n) cin >> a[i], f[i] = f[i-1] + a[i];
		fod(i,1,q){
			int l, r; cin >> l >> r;
			sub(l,r);
		}
		return 0;
	}
