//لعمرك ما أمرى على بغمة    نهارى و لا ليلى على بسرمد

#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

const char nl = '\n';
const ll mod = 1e9+7;

string K;
int D;

int dp[2][100][10001];

int calc_iter(){
    dp[1][0][0] = 1;
    for(int i=0;i<K.size();i++){
        for(int j=0;j<D;j++){
            for(int bound=0;bound<2;bound++){
                for(int digit=0;digit<10;digit++){
                    if(K[i]-'0'<digit && bound)break;
                    if(K[i]-'0'>digit){
                        dp[0][(j+digit)%D][i+1] += dp[bound][j][i];
                        dp[0][(j+digit)%D][i+1]%=mod;
                    }
                    else {
                        dp[bound][(j+digit)%D][i+1] += dp[bound][j][i];
                        dp[bound][(j+digit)%D][i+1]%=mod;
                    }
                }
            }
        }
    }
    return (dp[0][0][K.size()]+dp[1][0][K.size()])%mod;
}

void solve(){
    cin >> K >> D;
    cout << (calc_iter() -1 + mod) % mod << nl;
}
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
