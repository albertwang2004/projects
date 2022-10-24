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
unordered_set<int> mexicans;
char buf[H];
int p2[] = {1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768
        ,65536,131072,262144,524288,1048576};

int main() {

    bool trials = 1;

    if (trials) scanf("%d",&T);
    else T=1;

    while (T--) {

        mexicans = unordered_set<int>();

        scanf("%d%d",&N,&M);

        scanf("%s",buf);

        int pp = min(M,20);
        int acc = p2[pp];

        int lp = 0;
        int one = 0;
        int rp = M-1;

        for (;++rp<=N;lp++) {
            for(;(((buf[one]=='1')||(one<lp))&&(one++<rp));) {}
            //cout << "Currently processing " << lp << " " << one << " " << rp << endl;
            if (rp-one<=pp) {
                int hsh = 0;
                for (int i = 1; i <= rp-one; i++) {
                    hsh += p2[i-1]*(buf[rp-i]=='0');
                }
                //cout << hsh << endl;
                mexicans.ins(hsh);
            }
        }

        int ret=0;
        while (mexicans.count(ret)) ret++;
        if (acc==ret) cout <<"NO"<< endl;
        else {
            cout << "YES" << endl;
            for (int i = 0; i < M; i++) {
                if (M-i<=pp) {
                    cout << (char)('0'+((ret&p2[M-i-1])?1:0));
                } else cout << '0';
            } cout << endl;
        }
    }
}*/
