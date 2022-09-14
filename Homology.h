#include <iostream>
#include <string>
#include "Protein.h"
using namespace std;


class Homology{
    private:

    public:
        // Homology
        string getHomology(Protein a, Protein b);


};

string Homology::getHomology(Protein A, Protein B){

    // Step 1: Construct 1s and 0s matrix according to pairwise similarity

    // Initialize matrix to proper size
    int MAT[B.getLength()][A.getLength()];

    // Assign a one or zero to each index
    for(int i=0; i < B.getLength(); i++){
        
        for(int j=0; j < A.getLength(); j++){
            
            if(A.getSeq()[j] == B.getSeq()[i]){
                MAT[i][j] = 1;
            } else {
                MAT[i][j] = 0;
            }
        }
    }

    // TEMP DISPLAY MAT FOR VALIDATION
    for(int i=0; i <  B.getLength(); i++){
        
        for(int j=0; j < A.getLength(); j++){
            cout << MAT[i][j];
        }

        cout << endl;
    }

    cout << "\n\n";

    // Step 2: Assign each square a path score
    int pathMAT[B.getLength()][A.getLength()];
    int val, closestI, closestJ, startI, startJ, IJ, JI, distI, distJ;
    for(int i=0; i < B.getLength(); i++){
        
        for(int j=0; j < A.getLength(); j++){
            
            if (MAT[i][j] == 1){
                val = 1;
            } else val = 0;
            
            bool loop = true;

            startI = i;
            startJ = j;

            while(loop){

                // CHECK IF ON DA EDGE POR FAVOR

                if(startI == B.getLength()-1 || startJ == A.getLength()-1) break;

                // Initialize closest row values
                closestI = 1000;
                closestJ = 1000;
                cout << "HOWDY";
                // Find closest 1 on first row and column of sub matrix
                for(int k=startI+1; k < B.getLength(); k++){
                    if(MAT[k][startJ+1] == 1){
                        closestI = k;
                        IJ = startJ + 1;
                        break;
                    }
                }

                for(int l=startJ+1; l < A.getLength(); l++){
                    if(MAT[startI+1][l] == 1){
                        closestJ = l;
                        JI = startI+1;
                        break;
                    }
                }

                distI = closestI - startI;
                distJ = closestJ - startJ;

                // Define new starting position
                if(distI < distJ && closestI != 1000){

                        startI = closestI;
                        startJ = IJ;
                        cout << "HEREEEEEEEEE *******************";
                } else if(distJ < distI && closestJ != 1000){
                    
                        startI = JI;
                        startJ = closestJ;
                        cout << "TTTTTTTTTTTTTTTTHEREEEEEEEEE *******************" << endl;
                        cout << startI << "    " << startJ << endl;
                } else if(distI == distJ && closestI != 1000 && closestJ != 1000){
                    if(closestI < B.getLength() && IJ < A.getLength()){
                        startI = closestI;
                        startJ = IJ;
                        cout << "WWWWWHHHHHHHHHHHHHEREEEEEE *******************";
                    } else break;
                } else{
                    if(startI < B.getLength()-1 && startJ < A.getLength()-1){
                        startI++;
                        startJ++;
                        cout << "WHOOOOOOOOOOOOOOOOOOOOOOOOOOOO *******************";
                        continue;

                    } else break;
                    
                }

                // Added if we succesfully find a new square
                val++;

            }

            // Assign the square the value
            pathMAT[i][j] = val;

            // indicate loop is running
            cout << "SQUARE SET BB" << endl;

        }
    }

    // TEMP DISPLAY MAT FOR VALIDATION
    for(int i=0; i <  B.getLength(); i++){
        
        for(int j=0; j < A.getLength(); j++){
            cout << pathMAT[i][j];
        }

        cout << endl;
    }
}