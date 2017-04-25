#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

#include "./Format/CBitmap.h"
#include "./Formes/rectangle.h"


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

    RectangleS* rect = new RectangleS(200,200,100,50,25,0,0,255,100,0);
    //rect->resize(2);
    rect->dessiner(img);
    delete(rect);



    image->setImage( img );
    cout << "(II) CBitmap image saving" << endl;
    image->SaveBMP(filename2);

    return 1;
}
