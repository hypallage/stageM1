#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
#include <vector>
#include "lattin_rectangle.h"

// constructor

Latinrectangle::Latinrectangle(int i):size(i), line(0), b(true){}

// get fonctions
int Latinrectangle::getsize(){return this->size;}

int Latinrectangle::getline(){return this->line;}

bool Latinrectangle::getb (){return this->b;}

el* Latinrectangle::getel (int i, int j){return this->rectangle[i+this->getsize()*j];}

// set fonctions
void Latinrectangle::setsize (int i){this->size= i;}

void Latinrectangle::setline (int i){this->line= i;}

void Latinrectangle::setb (bool bo){this->b= bo;}

void Latinrectangle::setel (el* element, int i, int j){this->rectangle.at(i+this->getsize()*j)= element;}

void Latinrectangle::addline () {for (int i=0; i<this->getsize() ; i ++){
					this->rectangle.push_back(NULL);
					for (int j=0; j<this->getline(); j++){
						this->rectangle.at(i + j*this->getsize())->setfather(NULL);}
					}
					this->setline (this->getline()+1);
				}




