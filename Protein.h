#include <iostream>
#include <string>
using namespace std;

class Protein {
    
    private:
        string sequence;
        int length;

    public:
        // Constructor
        Protein(string Sequence);
        
        // Getters
        int getLength();
        string getSeq();

        // Setters
        void setSeq(string Sequence);

        // Display function
        void display();

};

// Constructor Def
Protein::Protein(string Sequence){
    sequence = Sequence;
    length = Sequence.length();
}

// Getters Defs
int Protein::getLength(){
    return length;
}

string Protein::getSeq(){
    return sequence;
}

// Setters Defs
void Protein::setSeq(string Sequence){
    sequence = Sequence;
    length = Sequence.length();
}

// Display Def
void Protein::display(){
    cout << "Protein of length: " << length << endl;
    cout << "Amino Acid Sequence: " << sequence << endl;
}
