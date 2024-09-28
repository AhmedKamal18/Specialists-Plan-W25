#include <bits/stdc++.h>

#define all(a) begin(a), end(a)
#define sz(x) (int)(x).size()

using namespace std ;
using ll = long long;

const char nl = '\n', sp = ' ';
const int mod = 998244353;

string s; int n , k;
ll memo1 [2][2][18][1 << 10];
ll memo2 [2][2][18][1 << 10];

int add (ll a , ll b){
    return ((a % mod) + (b % mod)) % mod;
}

int mul (ll a , ll b){
    return ((a % mod) * (b % mod)) % mod;
}

ll dp1 (int , int , int , int);
ll dp2 (int , int , int , int);

ll dp1 (int rs , int allZero , int index , int mask){ // count
    if (index == n) return __popcount(mask) <= k;
    ll &ret = memo1[rs][allZero][index][mask];
    if (~ret) return ret;
    int ub = rs ? s[index] - '0' : 9;
    ret = dp1(rs && (ub == 0) , allZero , index +1 , mask | (!allZero));
    for (int d = 1 ; d <= ub ; d ++){
        ret += dp1(rs && (ub == d) , 0 , index +1 , mask | (1 << d));
        if (ret >= mod) ret -= mod;
    }
    return ret;
}

ll dp2 (int rs , int allZero , int index , int mask){ // sum
    if (index == n) return 0;
    ll &ret = memo2[rs][allZero][index][mask];
    if (~ret) return ret;
    int ub = rs ? s[index] - '0' : 9;
    ret = dp2(rs && (ub == 0) , allZero , index +1 , mask | (!allZero));
    for (int d = 1 ; d <= ub ; d ++){
        ll cnt = dp1(rs && (ub == d), 0,
                     index +1 ,mask | (1 << d));
        ll cur = mul (d * pow(10ll , n - index -1),cnt);
        ll nxt = dp2 (rs && (ub == d) , 0 ,
                      index +1 , mask | (1 << d));
        ret = add (ret , add (nxt , cur));
    }
    return ret;
}

ll calc(ll num){
    s = to_string(num);
    n = s.length();
    memset(memo1 , -1 , sizeof memo1);
    memset(memo2 , -1 , sizeof memo2);
    ll ans = dp2(1 , 1 , 0 , 0);
    return ans;
}

void solve(){
    ll a , b;
    cin >> a >> b >> k;
    ll ans = calc(b);
    if (a) ans -= calc(a -1);
    if (ans < 0) ans += mod;
    cout << ans << nl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}