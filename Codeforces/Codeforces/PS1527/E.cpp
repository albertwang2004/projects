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

#define H 35*H3

#define mod 998244353
#define MOD 1000000007
#define INF 1069999999
#define lnf 0
#define LNF 5000000000000000000

using namespace std;
typedef long long int LL;
typedef pair<int,int> pii;
typedef pair<LL,LL> pll;

struct Cheese {

    LL F(LL a, LL b) {
        return min(a,b);
    }

    int sz;
    vector<LL> ST;
    vector<LL> lazy;
    void start(int n) {
        sz = n;
        for (int i = 0; i < 4*n; i++) { ST.pb(0); lazy.pb(0); }
    }

    void build(LL* A, int idx, int b, int e) {
        lazy[idx]=0;
        if(b == e) {
            ST[idx] = A[b];
        } else {
            int mid = (b + e) / 2;
            build(A, 2*idx, b, mid);
            build(A, 2*idx+1, mid+1, e);
            ST[idx] = F(ST[2*idx],ST[2*idx+1]);
        }
    }
    void build(LL* A) { build(A, 1, 0, sz-1); }

    void update(int idx, int b, int e, int l, int r, LL val) {
        if (lazy[idx] != 0) {
            ST[idx] += lazy[idx];
            if(b != e) {
                lazy[idx*2] += lazy[idx];
                lazy[idx*2+1] += lazy[idx];
            }
            lazy[idx] = 0;
        }
        if ((b > e) || (b > r) || (e < l)) return;
        if ((b >= l) && (e <= r)) {
            ST[idx] += val;
            if (b != e) {
                lazy[idx*2] += val;
                lazy[idx*2+1] += val;
            }
            return;
        }
        int mid = (b + e) / 2;
        update(idx*2, b, mid, l, r, val);
        update(idx*2 + 1, mid + 1, e, l, r, val);
        ST[idx] = F(ST[idx*2],ST[idx*2+1]);
    }
    void update(int l, int r, LL val) { update(1,0,sz-1,l,r,val); }

    LL query(int idx, int b, int e, int l, int r) {
        if ((b > e) || (b > r) || (e < l)) return LNF;
        if (lazy[idx] != 0) {
            ST[idx] += lazy[idx];
            if (b != e) {
                lazy[idx*2] += lazy[idx];
                lazy[idx*2+1] += lazy[idx];
            }
            lazy[idx] = 0;
        }
        if(b >= l and e <= r) return ST[idx];
        int mid = (b + e) / 2;
        LL p1 = query(idx*2, b, mid, l, r);
        LL p2 = query(idx*2 + 1, mid + 1, e, l, r);
        return F(p1,p2);
    }
    LL query(int l, int r) { return query(1,0,sz-1,l,r); }

} ST;

int T,N,M,K,Q;
int A[H];
int PR[H];
int B[H];
LL DP[H][H2];
LL trash[H];

int main() {

    bool trials = 0;

    if (trials) scanf("%d",&T);
    else T=1;

    while (T--) {
        scanf("%d%d",&N,&K);

        for (int i = 0; i < H; i++) DP[0][i] = LNF;
        DP[1][0]=LNF;
        ST.start(N+1);

        for (int i = 1; i <= N; i++) scanf("%d",A+i);

            LL tot = 0;
            for (int i = 0; i < H; i++) {
                B[i] = 0;
            }
        for (int i = 1; i <= N; i++) {

                PR[i] = B[A[i]];
                if (PR[i]==0) PR[i]=i;
                LL diff = i-PR[i];
                tot += diff;
                B[A[i]] = i;
            DP[1][i]=tot;
            //cout << 1 << " " << i << " " << tot << endl;
        }


        for (int j = 2; j <= K; j++) {

            LL tot = 0;
            // help what the heck am i doing
            ST.build(DP[j-1]);

            //for (int i = 0; i < j; i++) DP[j][i]=LNF;
            //DP[j][j]=0;
            for (int i = 1; i <= N; i++) {
                LL diff = i-PR[i];
                tot += diff;
               ST.update(PR[i],N,-diff);
               // cout << i << ": ";
                //for (int k = 0; k <= N; k++) {
                //    cout << ST.query(k,k) << " ";
                //}
                //cout << '\t';
                //ST.query(i-1,i-1);
                DP[j][i] = tot+ST.query(0,i-1);
                //cout << j << i << " " << DP[j][i] << endl;

            }
        }
    //        for (int j = 0; j < N; j++) {
  //      for (int i = 0; i <= N ;i++) {
 //               if (DP[j][i]>=MOD) cout << "x ";
//                else cout << DP[j][i] << " ";
   //         }
  //          cout << endl;
 //       }
        cout << DP[K][N] << endl;

    }

}
*/
