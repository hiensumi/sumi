// Q: 
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef vector<int> vii;
typedef vector<ll> vll;
typedef long double ld;
 
#define fi first
#define se second
#define pb push_back
#define mp make_pair
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    int t; cin >> t;
    while(t--)
    {
        ll a, b; cin >> a >> b;
        while(b != 0)
        {
            ll gcd = __gcd(a, b);
            if(gcd == 1) break;
            b /= gcd;
        }
        if(b == 1) cout <<"Yes\n";
        else cout << "No\n";
    }
    
    return 0;
}