#include<bits/stdc++.h>
using namespace std;

string s;
stack<char> S;
int main(){
    cin>>s;
    int ans = 0;
    for(int i=0;i<s.size();i++){
        if(s[i]==']'){
            if(S.size()==0)return puts("Impossible");
            if(S.top()=='[')
                S.pop();
            else{
                ans++;
                S.pop();
            }
        }
        else if(s[i]==')'){
            if(S.size()==0)return puts("Impossible");
             if(S.top()=='(')
                S.pop();
            else{
                ans++;
                S.pop();
            }
        }
        else if(s[i]=='>'){
            if(S.size()==0)return puts("Impossible");
            if(S.top()=='<')
                S.pop();
            else{
                ans++;
                S.pop();
            }
        }
        else if(s[i]=='}'){
            if(S.size()==0)return puts("Impossible");
             if(S.top()=='{')
                S.pop();
            else{
                ans++;
                S.pop();
            }
        }
        else S.push(s[i]);
    }
    if(S.size()!=0)return puts("Impossible");
    cout<<ans<<endl;
}
