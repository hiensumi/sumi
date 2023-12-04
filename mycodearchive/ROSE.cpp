#include <bits/stdc++.h>
#define fod(i,a,b) for(int i = a;i <= b; i++)
#define fok(i,a,b) for(int i = a;i >= b; i--)
#define ll long long
#define int long long
#define fi first
#define se second
#define name "ROSE"
#define pb push_back
using namespace std;
typedef priority_queue<int, vector<int>, greater<int>> sus;
const int oo = 1000111000;
typedef pair<int, int> ii;
const int base = 1e6 + 5;
int n, q, a[base], t[base];
signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(name".inp", "r")){
	    freopen(name".inp", "r", stdin);
	    freopen(name".out", "w", stdout);
	}
	// cin >> n >> q;
	// fod(i,1,n) cin >> a[i];
	// fod(i,1,n) t[i] = -1;
	// fod(i,1,q){
	// 	int l, r, s;
	// 	cin >> l >> r >> s;
	// 	fod(j,l,r){
	// 		if(a[j] > 0) a[j] -= s;
	// 		if(t[j] == -1 and a[j] <= 0) t[j] = i;
	// 	}
	// }
	// fod(i,1,n){
	// 	int ma = -1, maa = 0;
	// 	for(int j = i; j <= n; j += i){
	// 		ma = max(ma, t[j]), maa = max(maa, a[j]);
	// 		if(maa > 0) break;
	// 		// cout << j << " " << a[j] << endl;
	// 	}
	// 	if(maa <= 0) cout << ma << " ";
	// 	else cout << -1 << " ";
	// }
	// int n = 5;
	// cout << (1 << n);
	return 0;
}
