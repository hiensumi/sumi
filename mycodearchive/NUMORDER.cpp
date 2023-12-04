#include <bits/stdc++.h>
#define fod(i,a,b) for(int i = a;i <= b; i++)
#define fok(i,a,b) for(int i = a;i >= b; i--)
#define ll long long
#define int long long
#define base 1000000+1
#define non 5000+1
#define pog 1000000000+7
#define pb push_back
#define name "KTHSUM"
//real ans = 3 5 7
using namespace std;
typedef priority_queue<int, vector<int>, greater<int>> sus;
const int oo = 1000111000;
const int N = 1e5;
typedef pair<int, int> ii;
int n, a[base], b[base],k, m;
bool check(int mid ,int id){
	int j = mid, s = 0;
	fod(i,1,n){
		int d = 1, c = m, ans = 0;
		while(d <= c){
			int mi = d + c >> 1;
			if(mi * mi + i * i < mid * mid + id * id) d = mi + 1, ans = mi;
			else c = mi - 1;
		}
		s += ans;
		if(s >= k) return 1;
	}
	return 0;
}
signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(".inp", "r")){
		freopen(".inp", "r", stdin);
	    freopen(".out", "w", stdout);
	}
	else if(fopen(name".inp", "r")){
	    freopen(name".inp", "r", stdin);
	    freopen(name".out", "w", stdout);
	}
	cin >> m >> n >> k;
	if(m < n) swap(m,n);
	fod(i,1,n){
		int d = 1, c = m, ans = 0;
		while(d <= c){
			int mid = d + c >> 1;
			if(check(mid,i)) c = mid - 1, ans = mid;
			else d = mid + 1;
		}
		if(ans != 0){
			cout << i * i + ans * ans << endl;
			// return 0;
		}
	}
	return 0;
}