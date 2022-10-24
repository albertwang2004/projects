/*#include <bits/stdc++.h>
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define p push
#define ins insert
#define t top
#define fr front
#define H 101
#define MOD 1000000007
#define INF 9999999999

using namespace std;
typedef long long int LL;
typedef pair<float,float> pii;

int T, N, M;
vector<pii> G;
// gcd

float DP[H][H][10001];

void out(float f) {
    cout << setprecision(9) << f << " ";
}

int main() {
    //scanf("%d",&T);
    T=1;

    while (T--) {
        scanf("%d",&N);
        float ret = 0.0;
        G.pb(mp(69,420));
        for (int i = 1; i <= N; i++) {
            int x,y; scanf("%d%d",&x,&y);
            G.pb(mp(x,y));
            ret += (float)y;
        }
        ret /= 2.0;
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < H; j++) {
                for (int k = 0; k <= 10000; k++) {
                    DP[i][j][k]=-1;
                }
            }
        }
        DP[0][0][0]=0;
        for (int i = 1; i <= N; i++) {
            for (int j = 0; j <= N; j++) {
                for (int k = 10000; k >= 0; k--) {
                    if (j==0) DP[i][j][k] = DP[i-1][j][k];
                    else if (k<(int)G[i].f) DP[i][j][k]=DP[i-1][j][k];
                    else {
                        if (DP[i-1][j-1][k-(int)G[i].f]==-1) DP[i][j][k]=DP[i-1][j][k];
                    else DP[i][j][k]=max(DP[i-1][j][k],DP[i-1][j-1][k-(int)G[i].f]+G[i].s);
                   //if (DP[i][j][k]>0) cout << i << " " << j << " " << k << " " << DP[i][j][k] << endl;;
                    }
                }
            }
        }
        for (int j = 1; j <= N; j++) {
            float ans = 0.0;
            for (int k = 0; k <= 10000; k++) {
                if (DP[N][j][k]>=0)
                ans = max((float)ans,min((float)k,DP[N][j][k]/2.0f + ret));
               //if (DP[N][j][k]>0) cout << j << " " << k << " " << DP[N][j][k] << " " << DP[N][j][k]/2.0f + ret << " " << ans << endl;;
            }
            out(ans);
            //cout << endl;
        }
        cout << endl;
    }
    return 0;
}
*/
