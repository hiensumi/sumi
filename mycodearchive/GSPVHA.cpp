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
const int base = 1e6 + 5;
int r, c, a[105][105];
signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(name".inp", "r")){
	    freopen(name".inp", "r", stdin);
	    freopen(name".out", "w", stdout);
	}
	cin >> r >> c;
	fod(i,1,r) fod(j,1,c){
		char ch; cin >> ch;
		a[i][j] = (ch == '.');
	}
	ii res = {1e18,1e18};
	fod(i,1,r){
		fod(j,1,c-2){
			int d = 0;
			fod(k,j,j+2){
				d += a[i][k];
			}
			if(d == 3){
				if(res.fi > i) res = {i,j};
				if(res.se > j and res.fi == i) res = {i,j};
			}
		}
	}
	cout << res.fi << " " << res.se;
	return 0;
}
