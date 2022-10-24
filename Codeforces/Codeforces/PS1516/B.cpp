/*#include <bits/stdc++.h>
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define p push
#define fr front
#define H 100010

using namespace std;
typedef long long int LL;

int T,N;
int main() {
    cin >> T;
    while (T--) {
        cin >> N;
        vector<int> A;
        int ctr=0,ret=0,it=0;
        while (N--) {
            int x; cin >> x;
            A.pb(ret);
            if (ret==0) ctr=it;
            ret ^= x;
            it++;
        }
        bool flag = true;
        if (ret==0) flag = false;
        for (int i = 0; i < ctr; i++) {
            if (ret==A[i]) {
                flag = false;
            }
        }
        if (flag) cout << "NO\n";
        else cout << "YES\n";
    }
    return 0;
}*/
