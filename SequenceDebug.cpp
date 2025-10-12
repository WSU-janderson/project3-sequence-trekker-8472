/**
 * SequenceDebug.cpp
 * Project 3
 * CS 3100
 *
 * In this file, you will write your tests as you implement Sequence. If you are using CLion, you need to select
 * SequenceDebug from the drop-down menu next to the Build (hammer icon) if it is on SequenceTestHarness
 */
#include <iostream>

#include "Sequence.h"

using namespace std;

int main() {
    cout << "Starting Debug...\n" << endl;

    //test buiding it
    Sequence seq;

    cout << "Head pointer: " << seq.head << endl;//verify empty constructor called

    if (seq.empty()) { //test if empty
        cout << "Sequence is empty.\n";
    }
    else {
        cout << "Front: " << seq.front() << endl;
    }

    cout<< "Testing exceptions! Empty set errors!" << endl;

    try {
        cout << "Front: " << seq.front() << endl;
    } catch (const exception& e) {
        cout << "Caught exception: " << e.what() << endl;
    }

    try {
        cout << "Back: " << seq.back() << endl;
    } catch (const exception& e) {
        cout << "Caught exception: " << e.what() << endl;
    }

    try {
        cout << "Insert: bananas at 2: " << endl;
        seq.insert(2,"bananas");
    } catch (const exception& e) {
        cout << "Caught exception: " << e.what() << endl;
    }

    try {
        cout << "Operator[]: " << seq.operator[](1) << endl;
    } catch (const exception& e) {
        cout << "Caught exception: " << e.what() << endl;
    }

    try {
        cout << "Popback test: " << endl;
        seq.pop_back();
    } catch (const exception& e) {
        cout << "Caught exception: " << e.what() << endl;
    }

    try {
        cout << "Erase (single) test: " << endl;
        seq.erase(1);
    } catch (const exception& e) {
        cout << "Caught exception: " << e.what() << endl;
    }

    try {
        cout << "Erase (series) test: " << endl;
        seq.erase(1, 2);
    } catch (const exception& e) {
        cout << "Caught exception: " << e.what() << endl;
    }

    seq.push_back("Uno");

    cout << seq << endl;

    cout << "Testing not empty" << endl;

    try {
        cout << "Erase (single) test: " << endl;
        seq.erase(2);
    } catch (const exception& e) {
        cout << "Caught exception: " << e.what() << endl;
    }

    try {
        cout << "Erase (series) test: " << endl;
        seq.erase(1, 2);
    } catch (const exception& e) {
        cout << "Caught exception: " << e.what() << endl;
    }

    try {
        cout << "Insert: bananas at 2: " << endl;
        seq.insert(2,"bananas");
    } catch (const exception& e) {
        cout << "Caught exception: " << e.what() << endl;
    }

    try {
        cout << "Operator[]: " << seq.operator[](1) << endl;
    } catch (const exception& e) {
        cout << "Caught exception: " << e.what() << endl;
    }

    seq.push_back("Dos");
    seq.push_back("Tres");
    seq.push_back("Quatro");
    seq.push_back("Cinco");

    cout << seq << endl;




    return 0;
}
