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
int n, m, a[base];
signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(name".inp", "r")){
	    freopen(name".inp", "r", stdin);
	    freopen(name".out", "w", stdout);
	}
	cin >> n >> m;
	fod(i,1,n) cin >> a[i];
	sort(a+1,a+n+1);
	if(a[1] > m){
		cout << 0;
		return 0;
	}
	int size = n;
	a[n+1] = 1e18;
	while(a[size] > m) size--;
	// cout << size << endl;
	if(a[size+1] <= m) size++;
	int gs = 0;
	stack <int> st;
	st.push(a[size]);
	fok(i,size-1,1){
		if(a[i] + st.top() > m) st.push(a[i]);
		else{
			gs++;
			st.pop();
		}
	}
	cout << gs + st.size();
	return 0;
}
