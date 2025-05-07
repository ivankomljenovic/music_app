#include <key.hpp>

using namespace std;

Note::Note() {
    accidental = NATURAL;
    encoding = C;
}

Note::Note(int n, int a){
    encoding = n;
    accidental = a;
}

string Note::name(){
    return NOTE_ENCODINGS.at(encoding) + ACCIDENTALS.at(accidental);
}

int Note::distance(Note n){
    int result = 0;
    int modifier = 0;

    if (n.encoding == encoding)
        return abs(n.accidental - accidental);
    else{
        if (encoding == E || encoding == B)
            modifier = -1;
        else
            modifier = 0;

        return 2 + modifier + distance(Note(encoding + 1, accidental));
    }
}

Key::Key(){
    tonic = Note(C, NATURAL);
    type = MAJOR;
}

Key::Key(Note n, int t){
    tonic = Note(n);
    type = t;
}

Key::Key(int n, int a, int t){
    tonic = Note(n, a);
    type = t;
}

string Key::name(){
    if (type == MAJOR)
        return tonic.name() + " Major";
    else
        return tonic.name() + " Minor";
}

Key Key::relative_major(){
    if (type == MAJOR)
        return Key(*this);
    else{
        Note result = Note(tonic.encoding + 2, tonic.accidental);

        result.accidental += 3 - tonic.distance(result);

        return Key(result, MAJOR);
    }
}

Key Key::relative_minor(){
    if (type == MINOR)
        return Key(*this);
    else{
        Note result = Note(tonic.encoding - 2, tonic.accidental);

        result.accidental += tonic.distance(result) - 3;

        return Key(result, MINOR);
    }
}