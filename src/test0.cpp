/*
    Author: Ivan Komljenovic
    Comprehensive test of the Note and Key class constructors and methods
*/

#include "key.cpp"
#include <iostream>

using namespace std;

int main(){
    cout << "Testing Note and Key class constructors and methods." << endl;

    int pass_count = 0;
    int test_count = 0;

    // Test 1 - Key::Key()
    test_count++;
    // Test 1 body
    Key myKey = Key();
    // Test 1 evaluation
    if (myKey.name() == "C Major")
        pass_count++;
    else
        cout << "Failed Key::Key() test." << endl;

    printf("Testing finished with %.1f%% pass rate.", pass_count * 100.0 / test_count);
}