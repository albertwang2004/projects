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

#define H H6

#define mod 998244353
#define MOD 1000000007
#define INF 1069999999
#define LNF 500000000000000000

using namespace std;
typedef long long int LL;
typedef pair<int,int> pii;

int T,N,M,K,Q;
char buf[H];
int last0[H];
int last1[H];
int skip[H];

int main() {

        std::ios::sync_with_stdio(false);

    cin.tie(0);
    cout.tie(0);
    bool trials = 0;

    if (trials) scanf("%d",&T);
    else T=1;

    while (T--) {
        scanf("%d",&N);
        scanf("%s",buf+1);
//N=T6;
        last0[0]=0; last1[0]=0;
        for (int i = 1; i <= N; i++) {
                //buf[i]='0'+(i%2);
            skip[i]=1;
            if (buf[i]!='0') {
                last1[i]=last1[i-1]+1;
            } else {
                last1[i]=0;
            }
            if (buf[i]!='1') {
                last0[i]=last0[i-1]+1;
            } else {
                last0[i]=0;
            }
        }
        for (int i = 1; i <= N; i++) {
            //if (i%100==0)cout << i << endl;
            int curr = N;
            int ret = 0;
            queue<int> chain;
            while (curr) {
                //cout << i << " " << curr << endl;
                int j0 = last0[curr];
                int j1 = last1[curr];
                if (j0<j1) swap(j0,j1);
                if (j0>=i) {
                    while (chain.size()) {
                        int x = chain.fr();
                        chain.pop();
                        skip[x]=x-curr;
                    }
                    curr -= i; ret++;
                } else {
                    chain.p(curr);
                    curr-=skip[curr];
                }
            }
            while (chain.size()) {
                int x = chain.fr();
                chain.pop();
                skip[x]=x-curr;
            }
            cout << ret << " ";
        }
        cout << endl;
    }
}
*/
