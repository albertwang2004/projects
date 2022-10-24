/*#include <bits/stdc++.h>
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define p push
#define ins insert
#define t top
#define fr front
#define H 101
#define MOD 1000000007
#define INF 999999

using namespace std;
typedef long long int LL;
typedef pair<int,int> pii;

void fl() {
    cout << endl; cout.flush();
}

int N;
queue<pii> A;
queue<pii> B;
int main() {
    scanf("%d",&N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if ((i+j)%2==0) A.p(mp(i+1,j+1));
            else B.p(mp(i+1,j+1));
        }
    }
    while (1) {
        int x;
        scanf("%d",&x);
        if (A.size()==0) {
            int put = 3-x;
            if (x==3) put = 1;
            pii pos = B.fr();
            B.pop();
            cout << put << " " << pos.f << " " << pos.s;
        } else if (B.size() == 0) {
            int put = 4-x;
            if (x==2) put = 1;
            pii pos = A.fr();
            A.pop();
            cout << put << " " << pos.f << " " << pos.s;
        } else if (x!=3) {
            pii pos = A.fr();
            A.pop();
            cout << 3 << " " << pos.f << " " << pos.s;
        } else {
            pii pos = B.fr();
            B.pop();
            cout << 2 << " " << pos.f << " " << pos.s;
        }
        fl();
        if (A.size()+B.size()==0) break;
    }
}*/
