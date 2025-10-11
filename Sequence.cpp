#include <iomanip>
#include <iostream>
#include <string>
#include "Sequence.h"

using namespace std;

Sequence::Sequence(size_t sz) {
}

Sequence::Sequence(const Sequence &s) {
}

Sequence::~Sequence() {
}

Sequence & Sequence::operator=(const Sequence &s) {
}

std::string & Sequence::operator[](size_t position) {
}

void Sequence::push_back(std::string item) {
}

void Sequence::pop_back() {
}

void Sequence::insert(size_t position, std::string item) {
}

std::string Sequence::front() const {
}

std::string Sequence::back() const {
}

bool Sequence::empty() const {
}

size_t Sequence::size() const {
}

void Sequence::clear() {
}

void Sequence::erase(size_t position) {
}

void Sequence::erase(size_t position, size_t count) {
}

ostream & operator<<(ostream &os, const Sequence &s) {
}
