#include "minesweeper.h"
#include "Random.h"
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <utility>
#include <map>
#include <queue>
#include <list>
#include <SFML/Graphics.hpp>
#include <chrono>
#include <sys/time.h>
#include <ctime>

#define pb push_back
#define f first
#define s second
#define mp make_pair
#define p push
#define fr front
using namespace std;
typedef pair<int,int> pii;
typedef long long int LL;
#include <sys/timeb.h>

int getMilliCount(){
	timeb tb;
	ftime(&tb);
	int nCount = tb.millitm + (tb.time & 0xfffff) * 1000;
	return nCount;
}

    minesweeper::minesweeper() : N(0), M(0), mm(0), rev(0), F(0), state('a'), setmines(0) {};
    minesweeper::minesweeper(int N, int M) : N(N), M(M), mm(0), rev(0), F(0), state('a'), setmines(0) {
        reset();
        classic();
    }
    minesweeper::minesweeper(int N, int M, int mm) : N(N), M(M), mm(0), rev(0), F(0), state('a'), setmines(mm) {
        reset();
        classic();
        mines(mm);
    }
    void minesweeper::refill(string filename) {
        ifstream fin(filename);
        mm=0;
        for (int i = 1; i <= M; i++) {
            string x; fin >> x;
            for (int j = 1; j <= N; j++) {
                board[mp(j,i)]=100*((int)(x.at(j-1)-'0'));
            }
        }
        for (int i = 1; i <= M; i++) {
            for (int j = 1; j <= N; j++) {
                if (board[mp(j,i)]==100) {
                    mm++;
                    for (pii n : adj) {
                        pii curr = mp(j-n.f,i-n.s);
                        if (board[curr]!=100) board[curr]=board[curr]+1;
                    }
                }
            }
        }
    }
    void minesweeper::reset() {
        F=0;rev=0;mm=setmines;
        good=list<pii>();
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= M; j++) {
                good.pb(mp(i,j));
                board[mp(i,j)]=0;
            }
        }
    }
    void minesweeper::classic() { // load in adj for kingsweeper
        ifstream fin("boards/adj.cfg");
        int numAdj; fin >> numAdj;
        for (int i = 0; i < numAdj; i++) {
            int adjx,adjy; fin >> adjx >> adjy;
            adj.pb(mp(adjx,adjy));
        }
    }
    bool minesweeper::done() {return (rev==N*M-mm);} // T iff win
    int minesweeper::peek(pii x) { // > if ok, 0 if boom
        if (state!='a') return false;
        if (board[x]>=10000) return 69;
        if (board[x]==100) {return 0;}
        queue<pii> process;
        process.p(x);
        int i = 0;
        while (!process.empty()) {
            pii curr = process.fr();
            process.pop();
            if (board[curr]>=10000) continue;
            i++;
            board[curr]=board[curr]+1000000;
            if (board[curr]!=1000000) continue;
            for (pii n : adj) {
                pii next = mp(curr.f+n.f,curr.s+n.s);
                if (!inbound(next)) continue;
                process.p(next);
            }
        }
        rev+=i;
        return i;
    }
    int minesweeper::eval(pii x) { // gives the number of mines surrounding tile x
        return board[x]%100;
    }
    void minesweeper::mines(int x) { // generate x mines, returns mines
        mm=0;
        while (x--) {
            int y = (Random::Int(0, good.size()-1));
            list<pii>::iterator it = good.begin();
            advance(it, y);
            pii ff = *it;
            board[ff]=100;
            for (pii n : adj) {
                pii curr = mp(ff.f-n.f,ff.s-n.s);
                if (board[curr]!=100) board[curr]=board[curr]+1;
            }
            good.erase(it);
            mm++;
        }
    }
    bool minesweeper::inbound(pii x) {
        return (1<=x.f)&&(x.f<=N)&&(1<=x.s)&&(x.s<=M);
    } // check if x is in the board
    void minesweeper::print(bool cheat) {
        cout << N << " " << M << " " << mm << " " << rev << endl;
        for (int i = 1; i <= M; i++) {
            cout << i << "\t|";
            for (int j = 1; j <= N; j++) {
                int x=board[mp(j,i)];
                if (cheat && (x==100)) cout << '*';
                else if (x==1000000) cout << '.';
                else if (x>1000000) cout << x-1000000;
                else if (x>=10000) cout << 'F';
                else cout << ' ';
            }
            cout << "|\n";
        }
    }
    bool minesweeper::flag(pii x) {
        if (state!='a') return false;
        if (board[x] >= 1000000) return false;
        if ((board[x] >= 10000) && (board[x] < 1000000)) {
            board[x] = board[x] - 10000;
            F--;
            return true;
        }
        board[x] = board[x] + 10000;
        F++;
        return true;
    }

    void minesweeper::load(string fn, int w, int h) {
        sf::Texture texture;
        texture.loadFromFile("images/"+fn,
            sf::IntRect(0, 0, w, h));
        textures[fn]=texture;
    }

    void minesweeper::spr() {
        load("debug.png",64,64);
        load("digits.png",252,32);
        load("face_happy.png",64,64);
        load("face_lose.png",64,64);
        load("face_win.png",64,64);
        load("flag.png",32,32);
        load("mine.png",32,32);
        for (int i = 1; i <= 16; i++) {
            load("number_" + to_string(i) + ".png",32,32);
        }
        load("test_1.png",64,64);
        load("test_2.png",64,64);
        load("test_3.png",64,64);
        load("tile_hidden.png",32,32);
        load("tile_revealed.png",32,32);
    }

    void minesweeper::place(string fn, int i, int j, sf::RenderWindow& window) {
        sf::Sprite s(textures[fn]);
        s.setPosition(sf::Vector2f(32*(i-1),32*(j-1)));
        window.draw(s);
    }
    void minesweeper::placenum(string fn, int x, int y, int tx, int ty, int w, int h, sf::RenderWindow& window) {
        sf::Sprite s(textures[fn]);
        s.setTextureRect(sf::IntRect(tx, ty, w, h));
        s.setPosition(sf::Vector2f(x,y));
        window.draw(s);
    }

    int minesweeper::play(bool cheat) {
        int w = 32*N; int h = 32*M+88;
        sf::RenderWindow window(sf::VideoMode(w,h),"Minesweeper");
        spr();window.setKeyRepeatEnabled(false);
        LL sss = getMilliCount(); LL eee = sss;
        while (window.isOpen()) {
            sf::Event e;
            while (window.pollEvent(e)) {
                if (e.type == sf::Event::Closed)
                    window.close();
                if (((e.type == (sf::Event::KeyPressed)) && sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) || (e.mouseButton.button == sf::Mouse::Left && (e.type == sf::Event::MouseButtonPressed))) {
                    int x = sf::Mouse::getPosition(window).x/32 + 1;
                    int y = sf::Mouse::getPosition(window).y/32 + 1;
                    if (inbound(mp(x,y))) {
                        if (peek(mp(x,y))) {
                            // continue
                        } else {
                            state='l';
                            cheat=true;
                        }
                    }
                    if (N/2 <= x && x < N/2+2 && M+1 <= y && y < M+3) {
                        cheat=false;
                        reset();
                        mines(mm);
                        state='a';
                        sss = getMilliCount();
                    }
                    //if (state!='l')
                    //if (N-7 <= x && x < N-5 && M+1 <= y && y < M+3) {
                    //    cheat=!cheat;
                    //}
                    /*
                    if (N-5 <= x && x < N-3 && M+1 <= y && y < M+3) {
                        cheat=false;
                        reset();mm=0;
                        refill("boards/testboard1.brd");
                        state='a';
                    }
                    if (N-3 <= x && x < N-1 && M+1 <= y && y < M+3) {
                        cheat=false;
                        reset();mm=0;
                        refill("boards/testboard2.brd");
                        state='a';
                    }
                    if (N-1 <= x && x < N+1 && M+1 <= y && y < M+3) {
                        cheat=false;
                        reset();mm=0;
                        refill("boards/testboard3.brd");
                        state='a';
                    }*/

                }
                if (((e.type == (sf::Event::KeyPressed)) && sf::Keyboard::isKeyPressed(sf::Keyboard::X)) || (e.mouseButton.button == sf::Mouse::Right && (e.type == sf::Event::MouseButtonPressed))) {
                    int x = sf::Mouse::getPosition(window).x/32 + 1;
                    int y = sf::Mouse::getPosition(window).y/32 + 1;
                    if (inbound(mp(x,y))) {
                        flag(mp(x,y));
                    }
                }
            }
            window.clear(sf::Color::Black);

            if (done()) {
                state='w';
            }


            if (state=='a') {
                place("face_happy.png",N/2,M+1,window);
            } else if (state=='w') {
                place("face_win.png",N/2,M+1,window);
            } else if (state=='l') {
                place("face_lose.png",N/2,M+1,window);
            } else {
                cout << "unreachable state reached somehow." << endl;
            }

            // time to draw mm-F
            int disp = mm-F;
            if (disp<0) {
                placenum("digits.png",0,M*32,210,0,21,32,window);
                disp=0-disp;
            }
            int p = 0;
            for (int i = 100; i > 0; i/=10) {
                p++;
                int d = ((disp/i)%10);
                placenum("digits.png",21*p,M*32,21*d,0,21,32,window);
            }
            if (N*M-mm!=0) {
                sf::RectangleShape rectangle(sf::Vector2f(w*(((float)(rev))/(N*M-mm)),24));
                rectangle.setPosition(0, h-24);
                window.draw(rectangle);
            }
            if(state=='a') eee = getMilliCount();
            LL tt = eee-sss;
            p=9;
            for (int i = 100000; i > 100; i/=10) {
                p++;
                int d = ((int)(tt/i)%10);
                placenum("digits.png",21*p,M*32,21*d,0,21,32,window);
            }
            placenum("digits.png",21*p+21,M*32,231,0,21,32,window);
            for (int i = 100; i > 0; i/=10) {
                p++;
                int d = ((int)(tt/i)%10);
                placenum("digits.png",21*p+9,M*32,21*d,0,21,32,window);
            }
/*
            place("debug.png",N-7,M+1,window);
            place("test_1.png",N-5,M+1,window);
            place("test_2.png",N-3,M+1,window);
            place("test_3.png",N-1,M+1,window);
*/
            for (int i = 1; i <= N; i++) {
                for (int j = 1; j <= M; j++) {
                    int x = board[mp(i,j)];
                    string fn,bg;
                    if (x==100) {
                        if (cheat) {
                            fn = "mine.png";
                            bg = "tile_hidden.png";
                        } else {
                            fn = "tile_hidden.png";
                            bg = "tile_hidden.png";
                        }
                    } else if (x<100) {
                        fn = "tile_hidden.png";
                        bg = "tile_hidden.png";
                    //} else if (x==10100 && state=='l') {
                    //    fn = "mine.png";
                    //    bg = "tile_hidden.png";
                    } else if (x<1000000) {
                        fn = "flag.png";
                        bg = "tile_hidden.png";
                    } else if (x==1000000) {
                        fn = "tile_revealed.png";
                        bg = "tile_revealed.png";
                    } else {
                        int y = x-1000000;
                        fn = "number_" + to_string(y) + ".png";
                        bg = "tile_revealed.png";
                    }
                    place(bg,i,j,window);
                    place(fn,i,j,window);
                }
            }
            window.display();
        }
        return 0;
    }
