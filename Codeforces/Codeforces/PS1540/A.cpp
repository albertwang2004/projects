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

#define H 200100

#define mod 998244353
#define MOD 1000000007
#define INF 1069999999
#define LNF 500000000000000000

using namespace std;
typedef long long int LL;
typedef pair<int,int> pii;

int T,N,M;
vector<LL> A;
int main() {

    bool trials = 1;

    if (trials) scanf("%d",&T);
    else T=1;

    while (T--) {

        A.clear();
        scanf("%d",&N);
        //scanf("%d",&M);
        for (int i = 1; i <= N; i++) {
            LL x; scanf("%lld",&x);
            A.pb(x);

        }
        LL ret = 0;
        sort(A.begin(),A.end());
        for (int i = 0; i < N; i++) {
            ret += max(0,(N-i-2))*A[i];
            ret -= max(0,i-1)*A[i];
            //cout << i << " " << max(0,N-i-2) << " " << max(0,i-1) << endl;
        }
        cout << ret << endl;
    }
}*/
