/*#include <bits/stdc++.h>
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define p push
#define ins insert
#define t top
#define fr front
#define H 600
#define MOD 1100000007
using namespace std;
typedef long long int LL;
typedef pair<int,int> pii;

int N,M;
int adj[H][H];

// Dijkstra's

vector<int> D;
void dijkstra(int s) {
    D.assign(N, MOD);
    vector<bool> u(N, false);
    for (int i = 0; i < N; i++) {
        D[i]=min(D[i],adj[s][i]);
    }
    while (1) {
        int v = -1;
        for (int j = 0; j < N; j++) {
            if (!u[j] && (v == -1 || D[j] < D[v]))
                v = j;
        }

        if (v==-1) break;
        u[v] = true;

        D[(v+1)%N]=min(D[(v+1)%N],D[v]+1);

        for (int j = 0; j < N; j++) {
            D[(j+D[v])%N] = min(D[(j+D[v])%N],D[v] + adj[v][j]);
        }
    }
}



int main() {
    scanf("%d%d",&N,&M);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            adj[i][j]=MOD;
        }
        //adj[i][i]=0;
    }
    while (M--) {
        int a,b,c; scanf("%d%d%d",&a,&b,&c);
        adj[a][b]=min(adj[a][b],c);
    }
    for (int i = 0; i < N; i++) {
        dijkstra(i);
        D[i]=0;
        for (int j = 0; j < N; j++) {
            cout << D[j] << " ";
        }
        cout << endl;
    }
}*/
