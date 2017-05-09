#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <string>


using namespace std;

#include "./Format/CBitmap.h"

#include "./Formes/forme.h"
#include "./Formes/arc.h"
#include "./Formes/carre.h"
#include "./Formes/cercle.h"
#include "./Formes/ligne.h"
#include "./Formes/point.h"
#include "./Formes/rectangle.h"
#include "./Formes/triangle.h"

#include "./Traitement/traitement.h"


int main(int argc, char * argv[]) {
    cout << "(II) P_Bitmap exection start (" << __DATE__ << " - " << __TIME__ << ")" << endl;
    cout << "(II) + Number of arguments = " << argc << endl;

    cout << "(II) CBitmap object creation" << endl;
    CBitmap *image = new CBitmap();
    string filename2 = "Sortie.bmp";

    cout << "(II) CImage pointer extraction" << endl;
    CImage   *img = new CImage(500, 500);

    for (int j = 0; j<500; j++) {
        for (int i = 0; i < 500; i++) {
            CPixel *p = img->getPixel(i, j);
            p->RGB(255, 255, 255);
        }
    }
/*
    Arc* myarc = new Arc(250,250,100,150,300,0,0,255,100,0);
    myarc->dessiner(img);
    delete(myarc);
    Carre* mycarre = new Carre(1,1,100,0,0,0,255,100,0);
    mycarre->dessiner(img);
    delete(mycarre);
    Cercle* mycercle = new Cercle(250,250,50,0,0,255,100,0);
    mycercle->dessiner(img);
    delete(mycercle);
    Ligne* myligne = new Ligne(50,50,100,100,0,0,255,100,0);
    myligne->dessiner(img);
    delete(myligne);
    Point* mypoint = new Point(450,450,0,0,255,100,0);
    mypoint->dessiner(img);
    delete(mypoint);
    Rectangle* myrectangle = new Rectangle(100,400,120,80,0,0,0,255,100,0);
    myrectangle->dessiner(img);
    delete(myrectangle);
    Triangle* mytriangle = new Triangle(1,1,5,30,70,100,0,0,255,100,0);
    mytriangle->dessiner(img);
    delete(mytriangle);
*/

    Traitement* myfile = new Traitement("dessin.txt");
    myfile->dessiner(img);
    delete(myfile);

    image->setImage( img );
    cout << "(II) CBitmap image saving" << endl;
    image->SaveBMP(filename2);

    return 1;
}
