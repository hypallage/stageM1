


#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
#include <vector>
#include "lattin_check.h"
#include <fstream>
#include <string>
#include<sstream>






cyclearray::cyclearray( Latinrectangle* l){
                this->lattin=l;
				vector<vector<int> > eelcolumn;
				vector<int> aline;
				for (int i=0;i<l->getsize();i++){
					aline.push_back(-1);}
				for (int i=0;i<l->getsize();i++){
					eelcolumn.push_back(aline);}
				this->elcolumn=eelcolumn;
				this->elline=eelcolumn;
				vector<vector<el*> > v;
				for (int i=0;i<(l->getsize()-1)*(l->getsize())/2;i++)
				{this->cycles.push_back(v);}
				//cout<< this->getlattin()->getsize();
				//cout<<"continue"<<endl;
				}
vector<vector<vector<el*> > >* cyclearray::getcycles(){return &this->cycles;}

bool cyclearray::available (int c,int l, int el){return (this->elline.at(l).at(el)==-1) && (this->elcolumn.at(c).at(el)==-1);}

int cyclearray::getposc (int c,int el) {return this->elcolumn.at(c).at(el);}

int cyclearray::getposl (int l,int el) {return this->elline.at(l).at(el);}

void cyclearray::addacycle (vector<el*> cycle,int l,int p){this->cycles.at((l-2)*(l-1)/2+p).push_back(cycle);}

Latinrectangle* cyclearray::getlattin (){return this->lattin;}

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

void cyclearray::setnumberc (int el,int l,int c){this->elcolumn.at(c).at(el)=l;}

int check(cyclearray* Latin,int line){
					bool problem=false;
					int column=0;
					while (!problem && column<Latin->getlattin()->getsize()){
						int num=Latin->getlattin()->getel(line,column)->getnumber();
						if (Latin->available (column,line,num))
						{
						Latin->setnumberl (num,line,column);
						Latin->setnumberc (num,line,column);}
						else
						{problem=true;}
						column++;}
                    //for (int r=0;r<Latin->getlattin()->getsize();r++){cout<<r<<" "<<Latin->getposl(line,r)<<endl;}
                    if (problem)
					{column--;return column;}
					else
					{return -1;}

            }

void Latincheck(cyclearray* Latin){
				bool problem=false;int line=0;
                //cout<<Latin->getlattin()->getsize()<<endl;
				while (!problem && line<Latin->getlattin()->getsize()){
                    int checkl=check(Latin,line);
                    //cout<<"ligne "<<line<<endl;
                    if (checkl!=-1)
                    {problem=true;
                    int l=Latin->getlattin()->getel(line,checkl)->getnumber();
                        if (Latin->getposl(line,l)!=-1)
                            {printf("The number %d appears twice in the line %d \none in the column %d and one in the column %d\n",l,line,Latin->getposl(line,l),checkl);}
                        else
                            {printf("The number %d appears twice in the column %d \none in the line %d and one in the line %d\n",l,checkl,Latin->getposc(checkl,l),line);}
                    }
                    else {cout<<"line ok"<<endl;
                        vector<bool>* v;
                         //cout<<"firt="<<endl;
                        for (int i=0;i<Latin->getlattin()->getsize();i++){v->push_back(false);}
                        for (int pred=0;pred<line;pred++){
                            for (int i=0;i<Latin->getlattin()->getsize();i++){v->at(i)=false;}
                            //for (int i=0;i<Latin->getlattin()->getsize();i++){cout<<i<<" "<<v->at(i)<<endl;}
                                cout<<"pred"<<pred<<endl;
                                cout<<"line"<<line<<endl;

                            int first=0;
                            while (first<Latin->getlattin()->getsize()){
                            //cout<<"firt="<<first<<endl;

                            vector<el*> cycle=calculcylce(v,Latin,line,pred,first);
                            cout<<"ffgh"<<endl;
                            for (int i=0;i<Latin->getlattin()->getsize();i++){cout<<i<<" "<<v->at(i)<<endl;}
                            //cout<<"longueur"<<cycle.size()<<endl;
                            //cout<<Latin->getlattin()->getsize()<<endl;
                            if (cycle.size()==Latin->getlattin()->getsize()+1)
                                {first=Latin->getlattin()->getsize();}
                            else
                                {Latin->addacycle(cycle,line,pred);
                                while (first<Latin->getlattin()->getsize() && v->at(first)==true){first++;}

                                //cout<<"first"<<first<<endl;
                                }
                            }
                            if (line==3 && pred==2)
                            {v->at(455556);}

                            }

                    }
                line++;}
}

vector<el*> calculcylce(vector<bool>* v,cyclearray* Latin,int line,int pred,int column){
    for (int i=0;i<Latin->getlattin()->getsize();i++){cout<<i<<" "<<v->at(i)<<endl;}
    Latin->getlattin()->print();
    for (int i=0;i<Latin->getlattin()->getsize();i++){cout<<i<<" "<<v->at(i)<<endl;}
    vector<el*> rep;
    //cout<<"Je cacule un cycle"<<endl;
    //cout<<"line"<<line<<endl;
    //cout<<"pred"<<pred<<endl;
    //cout<<"column"<<column<<endl;
    el* debut=Latin->getlattin()->getel(line,column);
    cout<<debut->getsymbols()<<endl;
    cout<<column<<endl;
    v->at(column)=true;
    int col=column;
    el* ajout;
    ajout=Latin->getlattin()->getel(pred,col);
    col=Latin->getposl(line,ajout->getnumber());
    //cout<<"Je plante"<<endl;
    v->at(col)=true;cout<<v->at(col)<<"fff"<<endl;
    cout<<ajout->getsymbols()<<endl;cout<<col<<endl;
    for (int i=0;i<Latin->getlattin()->getsize();i++){cout<<i<<" "<<v->at(i)<<endl;}
    v->at(4455555555555);
    while (ajout->getnumber()!=debut->getnumber()){
        //cout<<pred<<" "<<col<<endl;
        ajout=Latin->getlattin()->getel(pred,col);
        //cout<<"Je plante"<<endl;cout<<line<<endl;cout<<ajout->getnumber()<<endl;
        col=Latin->getposl(line,ajout->getnumber());
        cout<<ajout->getsymbols()<<endl;
        cout<<col<<endl;
        //for (int i=0;i<Latin->getlattin()->getsize();i++){cout<<i<<" "<<v->at(i)<<endl;}
        v->at(col)=true;
        //for (int i=0;i<Latin->getlattin()->getsize();i++){cout<<i<<" "<<v->at(i)<<endl;}

        rep.push_back(ajout);}
        //cout<<"longueur"<<rep.size()<<endl;
        for (int i=0;i<Latin->getlattin()->getsize();i++){cout<<i<<" "<<v->at(i)<<endl;}
        //cout<<"fin"<<endl;
        return rep;
}

bool perfect(cyclearray* c){
    //cout<<c->getcycles()->size();
    for (int i=0;i<c->getcycles()->size();i++){if (c->getcycles()->at(i).size())
                                                {cout<<c->getcycles()->at(i).size()<<endl;}}

    return true;
}
