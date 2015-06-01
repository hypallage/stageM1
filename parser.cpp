#include <iostream>
#include <ctime>
#include <cstdlib>
#include "parser.h"
#include <string>
#include <vector>
#include <fstream>
#include <string>
#include <map>

using namespace std;

Latinrectangle openfile (std::string f){
		ifstream fichier(f.c_str(), ios::in);
		int size;
        std::map<std::string,int> mymap;
		fichier>>size;
		string s;
		Latinrectangle l=Latinrectangle(size);
		l.addline();
		for (int j=0;j<size;j++){
            fichier>>s;
            //cout<<s<<endl;
            if (mymap.count(s))
				{printf("The element %s appears twice in the line %d \none in the column %d and one in the column %d\n",s.c_str(),0,j,mymap.at(s));}
            else
                {mymap.insert(std::pair<string,int>(s,j));
                el* a=(el*)malloc(sizeof(el));
                new (a) el(s,j);
                l.setel (a, 0, j);}
            }
        //cout<<"continue"<<endl;
        string fin="fin";
        int i=1;
        fichier>>s;
		while (s!=fin && i<size){
		    l.addline();
            for (int j=0;j<size;j++){

				//cout<<j<<" "<<s<<endl;
				//cout<<j<<endl;
                //cout<<(s!=fin)<<endl;
				el* a=(el*)malloc(sizeof(el));
                new (a) el(s,mymap.at(s));
				l.setel (a, i, j);
				fichier>>s;
            }
            i++;
		}
		//cout<<"continue"<<endl;
		return l;
		}
