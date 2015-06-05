#include <iostream>
#include <ctime>
#include <cstdlib>
#include "parser.h"
#include "lattin_check.h"
#include "construction.h"
#include <string>
#include <vector>
#include <fstream>
#include <string>

using namespace std;
void lattinall (int );

int main(int argc,char *argv[])
{
if (argc==2)
    {
        Latinrectangle l=openfile (argv[1]);
        l.print();
        //cout<<l.getel(0,1)->getnumber()<<endl;
        Latinrectangle r=constructiond (&l);
        r.print();
        r.print1();
        //cout<<"perfect"<<endl;
        //perfect(&c);
        //cout<<"What do you want?"<<endl;
        //string rep;
        //cin>>rep;
        //cout<<rep<<endl;
        /*Latinrectangle l=openfile ("exemple.plr");
cout<<l.getline()<<endl;
//cout<<l.getel(4,3)->getnumber()<<endl;
cyclearray c=cyclearray (&l);
Latincheck(&c);

//l.print();
//c.getlattin()->print();

//c.printcycle(0,0);
*/
    }
return 0;
}



