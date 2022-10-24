/*#include <bits/stdc++.h>
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define p push
#define ins insert
#define t top
#define fr front
#define H 100010
#define MOD 1000000007
#define INF 999999

using namespace std;
typedef long long int LL;
typedef pair<int,int> pii;

int T,N,M,K;
unordered_set<int> adj[H];
int deg[H];
std::set<pii> V;

int main() {
    scanf("%d",&T);
    while (T--) {
        V.clear();
        scanf("%d%d%d",&N,&M,&K);
        for (int i = 1; i <= N; i++) {
            adj[i].clear();
            deg[i]=0;
        }
        int x,y;
        while (M--) {
            scanf("%d%d",&x,&y);
            adj[x].ins(y);
            adj[y].ins(x);
            deg[x]++;
            deg[y]++;
        }
        int flag = -1;
        //bool U[N+1];
        for (int i = 1; i <= N; i++) {
            V.ins(mp(deg[i],i));
            //U[i]=false;
        }
        //int X = N;
        while (V.size()) {
            //assert(V.size()==X); X--;
            int v = V.begin()->s;
            //cout << v << endl;
            if (deg[v]==K-1) {
                vector<int> a;
                for (int u : adj[v]) {
                    if (deg[u]) a.pb(u);
                }
                //cout << "Made A " << a.size() << endl;
                bool bad = 0;
                for (int i : a) {
                    for (int j : a) {
                        if (i<=j) continue;
                        if (adj[i].count(j)) {
                        } else {

                            bad = 1;
                            break;}
                    }
                    if (bad) break;
                }
                //cout << "Fuck \n";
                if (!bad) {
                    printf("%d\n%d ",2,v);
                    for (int i : a) {
                        printf("%d ",i);
                    }
                    printf("\n");
                    flag = -2;
                    break;
                }
            }
            if (deg[v]>=K) {
                flag = 1;
                break;
            } else {
                deg[v]=0;
                V.erase(V.begin());
                for (int u : adj[v]) {
                    if (deg[u]) {
                        V.erase(mp(deg[u],u));
                        --deg[u];
                        V.ins(mp(deg[u],u));
                    }
                }
            }
        }
        if (flag==-2) continue;
        if (flag != 1) printf("%d\n",flag);
        else printf("%d %d\n",flag,V.size());
        if (flag) {
            for (pii i : V) {
                printf("%d ",i.s);
            }
            printf("\n");
        }
    }
}
*/
