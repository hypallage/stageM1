#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
#include <vector>
#include "element.h"
#include <fstream>
#include <string>


class Latinrectangle {
private:
	int size;
	int line;
	bool b;
	vector<el*> rectangle;
public:	
	Latinrectangle(int);
	int getsize();
	int getline();
	bool getb ();
	el* getel (int, int);
	void setsize (int);
	void setline (int);
	void setb (bool);
	void setel (el*,int,int);
	void write (std::string);
	void addline ();
	bool addel (int ,el*);  // add the element at the given position on the current line
}
;
