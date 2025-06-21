/*
    Author: Ivan Komljenovic
    Testing the Note and Key class constructors and methods
*/

#include "key.cpp"
#include <iostream>

using namespace std;

int main(){
    cout << "Testing Note and Key class constructors and methods." << endl;

    int pass_count = 0;
    int test_count = 0;

    // Test 1 - Note::Note()
    test_count++;
    Note myNote = Note();
    if (myNote.name() == "C natural")
        pass_count++;
    else
        cout << "Failed test 1." << endl;

    // Test 2 - Note::Note(int, int)
    test_count++;
    myNote = Note(C, SHARP);
    Note myNote2 = Note(D, DOUBLE_FLAT);
    if (myNote.name() == "C sharp" && myNote2.name() == "D double flat")
        pass_count++;
    else
        cout << "Failed test 2." << endl;

    // Test 3 - Note::Note(int, int) encoding bounds
    test_count++;
    myNote = Note(7, NATURAL); // should wrap back to A
    myNote2 = Note(9, DOUBLE_SHARP);
    if (myNote.name() == "A natural" && myNote2.name() == "C double sharp")
        pass_count++;
    else
        cout << "Failed test 3." << endl;

    // Test 4 - Note::Note(int, int) accidental bounds
    test_count++;
    try{
        myNote = Note(A, 3);
    }catch (...){
        pass_count++;
    }
    if (pass_count != 4) cout << "Failed test 4." << endl;

    
    
    printf("Executed %d tests. Finished with %.1f%% pass rate.", test_count, pass_count * 100.0 / test_count);
}