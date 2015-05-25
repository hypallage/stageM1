#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
#include <vector>
#include "lattin_rectangle.h"
#include <fstream>
#include <string>
#include<sstream>

    
using namespace std;

template <typename T>
    std::string to_string(T value)
    {
      //create an output string stream
      std::ostringstream os ;

      //throw the value into the string stream
      os << value ;

      //convert the string stream into a string and return
      return os.str() ;
    }
// constructor
Latinrectangle::Latinrectangle(): size(0), line(0), b(true){}
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

// add a line and put all the father to NULL

void Latinrectangle::addline () {
				for (int i=0; i<this->getsize() ; i ++){
					this->rectangle.push_back(NULL);
					this->setline (this->getline()+1);}
				}

void Latinrectangle::write (std::string f){
	ofstream fichier(f.c_str(), ios::out);
	fichier<<this->getsize()<<"\n";
	for (int j=0;j<this->getline ();j ++){
		for (int i=0;i<this->getsize ();i++){
			int a=this->rectangle.at(i + j*this->getsize())->getnumber ();
			int b=to_string(a).size()-to_string(this->getsize()).size();
			fichier<<a;
			for (int l=0;l<=b;l++){
						fichier<<" ";
						}
			}
		fichier<<"\n";}
	}


void Latinrectangle::print (){
	cout<<"/n";
	for (int j=0;j<this->getline ();j ++){
		for (int i=0;i<this->getsize ();i++){
			int a=this->rectangle.at(i + j*this->getsize())->getnumber ();
			int b=to_string(a).size()-to_string(this->getsize()).size();
			cout<<a;
			for (int l=0;l<=b;l++){
						cout<<" ";
						}
			}
		cout<<"\n";}
	}
	


