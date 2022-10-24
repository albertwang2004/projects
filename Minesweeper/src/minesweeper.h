#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <utility>
#include <map>
#include <queue>
#include <list>
#include <SFML/Graphics.hpp>

using namespace std;
typedef pair<int,int> pii;

class minesweeper {
public:
    minesweeper();
    minesweeper(int N, int M);
    minesweeper(int N, int M, int mm);
    void refill(string filename);
    void reset(); // fill 0s
    void classic(); // load in adj for kingsweeper
    bool done(); // T iff win
    int peek(pii x); // T if ok, F if boom
    int eval(pii x); // gives the number of mines surrounding tile x
    void mines(int x); // generate x mines, returns mines
    bool inbound(pii x); // check if x is in the board
    void print(bool cheat); // can't hurt to have this
    bool flag(pii x);
    void load(string fn, int w, int h);
    void spr();
    void place(string fn, int i, int j, sf::RenderWindow& window);
    void placenum(string fn, int x, int y, int tx, int ty, int w, int h, sf::RenderWindow& window);
    int play(bool cheat); // huge function that literally does everything


private:
    int N,M,mm,rev,F,setmines;
    char state; // 'a' if active, 'w' if win, 'l' if lose
    list<pii> good;
    map<pii,int> board; // 100 if mine
                        // add 10000 for flagged square
                        // add 1000000 for unknown square
    vector<pii> adj; // what is "adjacent"
    map<string,sf::Texture> textures;
};
