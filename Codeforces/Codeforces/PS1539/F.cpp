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

#define mod 998244353
#define MOD 1000000007
#define INF 1069999999
#define LNF 500000000000000000

using namespace std;
typedef long long int LL;
typedef pair<int,int> pii;

int T,N,M,K,Q;


LL BT[2*H5];
LL A[2*H5];

void update(LL* A, LL* BT, LL idx, LL x) {
   LL d = x - A[idx];
   A[idx] = x;
   while (idx <= N) {
       BT[idx] += d;
       idx += (idx & -idx);
   }
}

LL sum(LL* BT, LL idx) {
   LL s = 0;
   while (idx >= 1) {
       s += BT[idx];
       idx -= (idx & -idx);
   }
   return s;
}

LL subSeq(LL* BT, LL a, LL b) {
   return sum(BT,b) - sum(BT,a-1);
}

LL TT[4*H5];
void build(int a[], int v, int tl, int tr) {
    if (tl == tr) {
        TT[v] = a[tl];
    } else {
        int tm = (tl + tr) / 2;
        build(a, v*2, tl, tm);
        build(a, v*2+1, tm+1, tr);
        TT[v] = TT[v*2] + TT[v*2+1];
    }
}

int sum(int v, int tl, int tr, int l, int r) {
    if (l > r)
        return 0;
    if (l == tl && r == tr) {
        return TT[v];
    }
    int tm = (tl + tr) / 2;
    return sum(v*2, tl, tm, l, min(r, tm))
           + sum(v*2+1, tm+1, tr, max(l, tm+1), r);
}

void update(int v, int tl, int tr, int pos, int new_val) {
    if (tl == tr) {
        TT[v] = new_val;
    } else {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update(v*2, tl, tm, pos, new_val);
        else
            update(v*2+1, tm+1, tr, pos, new_val);
        TT[v] = TT[v*2] + T[v*2+1];
    }
}

int main() {

    bool trials = 0;

    if (trials) scanf("%d",&T);
    else T=1;

    while (T--) {
        scanf("%d",&N);


    }
}*/
