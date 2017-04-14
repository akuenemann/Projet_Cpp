#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

#include "./Format/CBitmap.h"
#include "./Formes/ligne.h"


int main(int argc, char * argv[]) {
    cout << "(II) P_Bitmap exection start (" << __DATE__ << " - " << __TIME__ << ")" << endl;
    cout << "(II) + Number of arguments = " << argc << endl;

    cout << "(II) CBitmap object creation" << endl;
    CBitmap *image = new CBitmap();
    string filename2 = "Sortie.bmp";

    cout << "(II) CImage pointer extraction" << endl;
    CImage   *img = new CImage(1000, 1000);
    /*for(int i=0; i<200; i++){
        CPixel *p = img->getPixel(i, i);
        p->RGB(255,255,255);
    }*/
	
	
	Ligne* first_ligne = new Ligne(100,900,900,900,255,255,255,100,1);
	first_ligne->dessiner(img);
	/*Ligne* next_ligne = new Ligne(180,10,180,10,255,255,255,100,1);
	next_ligne->resize(10);
	next_ligne->dessiner(img);
*/
    image->setImage( img );
    cout << "(II) CBitmap image saving" << endl;
    image->SaveBMP(filename2);

    return 1;
}
