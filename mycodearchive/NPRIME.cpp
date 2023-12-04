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
int find(int n){
	fod(i,2,sqrt(n)){
		if(n % i == 0){
			return i;
		}
	}
}
signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(name".inp", "r")){
	    freopen(name".inp", "r", stdin);
	    freopen(name".out", "w", stdout);
	}
	int q; cin >> q;
	while(q--){
		int n; cin >> n;
		int x = find(n);
		if(n % (x * x) == 0 and x * x != n){
			int mi = x, ma = n/(x*x);
			cout << mi << " " << ma << endl;
		}
		else{
			int mi = x, ma = sqrt(n/x);
			cout << ma << " " << mi << endl;
		}
	}
	return 0;
}