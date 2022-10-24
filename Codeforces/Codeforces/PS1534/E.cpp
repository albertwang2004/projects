/*#include <bits/stdc++.h>
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define p push
#define ins insert
#define t top
#define fr front
#define H 510
#define MOD 1000000007

using namespace std;
typedef long long int LL;
typedef pair<int,int> pii;

int N,K;
LL ret = 0; int x;

int S[H]; // min to get to cover i
int P[H]; // optimal move to i
vector<int> adj;

int LP = 0;

void fl() {
    cout << endl; cout.flush();
    scanf("%d",&x);
    ret^=x;
}

int query(int x) {
    if (x==K) {
        cout << "? ";
        for (int i = 1; i <= K; i++) cout << ++LP << " ";
        fl();
    } else {
        assert(x%2==0);
        cout << "? ";
        for (int i = LP+1; i <= LP+x/2; i++) cout << i << " ";
        for (int i = LP+x+1; i <= LP+K+x/2; i++) cout << (i-1)%N+1 << " ";
        fl();
        cout << "? ";
        for (int i = LP+x/2+1; i <= LP+x; i++) cout << i << " ";
        for (int i = LP+x+1; i <= LP+K+x/2; i++) cout << (i-1)%N+1 << " ";
        fl();
        LP+=x;
    }
}

int main() {
    scanf("%d%d",&N,&K);
    if ((K%2==0)&&(N%2==1)) {
        cout << "-1\n"; return 0;
    }

    adj.pb(K);
    for (int i = 1; i <= min(K,N-K); i++) {
        adj.pb(2*i);
    }

    S[0]=0;
    for (int i = 1; i <= N; i++) {
        S[i]=99999;
        for (int j : adj) {
            if (j<=i) {
                int m = S[i-j]+((j==K)?1:2);
                if (m<S[i]) {
                    S[i]=m;
                    P[i]=j;
                }
            }
        }
    }
    int curr = N;
    while (curr>0) {
        query(P[curr]);
        curr-=P[curr];
    }
    cout << "! " << ret << endl;
}
*/
