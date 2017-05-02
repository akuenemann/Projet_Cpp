#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

#include "./Format/CBitmap.h"

#include "./Formes/arc.h"


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

    Arc* myarc = new Arc(250,250,100,330,320,0,0,255,100,0);
    myarc->dessiner(img);
    delete(myarc);



    image->setImage( img );
    cout << "(II) CBitmap image saving" << endl;
    image->SaveBMP(filename2);

    return 1;
}
