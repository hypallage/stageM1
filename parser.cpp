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
		for (int i=0;i<size;i++){l.addline();}
		for (int j=0;j<size;j++){
            fichier>>s;
            cout<<s<<endl;
            if (mymap.count(s))
				{printf("The element %s appears twice in the line %d \none in the column %d and one in the column %d\n",s.c_str(),1,j,mymap.at(s));}
            else
                {mymap.insert(std::pair<string,int>(s,j));
                el* a=(el*)malloc(sizeof(el));
                new (a) el(s,j);
                l.setel (a, 0, j);}
            }
        cout<<mymap.at("0");
        cout<<"continue"<<endl;
		for (int i=1;i<size;i++){
            for (int j=0;j<size;j++){
				fichier>>s;
				cout<<s<<endl;
				el* a=(el*)malloc(sizeof(el));
                new (a) el(s,mymap.at(s));
				l.setel (a, i, j);
            }
		}
		cout<<"continue"<<endl;
		return l;
		}
