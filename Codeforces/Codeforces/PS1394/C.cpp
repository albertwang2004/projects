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

#define H 5*H5

#define mod 998244353
#define MOD 1000000007
#define INF 1069999999
#define LNF 500000000000000000

using namespace std;
typedef long long int LL;
typedef pair<int,int> pii;

int T,N,M,K,Q;
int l=INF;
int d=INF;
int a=INF;
int r=-INF;
int u=-INF;
int B=-INF;
char buf[H];

pii ret;
bool check(int M) {
    //cout << "Checking " << M << endl;
    for (int i = max(r-M,0); i <= l+M; i++) {
        int lower = max(max(u-M,0), i+B-M);
        int upper = min(d+M, i+a+M);
        //cout << "Bounds at x=" << i << ": " << lower << " " << upper << endl;
        if (i==0) lower=max(lower,1); // NONEMPTY
        if (lower <= upper) {
            ret=mp(i,lower);
            return true;
        }
    }
    return false;
}
int main() {

    bool trials = 0;

    if (trials) scanf("%d",&T);
    else T=1;

    while (T--) {
        scanf("%d",&N);

        for (int i = 0; i < N; i++) {
            scanf("%s",buf);
            int k = strlen(buf);
            int b=0; int n=0;
            for (int i = 0; i < k; i++)
                if (buf[i]=='B') b++;
                else n++;
            l=min(l,b);
            d=min(d,n);
            a=min(a,n-b);
            r=max(r,b);
            u=max(u,n);
            B=max(B,n-b);
        }

        //cout << l << " " << d<< " " << a << " " << r << " " << u<< " "
        //<< B << endl;

        int L = 0;
        int R = T6;

        while (L<R) {
            int M=(L+R)/2;
            if (check(M)) R=M;
            else L=M+1;
        }

        cout << L << endl;
        //cout << ret.f << " " << ret.s << endl;
        while (ret.f--) cout << 'B';
        while (ret.s--) cout << 'N';
        cout << endl;

    }
}
*/
