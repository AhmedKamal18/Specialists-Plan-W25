#include <bits/stdc++.h>

#define all(a) begin(a), end(a)
#define sz(x) (int)(x).size()

using namespace std ;
using ll = long long;

const char nl = '\n', sp = ' ';
const int mod = 1e9 +7;

int mul (int a , int b){
    return (1ll * a * b) % mod;
}

int add (int a , int b){
    return (0ll + a + b) % mod;
}

int bin_pow (int a , int b){
    int res = 1;
    for ( ; b ; b >>= 1 , a = mul(a,a))
        if (b &1) res = mul(res , a);
    return res;
}

int mod_inv (int a){
    return bin_pow(a , mod -2);
}

int l [3] , r [3];
int memo [8][8][31];

int dp (int md , int mu , int i){
    if (i == -1) return 1;
    int &ret = memo[md][mu][i];
    if (~ret) return ret;
    int d [3] , u [3] , lb [3] , ub [3] , v [3];
    for (int j = 0 ; j < 3 ; j ++){
        d[j] = (md >> j) & 1;
        u[j] = (mu >> j) & 1;
        lb[j] = d[j] ? (l[j] >> i) &1 : 0;
        ub[j] = u[j] ? (r[j] >> i) &1 : 1;
    }
    ret = 0;
    for (v[0] = lb[0] ; v[0] <= ub[0] ; v[0] ++){
        for (v[1] = lb[1] ; v[1] <= ub[1] ; v[1] ++){
            for (v[2] = lb[2] ; v[2] <= ub[2] ; v[2] ++){
                if (v[0] ^ v[1] ^ v[2]) continue;
                int nmd = 0 , nmu = 0;
                for (int j = 0 ; j < 3 ; j ++){
                    nmd += (d[j] && (v[j] == lb[j])) << j;
                    nmu += (u[j] && (v[j] == ub[j])) << j;
                }
                ret = add(ret , dp (nmd ,nmu , i - 1));
            }
        }
    }
    return ret;
}

void solve(){
    for (int i = 0 ; i < 3 ; i ++) cin >> l[i] >> r[i];
    int res = 1;
    for (int i = 0 ; i < 3 ; i ++) res = mul(res , r[i] - l[i] +1);
    memset(memo , -1 , sizeof memo);
    int a = dp(7 , 7 , 30);
    res = mul(add(res , mod -a) , mod_inv(res));
    cout << res << nl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}