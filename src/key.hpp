#include <stdio.h>
#include <string>
#include <map>

using namespace std;

const enum ACC {DOUBLE_FLAT = -2, FLAT = -1, NATURAL = 0, SHARP = 1, DOUBLE_SHARP = 2};
const map<string, int> NOTE_ENCODINGS {{"A", 0}, {"B", 1}, {"C", 2}, {"D",3}, {"E", 4}, {"F", 5}, {"G", 6}};
const enum KEY_TYPE {MAJOR = 0, MINOR = 1};

class Note{
    private:
        ACC accidental;
        int encoding; // according to the NOTE_ENCODINGS map
    public:
        Note();
        Note(int n); // where n is the note encoding
        Note(string n); // where n is the note name

        string name();
};

class Key{
    private:
        Note tonic;
        KEY_TYPE type;
    public:
        Key();
        Key(string n);
        Key(int n); // where n is the note number

        Key relative_major();
        Key relative_minor();
};
