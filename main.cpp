#include <iostream>
#include <ctime>
#include <cstdlib>
#include "lattin_rectangle.h"
#include <string>
#include <vector>

using namespace std;

int main()
{
el A0=el(string("e"),0,NULL);
el A1=el(string("r"),1,NULL);
cout<<A0.getsymbols ()<<endl;
cout<<A0.getnumber ()<<endl;
cout<<(A0.getfather ()==NULL)<<endl;
cout<<(find (&A0)==&A0)<<endl;
cout<<(find (&A0)->getnumber())<<endl;
A0.setsymbols (string ("7"));
cout<<A0.getsymbols ()<<endl;
A0.setnumber (7);
cout<<A0.getnumber ()<<endl;
A0.setnumber (0);
Union (&A0,&A1);
cout<<(find (&A0)==&A0)<<endl;
cout<<(find (&A0)==&A1)<<endl;
Latinrectangle l(2);
cout<<l.getb ()<<endl;
cout<<l.getsize ()<<endl;
cout<<l.getline ()<<endl;
cout<<"addline"<<endl;
l.addline();
cout<<l.getb ()<<endl;
cout<<l.getsize ()<<endl;
cout<<l.getline ()<<endl;
l.setel(&A0,0,0);
l.setel(&A1,1,0);
l.addline();
return 0;
}
