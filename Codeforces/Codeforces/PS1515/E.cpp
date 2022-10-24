/*#include <bits/stdc++.h>

#define f first
#define s second
#define mp make_pair
#define pb push_back
#define p push
#define fr front
#define H 100010

using namespace std;
typedef long long int LL;

LL N,M;
LL B[401][401];
LL DP[401][401];
LL E[401];
int main() {
    cin >> N >> M;
    for (int i = 0; i < 401; i++) {
        E[i]=i?((E[i-1]*2)%M):1;
        for (int j = 0; j <= i; j++) {
            B[i][j]=(j*(i-j))?((B[i-1][j]+B[i-1][j-1])%M):1;
            DP[i][j]=0;
        }
        if(i>0)DP[i][i]=E[i-1];
    }
    for (int i = 1; i < 401; i++) {
        for (int j = i/2+1; j < i; j++) {
            for (int k = 1; k < j; k++) {
                //cout << "\t" << i << " " << j << " " << k << " "
                //    << E[k-1] << " " << B[j][k] << " " << DP[i-k-1][j-k]
                //    << endl;
                DP[i][j]+=(((E[k-1]*B[j][k])%M)*DP[i-k-1][j-k])%M;
            }
            DP[i][j]%=M;
        }
    }
    LL ret = 0;
    for (int j = 0; j < 401; j++) {
        ret += DP[N][j];
    }
    cout << ret%M << endl;
}
*/
