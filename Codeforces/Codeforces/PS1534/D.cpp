/*#include <bits/stdc++.h>
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define p push
#define ins insert
#define t top
#define fr front
#define H 2100
#define MOD 1000000007

using namespace std;
typedef long long int LL;
typedef pair<int,int> pii;

int N;
set<pii> G;
int Va[H];
int Vb[H];
void query(int r) {
    cout << "? " << r << endl; cout.flush();
}
int main() {
    scanf("%d",&N);
    query(1);
    int x; scanf("%d",&x);
    int lp=0,rp=0;
    for (int i = 2; i <= N; i++) {
        scanf("%d",&x);
        if (x==1) {
            G.ins(mp(1,i));
        }
        if (x%2==1) {
            Va[lp]=i;
            lp++;
        } else {
            Vb[rp]=i;
            rp++;
        }
    }
    int* ptr = Va;
    if (rp<lp) {
        ptr=Vb;
        lp=rp;
    }
    for (int j = 0; j < lp; j++) {
        int r = *(ptr+j); query(r);
        for (int i = 1; i<=N; i++) {
            scanf("%d",&x);
            if (x==1) {
                if (i<r) G.ins(mp(i,r));
                else G.ins(mp(r,i));
            }
        }
    }
    cout << "!\n";
    for (pii y : G) {
        cout << y.f << " " << y.s << endl;
    }
}*/
