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

    cout << seq << endl;

    cout<< "Testing exceptions!" << endl;

    cout << "front() and back() should error" << endl; //testing the similar functions
    cout << "Front: " << seq.front() << endl;
    cout << "Back: " << seq.back() << endl;

    cout <<"Testing operator[]: (should error) " << seq[1];//position test one


    seq.push_back("Uno");
    seq.push_back("Dos");
    seq.push_back("Tres");
    seq.push_back("Quatro");
    seq.push_back("Cinco");



    return 0;
}