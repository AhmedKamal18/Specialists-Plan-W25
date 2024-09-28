#include <bits/stdc++.h>
 
#define all(a) begin(a), end(a)
#define sz(x) (int)(x).size()
 
using namespace std ;
using ll = long long;
 
const char nl = '\n', sp = ' ';
const int mod = 1e9 +7;
 
string s;
int n;
ll memo [2][2][10][19];
 
ll dp (int index , int allZeros , int previous , int restricted){
    if (index == n) return 1;
    ll &ret = memo[restricted][allZeros][previous][index];
    if (~ret) return ret;
    int upper_bound = restricted ? s[index] - '0' : 9;
    ret = 0;
    for (int digit = 0 ; digit <= upper_bound ; digit ++){
        if (previous > 0){
            if (digit != previous)
                ret += dp(index + 1 ,
                          allZeros && !digit ,
                          digit ,
                          restricted && (digit == upper_bound));
        } else {
            if (digit != previous)
                ret += dp(index + 1 ,
                          allZeros && !digit ,
                          digit ,
                          restricted && (digit == upper_bound));
            else if (allZeros)
                ret += dp(index + 1 ,
                          allZeros && !digit ,
                          digit ,
                          restricted && (digit == upper_bound));
        }
    }
    return ret;
}
 
ll calc (ll num){ // calculate the number of valid integers in the interval [0 , num]
    s = to_string(num);
    n = s.length();
    memset(memo , -1 , sizeof memo);
    return dp(0 , 1 , 0 , 1);
}
 
void solve(){
    ll a , b;
    cin >> a >> b;
    ll ans = calc(b);
    if (a){
        ans -= calc(a - 1);
    }
    cout << ans << nl;
}
 
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
