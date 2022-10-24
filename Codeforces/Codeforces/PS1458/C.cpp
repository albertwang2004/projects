/*#include <bits/stdc++.h>
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define p push
#define ins insert
#define t top
#define fr front
#define H 1010
#define MOD 1000000007
#define INF 9999999999

using namespace std;
typedef long long int LL;

int T,N,M;
vector<vector<int>> A;
int ans[H][H];

int main() {
    scanf("%d",&T);
    //T=1;
    while (T--) {
        scanf("%d%d",&N,&M);
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                int X; scanf("%d", &X);
                vector<int> asdf;
                asdf.pb(i);asdf.pb(j);asdf.pb(--X);
                A.pb(asdf);
            }
        }
        char buf[M];
        scanf("%s",buf);
        int a0 = 0;
        int a1 = 1;
        int a2 = 2;
        int tx = 0;
        int ty = 0;
        int tz = 0;
        int* TX = &tx;
        int* TY = &ty;
        int* TZ = &tz;
        for (int i = 0; i < M; i++) {
            if (buf[i]=='D') ++*TX;
            else if (buf[i]=='R') ++*TY;
            else if (buf[i]=='U') --*TX;
            else if (buf[i]=='L') --*TY;
            else if (buf[i]=='I') { swap(a1,a2); swap(TY,TZ); }
            else if (buf[i]=='C') { swap(a0,a2); swap(TX,TZ); }
            //cout << "TESTING" << " " << buf[i] << endl;
        }
        for (vector<int> ttt : A) {
            ans[(H*N+ttt[a0]+*TX)%N][(H*N+ttt[a1]+*TY)%N]=(H*N+ttt[a2]+*TZ)%N;
        }
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) cout << ++ans[i][j] << " ";
            cout << endl;
        }
    }
    return 0;
}
*/
