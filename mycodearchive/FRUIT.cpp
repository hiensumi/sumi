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
int n, a,b, c[base];
signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(name".inp", "r")){
	    freopen(name".inp", "r", stdin);
	    freopen(name".out", "w", stdout);
	}
	cin >> n >> a >> b;
	fod(i,1,n) cin >> c[i];
	for(int i = 1; i <= n ; i ++){
		if(i & 1) a -= c[i];
		else b -= c[i];
		if(a <= 0 and b >= 0){
			int s = b;         
			fod(j,i+1,n) s -= c[j];
			if(s >= 0){
				cout << "NO";
				return 0;
			}
		}
	}
	cout << "YES"; 
	return 0;
}
