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
public:
	string getsymbols();
	el* getfather ();
	int getnumber ();
	void setnumber (int);
	void setsymbols (string);
	void setfather (el* );
	
	el(string s,int i, el* e);
}
;
void Union ( el*, el*);
el* find ( el* x);


