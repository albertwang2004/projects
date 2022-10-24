/*#include <bits/stdc++.h>
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define p push
#define ins insert
#define t top
#define H 1024
#define INF 5000000000000000

using namespace std;
typedef pair<int,int> pii;
typedef long long int LL;

int D,N;
set<int> V;
int wt[H];
set<pii> adj[H];
set<pii> rev[H];
int main() {
    scanf("%d%d",&D,&N);
    for (int i = 1; i <= N; i++) {
        char buf[D]; scanf("%s",buf);
        V.ins(w);
    }
    for (int i = 0; i < H; i++) {
        int j = i;
        wt[i]=0;
        while (j) {
            wt[i]+=(j%2);
            j /= 2;
        }
    }
    for (int i : V) {
        for (int j : V) {
            if (i==j) continue;
            if ((i|j)==i) {
                adj[j].ins(i);
                rev[j].ins(i);
            }
        }
    }
    for (int i : V) {
        cout << i << ": ";
        for (int j : adj[i]) cout << j << " ";
        cout << endl;
    }
}
*/
