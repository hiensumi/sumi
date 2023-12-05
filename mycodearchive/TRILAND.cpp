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
const int oo = 1000111000;
typedef pair<int, int> ii;
struct bg{
	int x,y;
}p[base], h[base];
ll CCW(bg A,bg B,bg C){
	ll k=(B.x-A.x)*(C.y-B.y)-(C.x-B.x)*(B.y-A.y);
	if(k==0) return 0;
	if(k>0) return 1;
	return -1;
}
int n;
int kc(bg a, bg b){
	return pow(a.x - b.x, 2) + pow(a.y - b.y, 2);
}
bool cmp(bg x, bg y){
	if(y.y == x.y) return x.x < y.x;
	return x.y < y.y;
}
bg p1;
bool cmp1(bg x, bg y){
	if(CCW(p1,x,y) == 0) return kc(p1,x) < kc(p1,y);
	return CCW(p1, x,y) > 0;
}
ll DTTG(bg a, bg b, bg c){
	// 2 lan dien tich
	return abs( (b.x - a.x)*(c.y - a.y) - (c.x - a.x)*(b.y - a.y));
}
string dientich(int m){
	int s = 0;
	// sort(h+1,h+m+1,cmp1);
	// int j = 2, k = 3;
	fod(i,1,m-2){
		int k = i + 2;
		fod(j,i+1,m-1){
			int res = DTTG(h[i], h[j], h[k]);
			while(j < k and k <= m and  DTTG(h[i], h[j], h[k]) < DTTG(h[i], h[j], h[k+1])){
				res = DTTG(h[i], h[j], h[k+1]);
				k++;
			}
			s = max(s, res);
		}
	}
	// sort(h+1,h+m+1,cmp1);
	// s = max(s, DTTG(h[m-2], h[m-1], h[m]));
	// s = abs(s);
	// fod(i,1,m-2) fod(j,i+1,m-1) s = max(s, DTTG(h[m], h[i],h[j]));
	// fod(i,2,m-1) fod(j,i+1,m) s = max(s, DTTG(h[1], h[i],h[j]));
	if(s % 2 == 0) return to_string(s/2) + ".0";
	else return to_string(s/2) + ".5";
}
signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(name".inp", "r")){
	    freopen(name".inp", "r", stdin);
	    freopen(name".out", "w", stdout);
	}
	while(1){
	    cin >> n;
	    if(n == -1) break;
    	fod(i,1,n) cin >> p[i].x >> p[i].y;
    	sort(p+1,p+n+1,cmp);
    	p[n+1] = p[1];
    	p1 = p[1];
    	sort(p+2,p+n+1,cmp1);
    	h[1] = p[1]; h[2] = p[2];
    	int m = 2;
    	fod(i,3,n+1){
    		while(m >= 2 and CCW(h[m-1],h[m],p[i]) <= 0) m--;
    		m++; h[m] = p[i];
    	}
    	m--;
    	// cout << m << endl;
    	cout << dientich(m) << endl;
	}
	// fod(i,1,m) cout << h[i].x << " " << h[i].y << endl;
	return 0;
}
