#include <bits/stdc++.h>
#define fod(i,a,b) for(int i = a;i <= b; i++)
#define fok(i,a,b) for(int i = a;i >= b; i--)
#define ll long long
#define int long long
#define base 1000000+5
#define name ""
#define non 5000+1
#define pog 1000000000+7
#define pb push_back
using namespace std;
typedef priority_queue<int, vector<int>, greater<int>> sus;
const int oo =  1000111000;
typedef pair<int, int> ii;
struct point{
	int x, y;
};
int f[base], n, a[21][21];
// gọi f[x] là tổng giá trị thẩm mỹ lớn nhất khi xếp tới trạng thái x và có số hàng bằng số lượng bit 1 thuộc x
// bit thứ i = 1 suy ra người thứ i đã được xếp vào hàng
int cal(int x){
	int k = __builtin_popcount(x);
	if(k == n) return 0;
	if(f[x] != -1e18) return f[x];
	int best = -1e18;
	fod(i,1,n){
		//kiem tra trang thai cua bit thu i
		int tt = (x & (1 << (i - 1)));
		if(tt == 0){ //neu chua bat
			int tmp = a[i][k+1] + cal(x ^ (1 << (i -1)));
			// a[i][k+1]: gia tri tham my khi xep nguoi i vao hang k + 1
			// cal(x ^ (1 << i - 1)): gia tri cua trang thai p khi nguoi thu i duoc xep vao hang 
			best = max(best, tmp);
		}
	}
	return f[x] = best;
}
// void solve()
signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(name".inp", "r")){
	    freopen(name".inp", "r", stdin);
	    freopen(name".out", "w", stdout);
	}
	cin >> n;
	fod(i,1,n) fod(j,1,n) cin >> a[i][j];
	fod(i,0,1 << n ) f[i] = -1e18;
	cout << cal(0);
	return 0;
}