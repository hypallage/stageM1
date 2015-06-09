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

if (argc==1){cout<<"manque d'argument"<<endl;}
else {
    //cout<<argv[1]<<endl;
    std::string ring(argv[1]);
    //cout<<(ring=="-construct")<<endl;
    if (ring=="-construct")
    {
        if (argc==4){
        Latinrectangle l=openfile (argv[2]);
        cout<<"Input Matrix:"<<endl;
        l.print();
        Latinrectangle r=constructiond (&l);
        cout<<"Output Matix with number:"<<endl;
        r.print();
        cout<<"Output Matix with string:"<<endl;
        r.print1();
        r.write1(argv[3]);
        }
        else{
        cout<<"Erreur d'argument."<<endl;}

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
*/  }
    }
    return 0;
}



