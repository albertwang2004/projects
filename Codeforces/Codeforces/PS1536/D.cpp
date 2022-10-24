/*#include <bits/stdc++.h>
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define p push
#define fr front
#define UH 2000000000
#define LH -2000000000
using namespace std;
typedef long long int LL;
typedef pair<int,int> pii;

int T,N;
int main() {
    scanf("%d",&T);
    while (T--) {
        scanf("%d",&N);
        set<int> A;
        string ret = "YES";
        A.insert(UH);
        A.insert(LH);
        int UB = UH;
        int LB = LH;
        int curr = LH;
        for (int i = 0; i < N; i++) {
            int x; scanf("%d",&x);
            A.insert(x);
            set<int>::iterator l = A.find(x);
            set<int>::iterator m = A.find(x);
            set<int>::iterator r = A.find(x);
            l--;
            r++;
            if (x==LB) {
                LB=*l;
                curr=*m;
                UB=*r;
            } else if ((LB < x)&&(x<=curr)) {
                LB=*l;
                curr=*m;
                UB=*r;
            } else if ((UB > x)&&(x>=curr)) {
                LB=*l;
                curr=*m;
                UB=*r;
            } else if (x==UB) {
                LB=*l;
                curr=*m;
                UB=*r;
            } else {
                ret="NO";
            }
        }
        cout << ret << endl;
    }
}*/
