


#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
#include <vector>
#include "lattin_check.h"
#include <fstream>
#include <string>
#include<sstream>






cyclearray::cyclearray( Latinrectangle l){
				vector<vector<int> > eelcolumn;
				vector<int> aline;
				for (int i=0;i<l.getsize();i++){
					aline.push_back(-1);}
				for (int i=0;i<l.getsize();i++){
					eelcolumn.push_back(aline);}
				this->elcolumn=eelcolumn;
				this->elline=eelcolumn;
				}


bool cyclearray::available (int c,int l, int el){return (this->elline.at(l).at(el)!=-1) && (this->elcolumn.at(c).at(el)!=-1);}

int cyclearray::getposc (int c,int el) {return this->elcolumn.at(c).at(el);}

int cyclearray::getposl (int l,int el) {return this->elline.at(l).at(el);}

void cyclearray::addacycle (vector<el*> cycle,int l,int c){this->cycles.at((l-2)*(l-1)/2+c).push_back(cycle);}

Latinrectangle* cyclearray::getlattin (){return &this->lattin;}

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

void cyclearray::setnumberl (int el,int l,int c){this->elline.at(l).at(el)=c;}

void cyclearray::setnumberc (int el,int l,int c){this->elcolumn.at(l).at(c)=l;}

int check(cyclearray* Latin,int line){
					bool problem=false;
					int column=0;
					while (!problem && column<Latin->getlattin()->getsize()){
						int num=Latin->getlattin()->getel(line,column)->getnumber();
						if (Latin->available (line,column,num))
						{Latin->setnumberl (num,line,column);
						Latin->setnumberc (num,line,column);}
						else
						{problem=true;}
						column++;}
					if (problem)
					{column--;return column;}
					else
					{return -1;}
					}

void Latincheck(cyclearray* Latin){
				bool problem=false;int line=0;
				while (!problem && line<Latin->getlattin()->getsize()){
                    int checkl=check(Latin,line);
                    if (checkl!=-1)
                    {problem=true;
                    int l=Latin->getlattin()->getel(line,checkl)->getnumber();
                        if (Latin->getposl(line,l)!=-1)
                            {printf("The number %d appears twice one in the column %d and one in the column %d",l,Latin->getposl(line,l),checkl);}
                        else
                            {printf("The number %d appears twice one in the column %d and one in the line %d",l,Latin->getposc(checkl,l),line);}
                    }
                    else {
                        for (int column=0;column<Latin->getlattin()->getsize();column++){
                            int l=Latin->getlattin()->getel(line,column)->getnumber();
                            for (int pred=0;pred<line;pred++){
                                int prepos=Latin->getposl(pred,l);
                                if (find(Latin->getlattin()->getel(line,column))==find(Latin->getlattin()->getel(line,prepos)))
                                    {vector<int> v=calculcylce(Latin,line,pred,column);}
                                    else
                                    {Union(find(Latin->getlattin()->getel(line,column)),find(Latin->getlattin()->getel(line,prepos)));}
                                }
                        }
                        for (int column=0;column<Latin->getlattin()->getsize();column++){
                            for (int pred=0;pred<line;pred++){
                            Latin->getlattin()->getel(pred,column)->setfather(NULL);}
                        }
                    }
                }
}

vector<int> calculcylce(cyclearray* Latin,int line,int pred,int column){
    vector<int> rep;
    int debut=Latin->getlattin()->getel(line,column)->getnumber();
    rep.push_back(debut);
    int col=column;
    int ajout=-1;
    while (ajout!=debut){
        ajout=Latin->getlattin()->getel(pred,col)->getnumber();
        col=Latin->getposl(line,ajout);
        rep.push_back(ajout);}
    return rep;
}
