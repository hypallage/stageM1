#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
#include <vector>
#include "lattin_check.h"

class Latinrectangle {
private:
	int size;
	int line;
	bool b;
	vector<el*> rectangle;
public:
	int getsize();
	int getline();
	bool getb ();
	el* getel (int, int);
	void setsize (int);
	void setline (int);
	void setb (bool);
	void setel (el*,int,int);}
;
