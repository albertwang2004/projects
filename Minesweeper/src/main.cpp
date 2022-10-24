#include <vector>
#include <string>
#include <iostream>
#include <utility>
#include <map>
#include <queue>
#include <list>

#define pb push_back
#define f first
#define s second
#define mp make_pair
#define p push
#define fr front

#include "minesweeper.h"

using namespace std;
typedef pair<int,int> pii;

pair<double,pair<double,double>> rgbtohsl(sf::Color c) {
    double R = c.r/255.0;
    double G = c.g/255.0;
    double B = c.b/255.0;
    double cmax = max(R,max(G,B));
    double cmin = min(R,min(G,B));
    double delt = cmax-cmin;
    double H,S,L;
    if (delt==0) H=0;
    else if (cmax==R) {
        double thing = (G-B)/delt;
        while (thing >= 6) thing -= 6;
        while (thing < 0) thing += 6;
        H = 60*thing;
    }
    else if (cmax==G) H=60*(((B-R)/delt)+2);
    else if (cmax==B) H=60*(((R-G)/delt)+4);
    L = (cmax+cmin)/2.0;
    double x = 2*L-1;
    if (x<0) x = -x;
    S = delt/(1-x);
    return {H,{S,L}};
}
sf::Color hsltorgb(pair<double,pair<double,double>> c) {
    double H = c.f;
    double S = c.s.f;
    double L = c.s.s;
    double x = 2*L-1;
    if (x<0) x = -x;
    double C = (1-x)*S;
    double h = H/60;
    while (h >= 2) h -= 2;
    while (h < 0) h += 2;
    h-=1;
    if (h < 0) h = -h;
    double X = C*(1-h);
    double m = L-C/2;
    double R,G,B;
    if (H < 60) R = C;
    else if (H < 120) R = X;
    else if (H < 180) R = 0;
    else if (H < 240) R = 0;
    else if (H < 300) R = X;
    else if (H < 360) R = C;
    if (H < 60) G = X;
    else if (H < 120) G = C;
    else if (H < 180) G = C;
    else if (H < 240) G = X;
    else if (H < 300) G = 0;
    else if (H < 360) G = 0;
    if (H < 60) B = 0;
    else if (H < 120) B = 0;
    else if (H < 180) B = X;
    else if (H < 240) B = C;
    else if (H < 300) B = C;
    else if (H < 360) B = X;
    return sf::Color((R+m)*255,(G+m)*255,(B+m)*255);
}

int main() {
    ifstream fin("boards/config.cfg");
    int x,y,z; fin>>x>>y>>z;
    minesweeper game = minesweeper(x,y,z);
    //game.refill("boards/testboard2.brd");
    //game.print(true);
    //game.play(false);
    int w = 1024; int h = 512;
    int samples = 1024;
    sf::RenderWindow window(sf::VideoMode(w,h),"Gradient");
    sf::Color p1(128, 0, 0);
    sf::Color p2(0, 128, 128);
    bool inv = 1;
    if (!inv) {
        pair<double,pair<double,double>> hsl1,hsl2;
        hsl1 = rgbtohsl(p1);
        hsl2 = rgbtohsl(p2);
        double dh = (hsl2.f-hsl1.f)/samples;
        double ds = (hsl2.s.f-hsl1.s.f)/samples;
        double dl = (hsl2.s.s-hsl1.s.s)/samples;
        for (int i = 0; i < samples; i++) {
            sf::ConvexShape c;
            c.setPointCount(4);
            c.setPoint(0,sf::Vector2f(w*i/samples,0));
            c.setPoint(1,sf::Vector2f(w*(i+1)/samples,0));
            c.setPoint(2,sf::Vector2f(w*(i+1)/samples,h));
            c.setPoint(3,sf::Vector2f(w*i/samples,h));
            c.setFillColor(hsltorgb(hsl1));
            hsl1.f+=dh;
            hsl1.s.f+=ds;
            hsl1.s.s+=dl;
            window.draw(c);
        }
    } else {
        pair<double,pair<double,double>> hsl1,hsl2,curr;
        hsl1 = rgbtohsl(p1);
        hsl2 = rgbtohsl(p2);
        if (hsl2.f<hsl1.f) hsl2.f+=360;
        if (hsl2.f>hsl1.f) hsl2.f-=360;
        double dh = (hsl2.f-hsl1.f)/samples;
        double ds = (hsl2.s.f-hsl1.s.f)/samples;
        double dl = (hsl2.s.s-hsl1.s.s)/samples;
        for (int i = 0; i < samples; i++) {
            sf::ConvexShape c;
            c.setPointCount(4);
            c.setPoint(0,sf::Vector2f(w*i/samples,0));
            c.setPoint(1,sf::Vector2f(w*(i+1)/samples,0));
            c.setPoint(2,sf::Vector2f(w*(i+1)/samples,h));
            c.setPoint(3,sf::Vector2f(w*i/samples,h));
            curr = hsl1;
            while (curr.f>=360) curr.f-=360;
            while (curr.f<0) curr.f+=360;
            c.setFillColor(hsltorgb(curr));
            hsl1.f+=dh;
            hsl1.s.f+=ds;
            hsl1.s.s+=dl;
            window.draw(c);
        }
    }
        window.display();
    while (window.isOpen()) {
        sf::Event e;
        while (window.pollEvent(e)) {
            if (e.type == sf::Event::Closed)
                window.close();
        }
    }

    /*
    minesweeper game = minesweeper(10, 10, 3);
    game.print(false);
    while (!game.done()) {
        int z, x, y;
        cin >> z >> x >> y;
        if (z==0) {
            if (game.peek(mp(x,y))) {game.print(false);}
            else {cout << "kaboom" << endl; break;}
        } else if (z==1) {
            game.flag(mp(x,y));
            game.print(false);
        } else {break;}
    }
    cout << "end" << endl;
    game.print(true);*/
    return 0;
}
