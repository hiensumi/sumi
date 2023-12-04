#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
    #define int long long int
	int t;
	cin>>t;
	while(t--)
	{
	    string l,r;
	    cin>>l>>r;
	    int ans=0;
	    int upperlim=0;
	    int lowerlim=0;
	    int check=0;
	    if(l.size()<r.size())
	    {
	        upperlim=pow(10,l.size())-1;
	        lowerlim=pow(10,r.size()-1);
	        check=pow(10,l.size());
	    }
	    if(ans==0)
	    {
	        ans=(upperlim-stoi(l)+1)*(stoi(l)+upperlim);
	        ans=ans/2;
	        ans=ans*l.size();
	        ans=ans+(((stoi(r)-lowerlim +1)*(stoi(r)+lowerlim))/2)*r.size();
	        int h=lowerlim/check;
	        while(check<lowerlim)
	        {
	            ans=ans+((((check*10)-1)-check +1)*(check+((check*10)-1))/2)*to_string(check).size();
	            
	            check=check*10;
	        }
	        
	    }
	    ans=ans%1000000007;
	    cout<<ans<<endl;;
	}
	return 0;
}













































