#ifndef CYCLEARRAY_H
#define CYCLEARRAY_H

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
#include <vector>
#include "lattin_rectangle.h"
#include <fstream>
#include <string>
#include<sstream>

class cyclearray{
private:
	vector<vector<vector<el*> > > cycles;
	vector<vector<int> > elcolumn;
	vector<vector<int> > elline;
	Latinrectangle* lattin;
public :
	Latinrectangle* getlattin ();
	bool available (int l,int c, int el);
	int getposc (int c,int el) ;
	int getposl (int l,int el) ;
	void addacycle (vector<el*> cycle,int l,int p);
	void printcycle (int l,int c);
	void setnumberl (int el,int l,int c);
	void setnumberc (int el,int l,int c);
	vector<vector<vector<el*> > >* getcycles();
	cyclearray(Latinrectangle*);

}
;
#endif


void Latincheck(cyclearray*);

int check(cyclearray*,int);

vector<el*> calculcylce(vector<bool>* v, cyclearray* Latin,int line,int pred,int column);

bool perfect(cyclearray* c);

