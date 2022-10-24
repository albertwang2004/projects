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

#define H 1*H6

#define mod 998244353
#define MOD 1000000007
#define INF 1069999999
#define lnf 0
#define LNF 5000000000000000000

using namespace std;
mt19937 mr(time(0));
struct LL {

    static const long long int m = mod; // set to LNF for nomod
    long long int val;

    LL(long long int v) {val=reduce(v);};
    LL() {val=0;};
    ~LL(){};
    LL(const LL& l) {val=l.val;};
    LL& operator=(int l) {val=l; return *this;}
    LL& operator=(long long int l) {val=l; return *this;}
    LL& operator=(LL l) {val=l.val; return *this;}

    static long long int reduce(long long int x, long long int md = m) {
        x %= md;
        while (x >= md) x-=md;
        while (x < 0) x+=md;
        return x;
    }

    bool operator<(const LL& b) { return val<b.val; }
    bool operator<=(const LL& b) { return val<=b.val; }
    bool operator==(const LL& b) { return val==b.val; }
    bool operator>=(const LL& b) { return val>=b.val; }
    bool operator>(const LL& b) { return val>b.val; }

    LL operator+(const LL& b) { return LL(val+b.val); }
    LL operator+(const long long int& b) { return (*this+LL(b)); }
    LL& operator+=(const LL& b) { return (*this=*this+b); }
    LL& operator+=(const long long int& b) { return (*this=*this+b); }

    LL operator-(const LL& b) { return LL(val-b.val); }
    LL operator-(const long long int& b) { return (*this-LL(b)); }
    LL& operator-=(const LL& b) { return (*this=*this-b); }
    LL& operator-=(const long long int& b) { return (*this=*this-b); }

    LL operator*(const LL& b) { return LL(val*b.val); }
    LL operator*(const long long int& b) { return (*this*LL(b)); }
    LL& operator*=(const LL& b) { return (*this=*this*b); }
    LL& operator*=(const long long int& b) { return (*this=*this*b); }

    static LL exp(const LL& x, const long long int& y){
        long long int z = y;
        z = reduce(z,m-1);
        LL ret = 1;
        LL w = x;
        while (z) {
            if (z&1) ret *= w;
            z >>= 1; w *= w;
        }
        return ret;
    }
    LL& operator^=(long long int y) { return (*this=LL(val^y)); }

    LL operator/(const LL& b) { return ((*this)*exp(b,-1)); }
    LL operator/(const long long int& b) { return (*this/LL(b)); }
    LL operator/=(const LL& b) { return ((*this)*=exp(b,-1)); }
    LL& operator/=(const long long int& b) { return (*this=*this/LL(b)); }

}; ostream& operator<<(ostream& os, const LL& obj) { return os << obj.val; }
typedef pair<int,int> pii;
typedef pair<LL,LL> pll;

int T,N,M,K,Q;

int rd() {int x; scanf("%d",&x); return x;}
void fl() {Q++; cout.flush();}

int main() {

    bool trials = 1;

    if (trials) T=rd();
    else T=1;

    while (T--) {
            Q=0;

        N = rd();

        int curr = 1;
        for (;;curr++) {
            cout << "? " << 1 << " " << N-curr << endl;
            cout << curr << endl;
            for (int i=curr+1; i<=N; i++) cout << i << " "; cout << endl;
            fl(); if (M=rd()) break;
        }
        int L = 1; int R = curr+1;
        int shit = 0;
        vector<int> ret;
        for (int i = (curr==N-1)?N+1:R; i < N; i++) {
            cout << "? 1 1" << endl;
            cout << curr << endl << i << endl;
            fl(); K=rd(); shit+=K; if (!K) ret.pb(i);
        }
        if (M==shit) ret.pb(N);

        //if (curr>1) {
        //    cout << "? " << curr-1 << " 1" << endl;
        //    for (int i = 1; i < curr; i++) cout << i << " ";
        //    cout << endl << curr << endl; fl();
        //    if (!rd()) L = 69420;
        //}

        while (L<R-1) {
            M = (L+R)/2;
            cout << "? " << M-L << " 1" << endl;
            for (int i = L; i < M; i++) cout << i << " ";
            cout << endl << curr << endl;
            fl(); if (rd()) R=M;
            else L=M;
        }
        for (int i = 1; i < curr; i++) if (i!=L) ret.pb(i);

        cout << "! " << ret.size() << " ";
        for (int i : ret) { cout << i << " "; } cout << endl;

    }
}*/
