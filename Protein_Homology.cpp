#include <iostream>
#include <string>
#include "Homology.h"
using namespace std;


int main(){

    Protein a = Protein("abc");
    Protein b = Protein("abc");

    Homology AB;

    AB.getHomology(a, b);

    return 0;
}
