#include <iostream>
#include <ctime>
#include <cstdlib>
#include "parser.h"
#include "lattin_check.h"
#include <string>
#include <vector>
#include <fstream>
#include <string>

using namespace std;
void lattinall (int );

int main()
{

Latinrectangle l=openfile ("fichier.plr");
cout<<l.getsize()<<endl;
cyclearray c=cyclearray (&l);
cout<<c.getlattin()->getsize()<<endl;
Latincheck(&c);

l.print();
cout << "cocu"<<endl;
c.getlattin()->print();

//c.printcycle(0,0);
return 0;
}

/*
void lattinall (int size){
Latinrectangle pls(size);
vector<vector<bool> > elcolumn;
vector<bool> elline;
for (int i=0;i<size;i++){
	elline.push_back(false);}
for (int i=0;i<size;i++){
	elcolumn.push_back(elline);}
for (int i=0;i<size;i++){
	pls.addline();}
int j=0;
int i=0;
int number;
while (j<size){
	cout<<"i="<<i<<endl;
	cout<<"j="<<j<<endl;
	if (pls.getel(i,j)==NULL){number=0;}
	else {number=pls.getel(i,j)->getnumber()+1;}
	bool numbergood= false;
	while (!numbergood && number<<size){
		numbergood=true;
		while (elline.at(number) ){numbergood=false;number++;}
		for (int l=0;l<size;l++){
		while (elcolumn.at(l).at(number) && numbergood){numbergood=false;number++;}}
		if (j!=0){
			el* mypredecessor;
			for (int l=0;l<size;l++){
						if (pls.getel(i,j-1)->getnumber()==number){mypredecessor=pls.getel(i,j-1);}
						}
			}
			while (elcolumn.at(l).at(number) && numbergood)
		}
	i++;
	j++;
	cout<<"i="<<i<<endl;
	cout<<"j="<<j<<endl;
	}
}

*/



