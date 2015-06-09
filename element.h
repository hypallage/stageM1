#ifndef EL_H
#define EL_H

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
#include <vector>

using namespace std;
class el {
private:
	int number;
	string symbols;
public:
	string getsymbols();
	int getnumber ();
	void setnumber (int);
	void setsymbols (string);
	el(string s,int i);
}
;

#endif
