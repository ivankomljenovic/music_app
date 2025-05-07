#include <stdio.h>
#include <string>
#include <map>

using namespace std;

enum ACCIDENTAL {DOUBLE_FLAT = -2, FLAT = -1, NATURAL = 0, SHARP = 1, DOUBLE_SHARP = 2};
const map<int, string> NOTE_ENCODINGS {{0, "A"}, {1, "B"}, {2, "C"}, {3, "D"}, {4, "E"}, {5, "F"}, {6, "G"}};
const map<int, string> ACCIDENTALS {{-2, "double flat"}, {-1, "flat"}, {0, "natural"}, {1, "sharp"}, {2, "double sharp"}};
enum NOTE_ENCODING {A = 0, B = 1, C = 2, D = 3, E = 4, F = 5, G = 6};
enum KEY_TYPE {MAJOR = 0, MINOR = 1};

// int note_encoding (string n){
//     return NOTE_ENCODINGS.at(n);
// }

class Note{
    public:
        int accidental;
        int encoding; // according to the NOTE_ENCODINGS map
        Note();
        Note(int n, int a);

        string name();
        int distance(Note n); // returns distance from another note in semitones
};

class Key{
    private:
        Note tonic;
        int type;
    public:
        Key();
        Key(Note n, int t);
        Key(int n, int a, int t);

        string name();
        Key relative_major();
        Key relative_minor();
};
