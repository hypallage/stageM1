#include "element.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
#include <vector>

using namespace std;

el::el(string s,int i , vector<int> v, int j): symbols (s), number(i), father(NULL){
										v.push_back(i);
										this->predecessor=v;
										}
el::el(string s,int i): symbols (s), number(i), father(NULL){
										vector<int> v;
										this->predecessor=v;
										}

//get fonctions
string el::getsymbols () {return this->symbols;}

int el::getnumber () {return this->number;}

el* el::getfather ()  {return this->father;}

int el::getapredecessor(int i){return this->predecessor.at(i);}

vector<int> el::getpredecessor(){return this->predecessor;}

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

