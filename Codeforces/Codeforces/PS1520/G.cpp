/*#include <bits/stdc++.h>
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define p push
#define fr front
#define H 2001
#define INF 5000000000000000

using namespace std;
typedef long long int LL;
typedef pair<int,int> pii;
typedef pair<pii,LL> pac;
int N,M,w;
LL W;
template <typename T,typename U> std::pair<T,U> operator+(const std::pair<T,U>& l, const std::pair<T,U>& r) {
    return {l.f+r.f,l.s+r.s};
}

LL bfsh[H][H];
LL bfss[H][H];
LL cty[H][H];
pii adj[4] = {{0,1},{1,0},{0,-1},{-1,0}};

int main() {
    std::cin.sync_with_stdio(false);
    std::cout.sync_with_stdio(false);
    scanf("%d%d%d",&N,&M,&w);
    W=1LL*w;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < H; j++) {
            cty[i][j]=-1;
        }
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            int w; scanf("%d",&w);
            cty[i][j]=w;
            bfsh[i][j]=INF;
            bfss[i][j]=INF;
        }
    }
    queue<pac> P;
    P.p(mp(mp(1,1),0LL));
    while (P.size()) {
        pac Pp = P.fr();
        P.pop();
        if (cty[Pp.f.f][Pp.f.s]+1) {
            if (bfsh[Pp.f.f][Pp.f.s]==INF) {
                bfsh[Pp.f.f][Pp.f.s]=Pp.s;
                for (pii i : adj) {
                    P.p(mp(Pp.f+i,Pp.s+W));
                }
            }
        }
    }
    P.p(mp(mp(N,M),0LL));
    while (P.size()) {
        pac Pp = P.fr();
        P.pop();
        if (cty[Pp.f.f][Pp.f.s]+1) {
            if (bfss[Pp.f.f][Pp.f.s]==INF) {
                bfss[Pp.f.f][Pp.f.s]=Pp.s;
                for (pii i : adj) {
                    P.p(mp(Pp.f+i,Pp.s+W));
                }
            }
        }
    }
    LL ret = bfsh[N][M];
    LL besth = INF;
    LL bests = INF;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            if (cty[i][j]>0) {
                //cout << i << " " << j << endl;
                besth=min(besth,cty[i][j]+bfsh[i][j]);
                bests=min(bests,cty[i][j]+bfss[i][j]);
            }
        }
    }
    LL ans = min(ret,besth+bests);
    if (ans>=INF) ans = -1;
    cout << ans << endl;
}
*/
