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
	el* father;
	string symbols;
	vector<int> predecessor;
public:
	string getsymbols();
	el* getfather ();
	int getnumber ();
	int getapredecessor(int);
	vector<int> getpredecessor();
	void setnumber (int);
	void setsymbols (string);
	void setfather (el* );

	el(string,int , vector<int>, int);
	el(string s,int i);
}
;
void Union ( el*, el*);
el* find ( el* x);

#endif
