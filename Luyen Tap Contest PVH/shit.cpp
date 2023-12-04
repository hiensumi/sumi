#include<bits/stdc++.h>
using namespace std;
int cnt,n,k,kt,res,a[200000+5],c[200000+5];
void doc(){
	cin>>n>>k;
	 cnt=0;
	 int x;
	for(int i=1;i<=n;i++){
		cin>>x;
		if(x<0){
			cnt++;
			a[cnt]=i;
			kt=i;
		}
	}	
}
bool cmp(int u,int v){
	return u<v;
}
void xuly(){
	a[0]=1;
	if(k<cnt){
		cout<<-1;
		return;
	}
	if(cnt==0){
		cout<<cnt;
		return;
	}
	if(cnt<=k){
		int k1=k-cnt;
		res=2*cnt;
		for(int i=1;i<=cnt-1;i++) c[i]=(a[i+1]-a[i])-1;
		sort(c+1,c+cnt,cmp);
		for(int i=1;i<=cnt-1;i++){
			if(k1>=c[i]){
				res-=2;
				k1-=c[i];
			}
		}
		if(k1>=n-kt) res--;
		cout<<res;
	}
	
}
int main(){
//	freopen("WOMAN.INP","r",stdin);
//	freopen("WOMAN.OUT","w",stdout);
	ios_base :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	doc();
	xuly(); 
	return 0;
}
