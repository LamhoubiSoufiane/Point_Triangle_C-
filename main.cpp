#include "main.hpp"
#include "tp1.cpp"


int main()
{
    Point p1;
    p1.saisie();
    p1.afficher();
    Point p2(p1);
    p2.afficher();
    Triangle tr;
    double cote[3];
    for(int i=0;i<3;i++) cote[i]=0.0;
    tr.saisieTr();
    tr.~Triangle();
    tr.afficherTr();
    cout<<"\n/********************/\n";
    Triangle tr2(tr);
    tr2.afficherTr();
    tr.coteTr(cote);
}