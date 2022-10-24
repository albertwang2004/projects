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

#define H 5*H3

#define mod 998244353
#define MOD 1000000007
#define INF 1069999999
#define LNF 0

using namespace std;
typedef long long int LL;
typedef pair<int,int> pii;
// segment tree

int T,N,M,K,Q;
int tags[H];
LL scores[H];
LL ans[H];
int main() {

    bool trials = 1;

    if (trials) scanf("%d",&T);
    else T=1;

    while (T--) {
        scanf("%d",&N);
        LL ret = 0;
        for (int i = 0; i < N; i++) ans[i] = 0;
        for (int i = 0; i < N; i++) scanf("%d",tags+i);
        for (int i = 0; i < N; i++) scanf("%lld",scores+i);
        for (int i = 0; i < N; i++) {
            for (int j = i-1; j>-1; j--) {
                if (tags[i]==tags[j]) continue;
                LL add = abs(scores[i]-scores[j]);
                LL temp = ans[j];
                ans[j]=max(ans[j],ans[i]+add);
                ans[i]=max(ans[i],temp+add);
                ret = max(ret,max(ans[i],ans[j]));
            }
        }
        cout << ret << endl;
    }
}
*/
