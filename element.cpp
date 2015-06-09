#include "element.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
#include <vector>

using namespace std;

el::el(string s,int i): number(i),symbols (s){}

//get fonctions
string el::getsymbols () {return this->symbols;}

int el::getnumber () {return this->number;}

//set fonctions
void el::setsymbols (string s) {this->symbols= s;}

void el::setnumber (int i) {this->number= i;}

