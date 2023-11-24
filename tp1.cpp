
#include "main.hpp"
#include "tp1.hpp"






/*****************************************************************/
Point::Point()
{
    coordX=0.0;
    coordY=0.0;
}

Point::~Point()
{
    
}

Point::Point(Point &p)
{
    coordX=p.coordX;
    coordY=p.coordY;
}

void Point::saisie()
{
    cout<<"\n saisissez la valeur de la coordonnee X : ";
    cin>>coordX;
    cout<<"\nsaisissez la valeur de la coordonnee Y : ";
    cin>>coordY;
}

void Point::afficher()
{
    cout<<"\nLes coordonnees du point sont : X = "<<coordX<<" ; Y = "<<coordY;
}

void Point::translater(double x,double y)
{
    coordX += x;
    coordY += y;
}
/*
un changement d'échelle modifie la taille d'un point en multipliant 
ses coordonnées par des facteurs d'échelle spécifiques pour chaque axe
*/
void Point::echelle(double sx,double sy)
{
    coordX *=sx;
    coordY *=sy;
}

double Point::distance(Point pt)
{
    return (sqrt(pow((pt.coordX-coordX),2)+pow((pt.coordY-coordY),2)));
}


/******* T R I A N G L E ******/

void Triangle::saisieTr()
{
    for(int i=0;i<3;i++) sommet[i].saisie();
}

Triangle::~Triangle()
{
    for(int i=0;i<3;i++) sommet[i].~Point();
    // delete[] sommet;
}

Triangle::Triangle(Triangle &tr)
{
    for(int i=0;i<3;i++) sommet[i]=tr.sommet[i];
}

Triangle::Triangle()
{
    Point p1,p2,p3;
    sommet[0]=p1;
    sommet[1]=p2;
    sommet[2]=p3;
}
void Triangle::afficherTr()
{
    cout<<"\nles coordonnees des points de votre triangle sont : ";
    for(int i=0;i<3;i++)
    {
        cout<<"\n/******************/";
        cout<<"\n Pour le point "<<i+1<< " : ";
        sommet[i].afficher();
    }
} 

void Triangle::translaterTr(double x, double y)
{
    for(int i=0;i<3;i++) sommet[i].translater(x,y);
}

void Triangle::echelleTr(double sx,double sy)
{
    for(int i=0;i<3;i++) sommet[i].echelle(sx,sy);
}

void Triangle::coteTr(double cotes[3])
{
    for(int i=0;i<2;i++) cotes[i]=sommet[i].distance(sommet[i+1]);
    cotes[2]=sommet[2].distance(sommet[0]);
    //affichage 
    for(int i=0;i<3;i++)
    {
        cout<<"\n longueur du cote "<<i+1<<" : "<<cotes[i];
    }
}

bool Triangle::isocele(double cotes[3])
{
    if(cotes[0] == cotes[1]) 
    {
        if(cotes[0] != cotes[2]) return true;
        else return false;
    }   
    else if(cotes[0] == cotes[2]) return true;
    else if(cotes[1] == cotes [3]) return true;
    else return false;
}

bool Triangle::equilateral(double cotes[3])
{
    if(cotes[0] == cotes[1] == cotes[3]) return true;
    return false;
}

double Triangle::perimetre(double cotes[3])
{
    double p=cotes[0];
    p+=cotes[1];
    p+=cotes[2];
    return p ;
}



