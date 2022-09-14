#include <iostream>
#include <string>
#include "Homology.h"
using namespace std;


int main(){

    Protein a = Protein("abcabcabc");
    Protein b = Protein("abcabcabc");

    Homology AB;

    AB.getHomology(a, b);

    return 0;
}
