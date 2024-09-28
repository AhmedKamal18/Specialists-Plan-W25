#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll mod = 1e9 + 7;
int dp[10][2][300000][2];
void solve(){
    int le  , ri;
    cin >> le >> ri;
    le--;
    string l , r;
    l = to_string(le);
    r= to_string(ri);
    int k;
    cin >>k;
    while(l.size()<r.size()) l = '0' + l;
    memset(dp , -1  ,sizeof dp);
    auto go = [&](auto && go , int idx , int up  ,int lm,int f)->int{
        if (idx == r.size()) return lm == k;
        int &ret  =  dp[idx][up][lm][f];
        if (~ret) return ret;
        int ans = 0;
        int end = up ? r[idx] - '0' : 9;
        ret= 0;
        for (int i = 0 ;i<=end;i++){
            f|=i!=0;
            if (f && i == 0) continue;
            if (idx + 1!=r.size() && i)
                ret+=go(go , idx + 2 , up & (r[idx + 1  ] - '0' == 0)&(r[idx] - '0' == i) , lcm(lm ,f ? i*10 : 1) ,f);
            ret+=go(go , idx + 1 , up & (r[idx] - '0' == i) , lcm(lm ,f ? i : 1) ,f);
        }
        return ret;
    };
    ll x = go(go , 0 , 1  , 1 , 0);
    memset(dp ,- 1, sizeof dp);
    r = l;
    cout <<x -  go(go , 0 , 1  , 1 , 0);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    //cin >>t;
    while(t--)
        solve();
}