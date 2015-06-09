#ifndef LATINRECTANGLE_H
#define LATINRECTANGLE_H

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
	int stringsize;
	int line;
	vector<el*> rectangle;
public:
	Latinrectangle(int);
	Latinrectangle();

	int getsize();
	int getline();
	int getstringsize();
    el* getel (int, int);

	void setsize (int);
	void setline (int);
	void setstringsize(int i);
	void setel (el*,int,int);

	void write1 (std::string);
	void write (std::string);
	void print ();
	void print1 ();
	void addline ();
}
;
template <typename T>
    std::string to_string(T value);
#endif
