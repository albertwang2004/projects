/*#include <bits/stdc++.h>
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define p push
#define ins insert
#define t top
#define H 200100
#define INF 5000000000000000

using namespace std;
typedef pair<int,int> pii;
typedef long long int LL;

int T,n; LL N;
vector<int> adj[H];
int P[H];
LL C[H];
int L,R;
bool V[H];
LL ret[H];

void dfs(int v) {
    if (!V[v]) {
        V[v]=true;
        LL ret = 1;
        for (int u : adj[v]) {
            if (!V[u]) {
                P[u]=v;
                dfs(u);
                ret+=C[u];
            }
        }
        C[v]=ret;
    }
}
int tip;
bool good(int v) {
    if (V[v]) {
        int u=v;
        int prev;
        while (V[u]) {
            V[u]=false;
            prev=u;
            u=P[u];
        }
        if ((u==1) && (L==1) && (R==1)) {
            tip = prev;
            L=v;
            return true;
        }
        if (u==L) {
            L=v;
            return true;
        }
        if (u==R) {
            R=v;
            return true;
        }
        return false;
    } else {
        return true;
    }
}

LL CC(int v) {
    if (v==1) return C[1]-C[tip];
    else return C[v];
}

int main() {
    scanf("%d",&T);
    while (T--) {
        L=1;R=1;
        scanf("%d",&n);
        N = (LL)n;
        for (int i = 0; i <= N+1; i++) {
            adj[i].clear();
            V[i]=false;
            C[i]=0;
            P[i]=0;
            ret[i]=0;
        }

        for (int i = 0; i < N-1; i++) {
            int x,y; scanf("%d%d",&x,&y);
            x++; y++;
            adj[x].pb(y);
            adj[y].pb(x);
        }

        dfs(1);
        ret[0]=N*(N-1)/2;
        ret[1]=ret[0];
        for (int u : adj[1]) {
            ret[1]-=(C[u]-1)*C[u]/2;
        }
        V[1]=false;

        int vv;
        for (vv=2;vv<=N;vv++) {
            bool x = good(vv);
            //cout << "good? " << vv << x << endl;
            if (!x) {
                break;
            } else {
                ret[vv]=CC(L)*CC(R);
            }
        }
        for (;vv<=N+1;vv++) {
            ret[vv]=0;
        }

        // return the answers
        for (int i = 0; i < N+1; i++) {
            cout << ret[i]-ret[i+1] << " ";
            //cout << ret[i] << " ";
        }
        cout << endl;

    }
}
*/
