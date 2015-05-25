#include <iostream>
#include <ctime>
#include <cstdlib>
#include "parser.h"
#include <string>
#include <vector>
#include <fstream>
#include <string>

Latinrectangle openfile (std::string f){		
		cout<<"coucou"<<endl;
		
		ifstream fichier(f.c_str(), ios::in);
		int entier,size;
		fichier>>size;
		Latinrectangle l=Latinrectangle(size);
		for (int i=0;i<size;i++){
			for (int j=0;j<size;j++){
				fichier>>entier;
				el a=el("s",entier);
				l.setel (&a, i, j);
				}
		}
		cout<<size<<endl;
		return l;
		}
