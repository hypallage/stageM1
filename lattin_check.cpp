#include "lattin_check.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
#include <vector>

using namespace std;

el::el(string s,int i, el* e):symbols(s), number(i), father(e){}

//get fonctions
string el::getsymbols () {return this->symbols;}

int el::getnumber () {return this->number;}

el* el::getfather ()  {return this->father;}
//set fonctions
void el::setsymbols (string s) {this->symbols= s;}

void el::setnumber (int i) {this->number= i;}
	
void el::setfather (el* father) {this->father= father;}
	
//union-find fonctions
void Union ( el* x , el* y){x->setfather (y);}

el* find ( el* x){
		if (x->getfather()==NULL)
		{ return x;}
		else
		{ 	el* z=find (x->getfather());
			x->setfather(z);
			return z;
		}

}

