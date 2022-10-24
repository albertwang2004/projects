/*#include <bits/stdc++.h>
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define p push
#define ins insert
#define t top
#define fr front

#define T1 10
#define T2 100
#define T3 1000
#define T4 10000
#define T5 100000
#define T6 1000000

#define H1 11
#define H2 105
#define H3 1010
#define H4 10010
#define H5 100010
#define H6 1000010

#define H 5*H5

#define mod 998244353
#define MOD 1000000007
#define INF 1069999999
#define LNF 500000000000000000

using namespace std;
typedef long long int LL;
typedef pair<int,int> pii;

int T,N,M,K,Q;

vector<int> adj[H];
int D[H];
int C[H];

vector<int> ret;
LL ans = 0;
int cent = 0;
int pos[H];

int dfs1(int v, int c) {
    if (D[v]) return 0;
    D[v]=c++;
    int ret = 1;
    for (int u : adj[v]) {
        ret += dfs1(u,c);
    }
    C[v]=ret;
    return ret;
}

void dfs2(int v) {
    if (D[v]) {
        D[v]=0;
        pos[v] = (ret.size()+N/2)%N;
        ret.pb(v);
        for (int u : adj[v]) {
            dfs2(u);
        }
    }
}

int main() {

    bool trials = 0;

    if (trials) scanf("%d",&T);
    else T=1;

    while (T--) {
        scanf("%d",&N);
        for (int i = 0; i < N-1; i++) {
            int x,y; scanf("%d%d",&x,&y);
            adj[x].pb(y);
            adj[y].pb(x);
            D[i+1]=0;
        }
        D[N]=0;

        dfs1(1,1);

        for (int i = 1; i <= N; i++) {
            bool flag = 1;
            for (int j : adj[i]) {
                if (D[i]>D[j]) {
                    flag &= ((N-C[i])<=N/2);
                } else {
                    flag &= (C[j]<=N/2);
                    ans+=2*min(C[j],N-C[j]);
                }
            }
            if (flag) cent = i;
        }

        dfs2(cent);

        cout << ans << endl;

        for (int i = 1; i <= N; i++) cout << ret[pos[i]] << " ";
        cout << endl;

    }
}
*/
