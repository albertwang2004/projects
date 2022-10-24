/*#include <bits/stdc++.h>
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define p push
#define fr front
#define H 100100
#define INF 5000000000000000

using namespace std;
typedef pair<int,int> pii;

int T,N;
set<int> adj[H];
int deg[H];
int anothervariable[H];
int SPEEDWAGON[H];
bool V[H];
bool VV[H];
queue<int> st;
queue<int> bfs;
stack<int> dfs;
stack<pii> re;
stack<pii> ad;

void del(int u) {
    int k = SPEEDWAGON[u];
    re.p(mp(u,k));
    deg[k]--;
    adj[u].erase(k);
    adj[k].erase(u);
}

int main() {
    scanf("%d",&T);
    while (T--) {
        scanf("%d",&N);
        for (int i = 1; i <= N; i++) {
            adj[i] = set<int>();
            deg[i] = 0;
            V[i]=1; VV[i]=1;
            SPEEDWAGON[i]=-1;
        }
        for (int i = 1; i < N; i++) {
            int x,y;
            scanf("%d%d",&x,&y);
            adj[x].insert(y);
            adj[y].insert(x);
        }
        int star = 0;
        for (int i = 1; i <= N; i++) {
            deg[i] = adj[i].size()-1;
            anothervariable[i]=deg[i]+1;
            if (deg[i]==0) {
                star = i;
                bfs.p(i);
            }
        }
        //deg[star]++;
        //cout << star << endl;
        bfs.p(star);
        while (bfs.size()) {
            int v = bfs.fr();
            bfs.pop();
            if (v == star) continue;
            if (VV[v] && (anothervariable[v]<=1)) {
                st.p(v);
                VV[v]=0;
                for (int u : adj[v]) {
                    if (VV[u]) {
                        anothervariable[u]--; anothervariable[v]--;
                        SPEEDWAGON[v]=u;
                        bfs.p(u);
                    }
                }
            }
        }

        st.p(star);
        while (st.size()) {
            int v = st.fr();
            st.pop();
            int u = SPEEDWAGON[v];
            if (deg[v]>=2) {
                if (adj[u].find(v)!=adj[u].end()) {
                    del(v);
                }
            }
            set<int> co = adj[v];
            for (int it : co) {
                if (deg[v]>2) {
                    del(it);
                }
            }
        }


        for (int i = 1; i <= N; i++) {
            deg[i] = adj[i].size();
            if (deg[i]<=1) {
                dfs.p(i);
                //cout << i << endl;
            }
            V[i]=1;
        }

        int pr = 0;
        bool add = 0;
        while (dfs.size()) {
            int u = dfs.top();
            dfs.pop();
            //cout << u << " " << add << " " << pr << endl;
            if (V[u]) {
                if (add) {
                    ad.p(mp(pr,u));
                    //cout << "added " << pr << " " << u << endl;
                    add=0;
                }
                if (deg[u]==0) {
                    pr = u;
                    add=1;
                }
                V[u]=0;
                for (int v : adj[u]) {
                    if (V[v]) {
                        deg[v]--;
                    deg[u]--;
                        dfs.p(v);
                    }
                }
            }
        }


        int ret = re.size();
        cout << ret << endl;
        assert(ret==ad.size());
        for (int i = 0; i < ret; i++) {
            pii x = re.top(), y = ad.top();
            cout << x.f << " " << x.s << " " << y.f << " " << y.s << endl;
            re.pop();ad.pop();
        }
    }
}
*/
