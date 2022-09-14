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
    int val, closestI, closestJ, startI, startJ, IJ, JI;
    for(int i=0; i < B.getLength(); i++){
        
        for(int j=0; j < A.getLength(); j++){
            
            if (MAT[i][j] == 1){
                val = 1;
            } else val = 0;
            
            bool loop = true;

            startI = i;
            startJ = j;

            while(loop){

                // Initialize closest row values
                closestI = 1000;
                closestJ = 1000;
                cout << "HOWDY";
                // Find closest 1 on first row and column of sub matrix
                for(int k=startI+1; k < B.getLength(); k++){
                    if(MAT[k][startJ+1] == 1){
                        closestI = k;
                        IJ = k;
                        break;
                    }
                }

                for(int l=startJ+1; l < A.getLength(); l++){
                    if(MAT[startI+1][l] == 1){
                        closestJ = l;
                        JI = l;
                        break;
                    }
                }

                // Define new starting position
                if(closestI < closestJ){

                        startI = closestI;
                        startJ = IJ;
                   
                } else if(closestJ < closestI){
                    
                        startI = JI;
                        startJ = closestJ;
                    
                } else if(closestI == closestJ && closestI != 1000 && closestJ != 1000){
                    
                        startI = closestI;
                        startJ = IJ;

                } else{
                    break;
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