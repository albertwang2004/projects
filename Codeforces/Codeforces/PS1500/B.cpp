/*#include <bits/stdc++.h>
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define p push
#define ins insert
#define t top
#define H 100100
#define INF 5000000000000000

using namespace std;
typedef long long int LL;

int T,N; LL K;
bool SP[H];
LL P2[60];
int main() {
    P2[0]=1;
    for (int i = 1; i < 60; i++) {
        P2[i]=P2[i-1]*2;
    }
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    scanf("%d",&T);
    while (T--) {
        scanf("%d%lld",&N,&K);
        vector<int> sploc;
        if (N < 61) {
            if (P2[N-1] < K) {
                cout << "-1" << endl;
                continue;
            }
        }
        K--;
        for (int i = N; i > 0; i--) {
            SP[i]=1;
        }
        for (int i = 59; i >= 0; i--) {
            if (K>=P2[i]) {
                K-=P2[i];
                SP[N-i-1]=0;
            }
        }
        for (int i = 1; i <= N; i++) {
            if (SP[i]) sploc.pb(i);
        }
        int curr = 0;
        //cout << "SPLIT LOCATIONS ";
        //for (int k : sploc) cout << k << " ";
        //cout << endl;
        for (int k : sploc) {
            for (int i = k; i > curr; i--) cout << i << " ";
            curr=k;
        }
        cout << endl;
    }
}*/
