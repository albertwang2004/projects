/*#include <bits/stdc++.h>
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define p push
#define ins insert
#define t top
#define fr front
#define H 800010
#define MOD 1000000007

using namespace std;
typedef long long int LL;
typedef pair<LL,LL> pii;

int T,N,M;
vector<LL> V;
vector<LL> TR;
vector<int> adj[H];
vector<int> comp[H];

int P[H];
int S[H];
int color[H];

bool color2(int v, int c) {
    if (color[v]) {
        if (color[v]!=c) return false;
        else return true;
    } else {
        color[v]=c;
        bool ret = 1;
        for (int x : adj[v]) {
            ret = ret && color2(x,3-c);
        }
        return ret;
    }
}

int pp(int x) {
	if (P[x]==x) return x;
    return (P[x] = pp(P[x]));
}

void un(int a, int b) {
	a = pp(a);
	b = pp(b);
	if (a == b) return;
	if (S[a] > S[b]) swap(a,b);
	S[b] += S[a];
	P[a] = b;
}


int main() {
    scanf("%d",&T);
    while (T--) {
        scanf("%d%d",&N,&M);
        V.clear();
        TR.clear();
        for (int i = 0; i < N; i++) {
            P[i]=i; S[i]=1;
            color[i]=0;
            comp[i]=vector<int>();
            adj[i]=vector<int>();
        }
        for (int i =0; i < N; i++) {
            int x; scanf("%d",&x);
            V.pb((LL)x);
        }
        for (int i =0; i < N; i++) {
            int x; scanf("%d",&x);
            TR.pb((LL)x);
        }
        for (int i =0; i < M ;i++) {
            int x,y; scanf("%d%d",&x,&y);
            x--;
            y--;
            adj[x].pb(y);
            adj[y].pb(x);
            un(x,y);
        }
        for (int i = 0; i < N; i++) {
            comp[pp(i)].pb(i);
        }
        bool flag = true;
        for (int i = 0; i < N; i++) {
            if (comp[i].size()) {
                int ssss = *(comp[i].begin());
                if (comp[i].size()==1) {
                    flag = flag && (V[ssss]==TR[ssss]);
                    continue;
                }
                bool tc = color2(ssss,1);
                if (tc) {
                    LL vs1=0; LL vs2=0;
                    LL ts1=0; LL ts2=0;
                    for (int j : comp[i]) {
                        if (color[j]==1) {
                            vs1+=V[j];
                            ts1+=TR[j];
                        } else {
                            vs2+=V[j];
                            ts2+=TR[j];
                        }
                    }
                    flag = flag && ((vs1-vs2)==(ts1-ts2));
                } else {
                    LL vs=0; LL ts=0;
                    for (int j : comp[i]) {
                        vs+=V[j];
                        ts+=TR[j];
                    }
                    flag = flag && (abs(vs-ts)%2==0);
                }
            }
        }
        if (flag) cout << "YES\n";
        else cout << "NO\n";
    }
}*/
