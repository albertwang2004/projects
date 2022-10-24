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

#define H 2*H5

#define mod 998244353
#define MOD 1000000007
#define INF 1069999999
#define LNF 0

using namespace std;
typedef long long int LL;
typedef pair<int,int> pii;
// segment tree

int T,N,M,K,Q;

struct SegTree {

    LL F(LL a, LL b) {
        return max(a,b);
    }

	int sz;
	vector<LL> ST;

	void start(int n) {
	    sz = n;
	    for (int i = 0; i < 2*n; i++)
            ST.pb(LNF); // i may have to change this value
    }

	void lift(int idx) {
	    ST[idx] = F(ST[2*idx],ST[2*idx+1]);
    }

	void update(int idx, LL x) {
		idx += sz;
		ST[idx] = x;
		idx >>= 1;
		while (idx) {
            lift(idx); idx >>= 1;
		}
	}

	LL query(int lp, int rp) {
		LL a = LNF; // i may have to change this value
		LL b = LNF; // i may have to change this value
		lp += sz;
		rp += sz + 1;
		while (lp < rp) {
			if (lp&1) a = F(a,ST[lp++]);
			if (rp&1) b = F(ST[--rp],b);
			lp >>= 1; rp >>= 1;
		}
		return F(a,b);
	}

} ST[86];
int enc[H];
int bil[H][20];
vector<LL> P; // primes

// there are 86 primes that we will do with a segtree
// the remaining 18000 ish will be dealt with using stupidity

int DP[H];
int pre[H];

// modular exponentiation

LL modexp(LL x, LL y){
    LL ret = 1;
    while (y) {
        if (y % 2 == 1) ret = (ret * x)%MOD;
        y = y >> 1;
        x = (x * x)%MOD;
    }
    return ret%MOD;
}

bool visited[H];
vector<LL> things;
vector<LL> powers[86];

int main() {

    bool trials = 0;

    if (trials) scanf("%d",&T);
    else T=1;

    while (T--) {
        scanf("%d",&N);
        enc[2]=0;
        P.pb(2);
        for (int i = 0; i < H; i++) {
            DP[i] = -1;
            visited[i] = 0;
            for (int j = 0; j < 20; j++) bil[i][j]=-1;
        }
        for (int i = 3; i < H; i++) {
            for (int j : P) {
                if (j*j>i) break;
                if (i%j==0) goto bad_coding_practice;
            }
            enc[i]=P.size();
            P.pb(i);
            bad_coding_practice:;
        }
        for (int i = 0; i < 86; i++) {
            powers[i]=vector<LL>();
            powers[i].pb(1);
            for (int j = 0; j < 30; j++) {
                powers[i].pb((powers[i][powers[i].size()-1]*P[i])%MOD);
            }
        }
        for (int i = 0; i < 86; i++) ST[i].start(N);
        for (int i = 0; i < N; i++) {
            int x; scanf("%d",&x);
            int curr = 0;
            while (curr < 86) {
                int div = 0;
                while (x%P[curr]==0) {
                    div++;
                    x/=P[curr];
                }
                ST[curr].update(i,div);
                curr++;
            }
            things.pb(i);
            if (x>1) {
                pre[i]=DP[x];
                DP[x]=i;
            }
        }
        for (int i = N-1; i >= 0; i--) {
            int that = things[i];
            if (visited[i]) continue;
            for (int j = 0; j < 20; j++) {
            int curr = i;
                int gap = powers[0][j];
                vector<int> stuff;
                int ptr = -gap;
                while (curr>-1) {
                    visited[curr]=0;
                    stuff.pb(curr);
                    if (ptr>=0)  {
                        bil[stuff[ptr]][j] = curr;
                    }
                    ptr++;
                    curr=pre[curr];
                }
            }
        }
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < 20; j++) {
                cout << bil[i][j] << " ";
            }
            cout << endl;
        }
    }
}*/
