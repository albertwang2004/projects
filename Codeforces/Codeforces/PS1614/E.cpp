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

#define woof 31051
#define mod 998244353
#define MOD 1000000007
#define lnf 0
#define inf 1069999999
#define INF 2099999999
#define LNF 5e18

#define tc(T) template <class T>
#define tcc(S, T) template <class S, class T>
#define tccc(S, T, U) template <class S, class T, class U>

using namespace std;
mt19937 mr(time(0));
typedef long long int ll;
typedef string str;
typedef double dbl;
struct LL {

    static ll m; // set to LNF for nomod
    long long int val;

    LL(ll v) {val=reduce(v);};
    LL(int v) {val=reduce((ll)v);};
    LL() {val=0;};
    ~LL(){};
    LL(const LL& l) {val=l.val;};
    LL& operator=(int l) {val=l; return *this;}
    LL& operator=(ll l) {val=l; return *this;}
    LL& operator=(LL l) {val=l.val; return *this;}

    static void setMod(ll m) { assert(m); LL::m = m; }

    static long long int reduce(ll x, ll md = m) {
        x %= md;
        while (x >= md) x-=md;
        while (x < 0) x+=md;
        return x;
    }

    bool operator<(const LL& b) { return val<b.val; }
    bool operator<=(const LL& b) { return val<=b.val; }
    bool operator!=(const LL& b) { return val!=b.val; }
    bool operator==(const LL& b) { return val==b.val; }
    bool operator>=(const LL& b) { return val>=b.val; }
    bool operator>(const LL& b) { return val>b.val; }

    LL operator+(const LL& b) { return LL(val+b.val); }
    LL operator+(const ll& b) { return (*this+LL(b)); }
    LL& operator+=(const LL& b) { return (*this=*this+b); }
    LL& operator+=(const ll& b) { return (*this=*this+b); }

    LL operator-(const LL& b) { return LL(val-b.val); }
    LL operator-(const ll& b) { return (*this-LL(b)); }
    LL& operator-=(const LL& b) { return (*this=*this-b); }
    LL& operator-=(const ll& b) { return (*this=*this-b); }

    LL operator*(const LL& b) { return LL(val*b.val); }
    LL operator*(const ll& b) { return (*this*LL(b)); }
    LL& operator*=(const LL& b) { return (*this=*this*b); }
    LL& operator*=(const ll& b) { return (*this=*this*b); }

    static LL exp(const LL& x, const ll& y){
        ll z = y;
        z = reduce(z,m-1);
        LL ret = 1;
        LL w = x;
        while (z) {
            if (z&1) ret *= w;
            z >>= 1; w *= w;
        }
        return ret;
    }
    LL& operator^=(ll y) { return (*this=LL(val^y)); }

    LL operator/(const LL& b) { return ((*this)*exp(b,-1)); }
    LL operator/(const ll& b) { return (*this/LL(b)); }
    LL operator/=(const LL& b) { return ((*this)*=exp(b,-1)); }
    LL& operator/=(const ll& b) { return (*this=*this/LL(b)); }

}; ostream& operator<<(ostream& os, const LL& obj) { return os << obj.val; }
ll LL::m = MOD;

typedef pair<int,int> pii;
typedef pair<int,ll> pil;
typedef pair<int,LL> piL;
typedef pair<ll,ll> pll;
typedef pair<LL,LL> pLL;
typedef pair<dbl,dbl> pdd;
using namespace std;
// sacrilege

#define bts(a,x,b) ((a<x)&&(x<b))
#define btw(a,x,b) ((a<=x)&&(x<=b))

#define F0(x,n) for(ll x = 0; x < n; ++x)
#define Fr(x,L,R) for(ll x = L; x < R; ++x)
#define R0(x,n) for(ll x = n-1; x >= 0; --x)
#define F1(x,n) for(ll x = 1; x <= n; ++x)
#define FR(x,L,R) for(ll x = L; x <= R; ++x)
#define R1(x,n) for(ll x = n; x >= 1; --x)
#define RR(x,L,R) for(ll x = R; x >= L; --x)
#define Rr(x,L,R) for(ll x = R-1; x >= L; --x)
#define FE(x,ls) for(auto x : ls)
#define FER(x,ls) for(auto &x : ls)

#define srt(x) sort(x.begin(),x.end())
#define srtc(x,c) sort(x.begin(),x.end(),c)
#define rev(x) reverse(x.begin(),x.end())

#define UB upper_bound
#define LB lower_bound
#define ub(x,v) upper_bound(x.begin(),x.end(),v)
#define lb(x,v) lower_bound(x.begin(),x.end(),v)
#define bs(x,v) binary_search(x.begin(),x.end(),v)
#define dst(x,y) (ll)distance(x,y)
#define nlt(x,v) (ll)dst(x.begin(),lb(x,v))
#define nle(x,v) (ll)dst(x.begin(),ub(x,v))

class oset {
public:
    struct Node {                                                               /// STRUCT FOR AVL NODES

        int id;
        Node* left;                                                             // left child
        Node* right;                                                            // right child

        int height;                                                             // height of node
        int nodeCount;                                                          // number of nodes in this subtree

        int leftHeight() {                                                      /// Height of left child
            if (left == nullptr) return 0;
            else return left->height;
        }

        int rightHeight() {                                                     /// Height of right child
            if (right == nullptr) return 0;
            else return right->height;
        }

        int leftNodeCount() {                                                   /// Node count of left child
            if (left == nullptr) return 0;
            else return left->nodeCount;
        }

        int rightNodeCount() {                                                  /// Node count of right child
            if (right == nullptr) return 0;
            else return right->nodeCount;
        }


        void update() {                                                         /// Update the height and nodeCount for this node
            height = 1 + max(leftHeight(), rightHeight());
            nodeCount = 1 + leftNodeCount() + rightNodeCount();
        }


        Node(int ID = 0,                                   /// NODE CONSTRUCTOR
                Node* LEFT = nullptr, Node* RIGHT = nullptr) {                  /// DEFAULTS TO LEAF
            id = ID;
            left = LEFT;
            right = RIGHT;
            update();
        }




    };

    Node* tree;
    oset() {
        tree = nullptr;
    }




    ///////////
    // DEBUG //
    ///////////

    void printTree() { printTree(tree); }
    void printTree(Node* node, int depth = 0) {                                 /// DEBUG ONLY
        for (int d = 0; d < depth; d++) cout << "    ";
        if (node == nullptr) cout << "nullptr" << endl;
        else {
            ++depth;
            for (int d = 0; d < depth-1; d++) cout << "    ";cout << "Left child {" << endl;
            printTree(node->left,depth);

            for (int d = 0; d < depth-1; d++) cout << "    ";cout << "} Right Child {" << endl;
            printTree(node->right,depth);

            for (int d = 0; d < depth-1; d++) cout << "    ";cout << "}" << endl;
        }
    }

    int sz() { return (tree==nullptr)?0:(tree->nodeCount); }
    int NLE(int a) { return NLE(a,tree); }
    int NLE(int a, Node* node) {
        if (node == nullptr) return 0;
        if (node->id>a) return NLE(a,node->left);
        else return NLE(a,node->right) + 1+((node->left==nullptr)?0:node->left->nodeCount);
    }
    int NLT(int a) {return NLE(a-1);}


    ///////////////////
    // NODE ROTATION //
    ///////////////////

    Node* rotateLeft(Node *node) {                                              /// ROTATE node LEFT (requirement: has right child)
                                                                                /// returns new root

        if (node == nullptr) return node;                                       // unsuccessful rotation.
        if (node->right == nullptr) return node;                                // unsuccessful rotation.

        Node* ret = node->right;                                                // this will be the returned node
        node->right = ret->left;                                                // move the new root
        ret->left = node;                                                       // link the past root to the new root

        ret->left->update();                                                    // update height of new left node
        ret->update();                                                          // update height of new root

        return ret;
    }


    Node* rotateRight(Node* node) {                                             /// ROTATE node RIGHT (requirement: has left child)
                                                                                /// returns new root

        if (node == nullptr) return node;                                       // unsuccessful rotation.
        if (node->left == nullptr) return node;                                 // unsuccessful rotation.

        Node* ret = node->left;                                                 // this will be the returned node
        node->left = ret->right;                                                // move the new root
        ret->right = node;                                                      // link the past root to the new root

        ret->right->update();                                                   // update height of new right node
        ret->update();                                                          // update height of new root

        return ret;
    }




    ///////////////////////
    // HELPFUL FUNCTIONS //
    ///////////////////////


    pair<Node*,Node*> searchAndBalanceHelper(int id, Node* node) {              /// HELPER: SIMULTANEOUSLY SEARCH AND BALANCE A TREE FOR UFID id FROM node
                                                                                /// returns a pair {the desired node or nullptr if not found, the root}

        pair<Node*,Node*> ret = make_pair(nullptr, nullptr);                    // this will be the returned value

        if (node == nullptr) return ret;                                        // if there is nothing to search
        else if (id == node->id) ret.first = node;                              // if the desired node is found
        else if (id < node->id) {                                               // if we need to look on the left
            ret = searchAndBalanceHelper(id, node->left);                       //     recurse
            node->left = ret.second;                                            //     update node's left child
        } else {                                                                // if we need to look on the right
            ret = searchAndBalanceHelper(id, node->right);                      //     recurse
            node->right = ret.second;                                           //     update node's right child
        }

        node->update();

        while (node->leftHeight() - node->rightHeight() >= 2) {                 // while this node is skewed, rotate it
            if (node->left->id < id)                                        // R-L rotation case
                node->left = rotateLeft(node->left);
            node = rotateRight(node);
            return make_pair(ret.first, node);
        }

        while (node->rightHeight() - node->leftHeight() >= 2) {                 // repeat for other direction
            if (node->right->id > id)                                            // L-R rotation case
                node->right = rotateRight(node->right);
            node = rotateLeft(node);
            return make_pair(ret.first, node);
        }

        return make_pair(ret.first, node);
    }


    pair<Node*,Node*> searchAndBalanceHelper(Node* key, Node* node) {           /// Overloads the above function, searching for a Node* instead
        return searchAndBalanceHelper(key->id, node);
    }


    Node* findParent(Node* key, Node* node) {                                   /// HELPER: FINDS PARENT NODE OF key IN node
                                                                                /// returns desired node, or the node if it's the root, or nullptr if fail
        if (node == nullptr) return nullptr;                                    // fail
        if (key->id == node->id) return key;                                    // found key

        else if (key->id < node->id) {                                          // look left

            Node* ret = findParent(key, node->left);                            //     recurse
            if (ret == key) return node;                                        //     found the parent node
            else return ret;                                                    //     carry result

        } else {                                                                // look right

            Node* ret = findParent(key, node->right);                           //     recurse
            if (ret == key) return node;                                        //     found the parent node
            else return ret;                                                    //     carry result

        }
    }


    Node* findParent(int id, Node* node) {                                      /// Overloads the above function with a slightly different return result
                                                                                /// returns desired node, or nullptr if fail
        Node* key = new Node(id);                                               // dummy node
        Node* ret = findParent(key, node);                                      // call helper

        if (ret == key) ret = nullptr;                                          // adjust result
        return ret;
    }


    Node* findInorder(int num, Node* node) {                                    /// HELPER: FINDS numTH NODE IN INORDER, 0-INDEXED
                                                                                /// returns desired Node* if found, nullptr if out of range
        if (node == nullptr) return nullptr;                                    // bad
        else if (num < 0) return nullptr;                                       // negative is bad
        else if (num >= node->nodeCount) return nullptr;                        // too big, also bad

        else if (num == node->leftNodeCount()) return node;                     // we found it!
        else if (num > node->leftNodeCount())                                   // we want to look in the right tree
            return findInorder(num-node->leftNodeCount()-1, node->right);       // adjust index accordingly
        else return findInorder(num, node->left);                               // we want to look in left tree
    }




    /////////////////////////
    // INSERTION FUNCTIONS //
    /////////////////////////


    Node* insertNodeHelp(Node* key, Node* node) {                               /// HELPER FUNCTION FOR insertNode(), INSERTS key INTO node != nullptr
                                                                                /// returns the inserted node, or nullptr if it fails

        if (node->id == key->id) return nullptr;                                // insertion failure (duplicate)
        else if (node->id > key->id) {                                          // look on the left

            if (node->left == nullptr) return node->left = key;                 //     we're done!
            else return insertNodeHelp(key, node->left);                        //     recurse left

        } else {                                                                // look on the right

            if (node->right == nullptr) return node->right = key;               //     we're done!
            else return insertNodeHelp(key, node->right);                       //     recurse right

        }
    }


    pair<bool,Node*> insertNode(Node* key, Node* node) {                        /// INSERTS key INTO node AND BALANCES & UPDATES AFFECTED HEIGHTS
                                                                                /// returns a pair (1 if successful or 0 if not, the root)

        Node* ret;                                                              // returned Node* from helper, or the root if tree is initially empty
        if (node == nullptr) ret = (node = key);                                // tree is empty, put node at the root
        else ret = insertNodeHelp(key, node);                                   // tree is not empty, call helper function

        if (ret == nullptr) return make_pair(0,node);
        else {

            pair<Node*,Node*> found = searchAndBalanceHelper(key,node);         // finds the newly inserted node, while balancing and updating heights
            Node* chk = found.first;
            node = found.second;
            assert(chk == ret);                                                 // if this assertion fails, then at least one of the search or insertion functions broke
            return make_pair(1,node);

        }
    }


    pair<bool,Node*> insertNode(int id, Node* node) {              /// Overloads the above function, input node by values instead
        return insertNode(new Node(id), node);
    }

    void ins(int id) {
        tree = insertNode(id, tree).second;
    }



    ///////////////////////
    // REMOVAL FUNCTIONS //
    ///////////////////////


    pair<bool,Node*> removeNodeHelper(Node* found, Node* node) {                /// Helper TRIES TO REMOVE key FROM node
                                                                                /// returns a pair (successful?, new root)

        if (found==nullptr) return make_pair(0,node);                           // failure

        int deg = 0 + ((found->left != nullptr)?1:0)                            // count the children (outdegree) of found
                    + ((found->right != nullptr)?2:0);
                                                                                // hashed as follows: 0 - leaf,
                                                                                // 1 - left only, 2 - right only, 3 - both

        int id = found->id;                                                     // get ids for comparisons later on
        int parentId;
        Node* parent = findParent(id, node);                                    // find the parent
        if (parent == nullptr) parentId = -69;                                  // gotta check for nullptr too
        else parentId = parent->id;

        pair<bool,Node*> ret;                                                   // the output value

        if (deg == 0) {                                                         // this is a leaf

            if (parent != nullptr) {                                            // in the case that a parent node exists

                if (id<parentId) parent->left = nullptr;                        // key is parent's left child
                else parent->right = nullptr;                                   // key is parent's right child
                ret = make_pair(1,node);

            } else {
                ret = make_pair(1,nullptr);                                     // there is no parent and the tree is empty
            }

        }

        if (deg == 1) {

            if (parent != nullptr) {                                            // in the case that a parent node exists

                if (id<parentId) parent->left = found->left;                    // key is parent's left child
                else parent->right = found->left;                               // key is parent's right child
                ret = make_pair(1,node);

            } else {
                ret = make_pair(1,node->left);                                  // there is no parent, return left child as root
            }

        }

        if (deg == 2) {

            if (parent != nullptr) {                                            // in the case that a parent node exists

                if (id<parentId) parent->left = found->right;                   // key is parent's left child
                else parent->right = found->right;                              // key is parent's right child
                ret = make_pair(1,node);

            } else {
                ret = make_pair(1,node->right);                                 // there is no parent, return left child as root
            }

        }

        if (deg == 3) {


            Node* successor = found->right;                                     // look for the inorder successor
            Node* parentOfSuccessor = found;                                    // we will have to disconnect the successor from its parent

            while (successor->left != nullptr) {                                // dig left until we can't go further

                parentOfSuccessor = successor;
                successor = successor->left;

            }

            if (successor != found->right) {                                    // cut from parent if necessary

                parentOfSuccessor->left = successor->right;
                successor->right = found->right;                                // link right part of tree to successor

            }

            successor->left = found->left;                                      // link left part of tree to successor

            if (parent != nullptr) {                                            // in the case that a parent node exists

                if (id<parentId) parent->left = successor;                      // key is parent's left child
                else parent->right = successor;                                 // key is parent's right child
                ret = make_pair(1,node);

            } else {
                ret = make_pair(1,successor);                                   // there is no parent, return successor as root
            }

        }

        ret.second = searchAndBalanceHelper(id+1,ret.second).second;

        return ret;

    }


    pair<bool,Node*> removeNode(Node* key, Node* node) {                        /// TRIES TO REMOVE key ID FROM node
                                                                                /// returns same as above
        pair<Node*,Node*> ret = searchAndBalanceHelper(key, node);              // look for node
        Node* found = ret.first;                                                // update values
        node = ret.second;
        return removeNodeHelper(found, node);
    }


    pair<bool,Node*> removeNode(int idx, Node* node) {                          /// TRIES TO REMOVE nth INDEX FROM node INORDER, 0-INDEXED
                                                                                /// returns same as above
        Node* key = findInorder(idx,node);                                      // call helper
        if (key == nullptr) return make_pair(false,node);                       // key doesn't exist
        else return removeNodeHelper(key,node);                                 // found it, keep removing
    }




    ////////////////
    // TRAVERSALS //
    ////////////////


    void printInorderHelperL(Node* node) {                                      /// Helper for inorder that prints commas after names

        if (node!=nullptr) {

            printInorderHelperL(node->left);
            cout << node->id << ", ";
            printInorderHelperL(node->right);

        }

    }


    void printInorderHelperR(Node* node) {                                      /// Helper for inorder that prints commas before names

        if (node!=nullptr) {

            printInorderHelperR(node->left);
            cout << ", " << node->id;
            printInorderHelperR(node->right);

        }

    }


    void printInorder(Node* node) {                                             /// Prints a ,-delimited inorder traversal

        if (node!=nullptr) {

            printInorderHelperL(node->left);
            cout << node->id;
            printInorderHelperR(node->right);

        }

        cout << endl;

    }

};

ll cases,N,M,Q,K,X,Y;

ll rd() {ll x;cin>>x; return x;}
dbl rdd() {dbl x;cin>>x; return x;}
str rds() {str x;cin>>x; return x;}
tc(T) void rds(char* S, T* sz) {*sz=strlen(strcpy(S,rds().c_str()));}
tc(T) void rG(int sz, vector<vector<T>>& adj, int E = -18852946) {
    if (E == -18852946) E = sz-1;
    adj.clear();
    F0(i,sz+1) adj.pb(vector<T>());
    F0(i,E) {
        T a = rd(); T b = rd();
        adj[a].pb(b); adj[b].pb(a);
    }
}

void fl() {cout.flush();}
void ds(int v) { cout << v << " "; }
void ds(ll v) { cout << v << " "; }
void ds(LL v) { cout << v << " "; }
void ds(dbl v) { cout << v << " "; }
void ds(char v) { cout << v << " "; }
void ds(str v) { cout << v << " "; }
void ds(char* v) { cout << v << " "; }
tcc(S,T) void ds(pair<S,T> v) {cout << v.f << " " << v.s << endl;}
tc(T) void ds(vector<T> v) { FE(x,v) ds(x); cout << endl; }
tc(T) void panic(T out) { ds(out); exit(0); }

tcc(S,T) bool updmin(S &a, T b) {
    S B = (S)b;
    if (B < a) {a = B; return 1;}
    return 0;
}

tcc(S,T) bool updmax(S &a, T b) {
    S B = (S)b;
    if (B > a) {a = B; return 1;}
    return 0;
}

tcc(S,T) S min(S a, T b) {
    S c = a; updmin(c, b); return c;
}

tcc(S,T) S max(S a, T b) {
    S c = a; updmax(c, b); return c;
}

// witness
bool witness(LL a, ll d, ll m) {
    LL x = LL::exp(a,m);
    if (x==LL(1)) return 1;
    F0(r,d) {
        if (x==LL(-1)) return 1;
        x = x*x;
    }
    return 0;
}

// O(log^3 n) test
bool isPrime(ll x) {
    if (x < T6) {
        int j = 2;
        while (j*j <= x) {
            if (x%j==0) return 0;
            ++j;
        }
        return 1;
    }
    ll d = 0;
    ll m = 0;
    ll y = x;
    ll cur = LL::m;
    LL::m = x;
    bool ret = 1;
    while (y>>=1) {
        ++d; if (y&1) break;
    }
    m = y;
    if (x < 1e12) {
        ret = witness(2,d,m)
            && witness(13,d,m)
            && witness(23,d,m)
            && witness(1662803,d,m);
    } else {
        ret = witness(2,d,m)
            && witness(3,d,m)
            && witness(5,d,m)
            && witness(7,d,m)
            && witness(11,d,m)
            && witness(13,d,m)
            && witness(17,d,m)
            && witness(19,d,m)
            && witness(23,d,m)
            && witness(29,d,m)
            && witness(31,d,m)
            && witness(37,d,m)
            && witness(41,d,m);
    }
    LL::m = cur;
    return ret;
}

#define H 3*H5
#define HH 43

ll gcd(ll a, ll b) {
    return b?gcd(b, a % b):a;
}

void precalc() {
}

void reset() {
}

bool cmp(pii a, pii b) {
    return (a.s==b.s)?(a.f<b.f):(a.s<b.s);
}

bool debug = 0;

oset S = oset();
int ans(int Q) {
    return Q+(S.sz()>>1)-S.NLT(Q);
}
int fn(int x) {
    int L = x-200069;
    int R = x+200069;
    while (L<R-1) {
        int M = (L+R)>>1;
        //cout << "fn " << x << " " << L << " " << R << " " << M << endl;
        if (ans(M)<=x) L=M;
        else R=M;
    }
    return L;
}

void read() {
    N = rd();
    int LASTANS = 0;
    F1(i,N) {
        X = rd(); K = rd();
        int a = fn(X);
        int b = fn(X-1);
        //cout << "inserting " << a << " " << b << endl;
        S.ins(a);
        S.ins(b);
        F0(j,K) {
            Q = (LASTANS+rd())%(MOD-6);
            cout << (LASTANS=ans(Q)) << endl;
        }
    }
}


int main() {

    precalc();

    bool trials = 0;
    bool interactive = 0;

    if (!interactive) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
    }

    if (trials) cases=rd();
    else cases=1;
    while (cases--) {
        read();
    }

}
*/
