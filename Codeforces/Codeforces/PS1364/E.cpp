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

#define H 2048

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

vector<int> idx;
vector<int> ansx;
vector<int> ansy;

int main() {

    bool trials = 0;

    if (trials) T=rd();
    else T=1;

    while (T--) {

        N = rd();

        for (int i = 0; i < N; i++) { idx.pb(i); ansx.pb(-1); ansy.pb(-1); }

        random_shuffle(idx.begin(),idx.end());

        int x = idx[0], y = idx[1];
        cout << "? " << x+1 << " " << y+1 << endl; fl();
        int curr = rd();

        for (int i = 2; i < N; i++) {
            cout << "? " << y+1 << " " << idx[i]+1 << endl; fl();
            int temp = rd();
            if (temp<curr) {
                x=idx[i];
                curr=temp;
            } else if (temp==curr) {
                y=idx[i];
                cout << "? " << x+1 << " " << y+1 << endl; fl();
                curr=rd();
            }
        }

        random_shuffle(idx.begin(),idx.end());

        bool flagx = 0;
        for (int i : idx) {
            if (i!=x) if (i!=y) {
                cout << "? " << x+1 << " " << i+1 << endl; fl();
                ansx[i]=rd();
                cout << "? " << y+1 << " " << i+1 << endl; fl();
                ansy[i]=rd();
                if (ansx[i]<ansy[i]) {
                    flagx = 1; break;
                } else if (ansx[i]>ansy[i]){
                    flagx = 0; break;
                }
            }
        }

        if (flagx) {
            ansx[x]=0;
            for (int i : idx) {
                if (ansx[i]==-1) {
                    cout << "? " << x+1 << " " << i+1 << endl; fl();
                    ansx[i]=rd();
                }
            }
            cout << "! ";
            for (int p : ansx) cout << p << " ";
            cout << endl;
        } else {
            ansy[y]=0;
            for (int i : idx) {
                if (ansy[i]==-1) {
                    cout << "? " << y+1 << " " << i+1 << endl; fl();
                    ansy[i]=rd();
                }
            }
            cout << "! ";
            for (int p : ansy) cout << p << " ";
            cout << endl;
        }

    }
}*/
