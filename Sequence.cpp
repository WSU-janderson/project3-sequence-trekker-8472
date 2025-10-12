#include <iostream>
#include <string>
#include "Sequence.h"
#include <exception>

using namespace std;
// Creates an empty sequence (numElts == 0) or a sequence of numElts items
// indexed from 0 ... (numElts - 1).
Sequence::Sequence(size_t sz) {//create a number of empty posns

    for (size_t i = 0; i < sz; i++) {
        push_back("");
    }
}
// Creates a (deep) copy of sequence s
Sequence::Sequence(const Sequence &s) {
}
// Destroys all items in the sequence and releases the memory
// associated with the sequence
Sequence::~Sequence() {
    SequenceNode* current = head; //set location
    while (current != nullptr) { //while loop to iterate through and delete each node
        SequenceNode* deleteThisNext = current->next;
        delete current;
        current = deleteThisNext;
    }

    head = nullptr; // set the beginning and end to nullptrs so that it finishes the whole reset
    tail = nullptr;

}
// The current sequence is released and replaced by a (deep) copy of sequence
// s. A reference to the copied sequence is returned (return *this;).
Sequence & Sequence::operator=(const Sequence &s) {
}
// The position satisfies ( position >= 0 && position <= last_index() ).
// The return value is a reference to the item at index position in the
// sequence. Throws an exception if the position is outside the bounds
// of the sequence
std::string & Sequence::operator[](size_t position) {
}
// The value of item is appended to the sequence.
void Sequence::push_back(std::string item) {

    SequenceNode* newNode = new SequenceNode(item);//create the item

    if (tail == nullptr) { //basically checking if the link list is clear
        head = tail = newNode; //if it is set thus so that the first node is created
    }
    else {
        tail->next = newNode; //link tail node to the new one
        newNode->prev = tail; //reverse link the new one to the tail
        tail = newNode; //set the new node itself as the last node
    }
}
// The item at the end of the sequence is deleted and size of the sequence is
// reduced by one. If sequence was empty, throws an exception
void Sequence::pop_back() {

    if (head == nullptr) {
        return; //nothing is in the list to delete
    }

    SequenceNode* current = tail;

    if (tail->prev == nullptr) { //if first = last still will not point anywhere
        head = tail = nullptr; //reverse of the push_back logic for first node
    }
    else {
        tail = tail->prev; //set tail to the prior node
        tail->next = nullptr; // now remove the pointer from the new last tail node
    }

    delete current;
}
// The position satisfies ( position >= 0 && position <= last_index() ). The
// value of item is inserted at position and the size of sequence is increased
// by one. Throws an exception if the position is outside the bounds of the
// sequence
void Sequence::insert(size_t position, std::string item) {

    SequenceNode* current = head;
    SequenceNode* newNode = new SequenceNode(item);//create the item

    if ( position >= 0 && position <= size() ) {//for some reason instructions have last_item instead of size(below)
        if ( position == size() ) {
            push_back(item);
        }
        else if (position == 0) {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        else {
            for (int i = 0 ; i < position ; i++) {
                current = current->next;
            }
            newNode->prev = current->prev; //link new node to previous
            newNode->next = current; //link new node to current node forward
            current->prev->next = newNode; //link the previous's next to current
            current->prev = newNode; // link current back to new node
        }
    }
    else {
        throw std::out_of_range("Out of Range");
    }
}

// Returns the first element in the sequence. If the sequence is empty, throw an
// exception.
std::string Sequence::front() const {

    if (head == nullptr) {// when head is null provided all other logic correct whole series is empty
        throw std::out_of_range("Warning: Empty Sequence");
    }
    return head->item; //returns first item
}
// Returns the last element in the sequence. If the sequence is empty, throw an
// exception.
std::string Sequence::back() const {
    if (head == nullptr) {// when head is null provided all other logic correct whole series is empty
        throw std::out_of_range("Warning: Empty Sequence");
    }
    return tail->item; //returns last item
}
// Returns true if the sequence has no elements, otherwise false.
bool Sequence::empty() const {
    if (head == nullptr) { // when head is null provided all other logic correct whole series is empty
        return true;
    }
    return false;
}
// Returns the number of elements in the sequence.
size_t Sequence::size() const {

    int size = 0;

    if (head == nullptr) {  // if the head points to nothing, there is nothing
        return 0;  // returns the nothing that there is of 0
    }
    else {
        SequenceNode* current = head;//start Node Seq series
        while (current != nullptr) { //if current is null the sequence os complete
            current = current->next; //increment step
            size ++; //increment size
        }
        return size; //return the final size
    }
}
// All items in the sequence are deleted and the memory associated with the
// sequence is released, resetting the sequence to an empty state that can have
// items re-inserted.
void Sequence::clear() {
}
// The item at position is removed from the sequence, and the memory
// is released. If called with an invalid position throws an exception.
void Sequence::erase(size_t position) {
}
// The items in the sequence at ( position ... (position + count - 1) ) are
// deleted and their memory released. If called with invalid position and/or
// count throws an exception.
void Sequence::erase(size_t position, size_t count) {
}
// Outputs all elements (ex: <4, 8, 15, 16, 23, 42>) as a string to the output
// stream. This is *not* a method of the Sequence class, but instead it is a
// friend function
ostream & operator<<(ostream &os, const Sequence &s) {
}
