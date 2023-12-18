//Author: Oreo
#include<bits/stdc++.h>
#define int long long 
#define pb push_back
#define ndl "\n"
#define yes cout<<"YES\n"
#define no cout<<"NO\n"
#define mod (int)(1e9 + 7)
#define F first
#define S second
#define vi vector<int>
#define vc vector<char>
#define vpi vector<pair<int,int>>
#define pi pair<int,int>
#define mi map<int, int>
#define miv map<int,vector<int>>
using namespace std;

template<class T>
void inp(vector<T>&a){ for(auto &x : a)cin>>x; }

template<class T>
void print(vector<T>&a){
    for(auto &x: a)cout<<x<<" ";
    cout<<ndl;
}

template<class T>
void print(T x){cout<<x<<" ";}

template<class T>
void println(T x){ cout<<x<<"\n";}

template<class T>
T maxEle(vector<T>&a){
    T maxi = LLONG_MIN;
    for(auto x : a)
        if(x>maxi)maxi = x;
    return maxi;
}

template<class T>
T minEle(vector<T>&a){
    T mini = LLONG_MAX;
    for(auto x: a)
        if(x<mini) mini = x;
    return mini;
}

template<class T>
void sortAll(vector<T>&a){ sort(a.begin(), a.end());}

template<class T>
T sumAll(vector<T>&a){
    T sum = 0;
    for(auto x : a) sum +=x;
    return sum;
}

template<class T>
void revAll(vector<T>&a){reverse(a.begin(),a.end());}



///////////////////////////////////////////////////////////////////////////////////////////////////

int a, b, n;

bool isPos(vi & h, int op){
    
    int cnt = 0;
    for(int i = 0; i<n; i++){
        
        if(h[i]-op*b <= 0)continue;
        else cnt += (h[i]-op*b + a-b-1)/(a-b);
        if(cnt>op)return false;
    }
    return true;
}


int bs(int low, int high, vi& h){
    
    int ans = 0;
    
    while(low<=high){
       
       int mid =(low+high)>>1;
       if(isPos(h,mid)){
           high = mid - 1;
           ans = mid;
       }
       else{
           low = mid + 1;
       }
    }
    return ans;
}

void solve(){
    
    cin>>n>>a>>b;
    
    vi h(n); inp(h);
    
    cout<<bs(0,1e9,h)<<"\n";
    
}



///////////////////////////////////////////////////////////////////////////////////////////////////



signed main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int t = 1; //cin>>t;
    while(t--){
        solve();
    }
}