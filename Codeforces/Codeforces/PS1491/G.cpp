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
void fl() {cout.flush();}
bool V[H];
int A[H];
int lp = 0;
vector<pii> ret;
vector<vector<int>> suck;

void suck1() { // n+1
    for (int i = 0; i < suck[lp].size()-2; i++) {
        ret.pb(mp(suck[lp][i],suck[lp][suck[lp].size()-1]));
    }
    ret.pb(mp(suck[lp][0],suck[lp][suck[lp].size()-2]));
    ret.pb(mp(suck[lp][suck[lp].size()-2],suck[lp][suck[lp].size()-1]));
    ret.pb(mp(suck[lp][0],suck[lp][suck[lp].size()-1]));
    lp++;
}

void suck2() { // n
    int L = suck[lp].size()-1;
    int R = suck[lp+1].size()-1;
    ret.pb(mp(suck[lp][L],suck[lp+1][R]));
    for (int i = 0; i < R; i++) ret.pb(mp(suck[lp+1][i],suck[lp][L]));
    for (int i = 0; i <= L; i++) ret.pb(mp(suck[lp][i],suck[lp+1][R]));
    lp+=2;
}

void suck3() { // n+1
    int L = suck[lp].size()-1;
    int M = suck[lp+1].size()-1;
    int R = suck[lp+2].size()-1;
    ret.pb(mp(suck[lp][L],suck[lp+1][M]));
    ret.pb(mp(suck[lp+1][M],suck[lp+2][R]));
    for (int i = 0; i < M; i++) ret.pb(mp(suck[lp+1][i],suck[lp][L]));
    for (int i = 0; i <= R; i++) ret.pb(mp(suck[lp+2][i],suck[lp+1][M]));
    for (int i = 0; i <= L; i++) ret.pb(mp(suck[lp][i],suck[lp+1][M]));
    lp+=3;
}

int main() {

    bool trials = 0;

    if (trials) T=rd();
    else T=1;

    while (T--) {

        N = rd();

        for (int i = 1; i <= N; i++) { V[i] = 1; scanf("%d",A+i); }
        int sucks = 0;
        for (int i = 1; i <= N; i++) {
            if (V[i]) {
                suck.pb(vector<int>());
                int curr = i;
                while ((curr != i) || (suck[sucks].size()==0)) {
                    V[curr] = 0;
                    suck[sucks].pb(curr);
                    curr = A[curr];
                }
                sucks++;
            }
        }

        while (sucks-lp>0) {
            //if ((suck[lp].size()==1)&&(sucks-lp>1)) lp++;
            //else
            if (sucks-lp==1) suck1();
            else if (sucks-lp==3) suck3();
            else suck2();
        }

        cout <<ret.size()<< endl;
        for (pii x : ret) {
            cout << x.f << " " << x.s << endl;
        }
    }
}
*/
