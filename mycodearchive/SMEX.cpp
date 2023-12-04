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
const int base = 3e5 + 10;
const int LG = 17;
int n, a[base], mex = 1e18, f[base];
int st[LG + 1][base];
void preprocess(){
    for (int i = 1; i <= n; ++i) st[0][i] = abs(a[i]);
    for (int j = 1; j <= LG; ++j)
        for (int i = 1; i + (1 << j) - 1 <= n; ++i)
            st[j][i] = min(st[j - 1][i], st[j - 1][i + (1 << (j - 1))]);
}
int query(int l, int r) {
    int k = __lg(r - l + 1);
    return min(st[k][l], st[k][r - (1 << k) + 1]);
}
signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(name".inp", "r")){
	    freopen(name".inp", "r", stdin);
	    freopen(name".out", "w", stdout);
	}
	cin >> n;
	fod(i,1,n){
		cin >> a[i];
		if(a[i] >= 0) mex = min(mex, abs(a[i]));
	}
	preprocess();
	f[n+1] = 1;
	f[n] = 0;
	fok(i,n,1){
		fod(j,i+1,n){
			int me = query(i,j);
			// fod(k,i,j) me = min(me, abs(a[k]));
			if(me == mex) f[i] += f[j+1];
		}
	}
	// fod(i,1,n) cout << f[i] << " ";
	cout << f[1];
	return 0;
}
