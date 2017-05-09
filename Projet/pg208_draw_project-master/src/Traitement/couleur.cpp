#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <sstream>
#include <cmath>

using namespace std;

#include "couleur.h"

vector<int> getCouleur(string color){

    vector<int> RVB = {0,0,0};

    if (color == "ROUGE"){
        RVB = {255,0,0};
    }
    else if (color == "VERT"){
        RVB = {0,255,0};
    }
    else if (color == "BLEU"){
        RVB = {0,0,255};
    }
    else if (color == "JAUNE"){
        RVB = {255,255,0};
    }
    else if (color == "MAGENTA"){
        RVB = {255,0,255};
    }
    else if (color == "CYAN"){
        RVB = {0,255,255};
    }
    else if (color == "BLANC"){
        RVB = {255,255,255};
    }
    else if (color == "NOIR"){
        RVB = {0,0,0};
    }
    else if (color == "GRIS"){
        RVB = {150,150,150};
    }
    return RVB;
}