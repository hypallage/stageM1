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
	Latinrectangle lattin;
public :
	Latinrectangle* getlattin ();
	bool available (int l,int c, int el);
	int getposc (int c,int el) ;
	int getposl (int l,int el) ;
	void addacycle (vector<el*> cycle,int l,int c);
	void printcycle (int l,int c);
	void setnumberl (int el,int l,int c);
	void setnumberc (int el,int l,int c);
	cyclearray(Latinrectangle);

}
;
#endif


void Latincheck(cyclearray);

int check(cyclearray*,int);

vector<int> calculcylce(cyclearray* Latin,int line,int pred,int column);
