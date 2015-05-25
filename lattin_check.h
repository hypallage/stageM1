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
	vector<vector<bool> > elcolumn;
	vector<bool> elline;
	Latinrectangle lattin;
public :
	Latinrectangle* getlattin ();
	bool available (int, int );
	void addacycle (vector<el*>,int,int);
	void printcycle (int,int);
	cyclearray(int);
	
}
;
