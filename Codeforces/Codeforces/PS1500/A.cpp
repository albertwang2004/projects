/*#include <bits/stdc++.h>
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define p push
#define ins insert
#define t top
#define H 5000100 // oh god
#define INF 5000000000000000

using namespace std;
typedef long long int LL;
typedef pair<int,int> pii;

int N;
vector<int> A;
vector<pii> ret[H];

int main() {
    for (int i = 0; i < H; i++) {
        ret[i] = vector<pii>();
    }
    scanf("%d",&N);
    bool flag = 0;
    for (int i = 0; i < min(N,3500); i++) {
        int x; scanf("%d",&x);
        A.pb(x);
        for (int j = 0; j < i; j++) {
            int ans = A[i]+A[j];
            ret[ans].pb(mp(i+1,j+1));
            for (pii k : ret[ans]) {
                for (pii l : ret[ans]) {
                    set<int> a;
                    a.ins(k.f);
                    a.ins(k.s);
                    a.ins(l.f);
                    a.ins(l.s);
                    if (a.size()==4) {
                        cout << "YES\n" << k.f << " " << k.s << " " << l.f << " " << l.s << endl;
                        flag=1;
                        break;
                    }
                }
                if (flag) break;
            }
            if (flag) break;
        }
        if (flag) break;
    }
    if (!flag) cout << "NO";
    cout << endl;
}
*/
