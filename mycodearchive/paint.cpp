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
int a1, a2, b1, b2;
signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(name".inp", "r")){
	    freopen(name".inp", "r", stdin);
	    freopen(name".out", "w", stdout);
	}
	cin >> a1 >> a2 >> b1 >> b2;
	if(a1 > a2) swap(a1,a2);
	if(b1 > b2) swap(b1,b2);
	if(a1 > b1){
		swap(a1,b1);
		swap(a2,b2);
	}
	if(a1 <= b1 and b2 <= a2){
		cout << a2 - a1;
	}
	else if(a1 <= b1 and b1 <= a2){
		cout << b2 - a1;
	}
	else{
		cout << a2 - a1 + b2 - b1;
	}
	return 0;
}
