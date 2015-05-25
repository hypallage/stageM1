#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
#include <vector>
#include "lattin_check.h"
#include <fstream>
#include <string>
#include<sstream>


cyclearray::cyclearray(int size){
				vector<vector<bool> > eelcolumn;
				vector<bool> eelline;
				Latinrectangle l=Latinrectangle(size);
				for (int i=0;i<size;i++){
					eelline.push_back(false);}
				for (int i=0;i<size;i++){
					eelcolumn.push_back(eelline);}
				for (int i=0;i<size;i++){
					l.addline();}
				this->elcolumn=eelcolumn;
				this->elline=eelline;
				this->lattin=l;}


bool cyclearray::available (int c, int el){return this->elline.at(el) && this->elcolumn.at(c).at(el);}

void cyclearray::addacycle (vector<el*> cycle,int l,int c){this->cycles.at((l-2)*(l-1)/2+c).push_back(cycle);}

void cyclearray::printcycle (int l,int c){
					if (this->cycles.at((l-2)*(l-1)/2+c).size()==0)
					{printf("pas de cycle entre la ligne %d et la ligne %d",l,c);}
					else
					{for (int i=0; i<this->cycles.at((l-2)*(l-1)/2+c).size(); i++)
						{printf("cycle number %d:",i);
						for (int j=0;j<this->cycles.at((l-2)*(l-1)/2+c).at(i).size();j++)
							{cout <<this->cycles.at((l-2)*(l-1)/2+c).at(i).at(j)<<" ";}
						}
					}
					}



