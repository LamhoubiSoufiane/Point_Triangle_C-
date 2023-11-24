#ifndef SRC_TP1_H_
#define SRC_TP1_H_

//Classe Point

class Point
{
    private:
        double coordX;
        double coordY;
    public:
        Point();//constructeur
        ~Point();
        Point(Point &p);
        void saisie();//permet de fixer les coordonnées du point
        void afficher();//affiche les coordonnées du point
        void translater(double x,double y);//pour deplacer le point
        void echelle(double sx,double sy);//changement d echelle
        double distance(Point pt);
};

//Classe Triangle

class Triangle
{
    private:
        Point sommet[3];
    public:
        Triangle();
        ~Triangle();
        Triangle(Triangle &tr);
        void saisieTr();
        void afficherTr();
        void translaterTr(double x,double y);
        void echelleTr(double sx,double sy);
        void coteTr(double cotes[3]);
        bool isocele(double cotes[3]);
        bool equilateral(double cotes[3]);
        double perimetre(double cotes[3]);
};

#endif