#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
#include <vector>
#include "construction.h"
#include <fstream>
#include <string>
#include<sstream>


Latinrectangle constructiond (Latinrectangle* latin) {
    int size=latin->getsize();
    vector<int> v;
    Latinrectangle rep=Latinrectangle(2*size-1);
    rep.setstringsize(latin->getstringsize()+1);
    for (int k=0;k<2*size-1;k++){rep.addline();}
    for (int i=1;i<size;i++){
        for (int j=1;j<size;j++){
            int number=latin->getel(i,j)->getnumber();
            string s=latin->getel(i,j)->getsymbols();
            el* a=(el*)malloc(sizeof(el));
            new (a) el(getstring(number,size,s),number);
            rep.setel(a,i,j); //1 ere matrice

            el* a2=(el*)malloc(sizeof(el));
            new (a2) el(getstring(number,size,s),number);
            rep.setel(a2,i+size-1,j+size-1); //2 eme matrice
            if (number!=0){
                el* a3=(el*)malloc(sizeof(el));
                new (a3) el(getstring(number+size-1,size,s),number+size-1);
                rep.setel(a3,i,j+size-1);
            }
            else{v.push_back(j);}

        }
    }
    el* a=(el*)malloc(sizeof(el));
    new (a) el(getstring(latin->getel(0,0)->getnumber(),size,latin->getel(0,0)->getsymbols()),latin->getel(0,0)->getnumber());
    rep.setel(a,0,0);
    for (int i=1;i<size;i++){//bord horizontal
        int number=latin->getel(0,i)->getnumber();
        string s=latin->getel(0,i)->getsymbols();
        el* a=(el*)malloc(sizeof(el));
        new (a) el(getstring(number+size-1,size,s),number+size-1);
        rep.setel(a,0,i);//avec barre
        el* a2=(el*)malloc(sizeof(el));
        new (a2) el(getstring(number,size,s),number);
        rep.setel(a2,0,i+size-1);//sans barre
        
    }
    for (int i=1;i<size;i++){//bord vertical
        int number=latin->getel(i,0)->getnumber();
        string s=latin->getel(i,0)->getsymbols();
        el* a=(el*)malloc(sizeof(el));
        new (a) el(getstring(number+size-1,size,s),number+size-1);
        rep.setel(a,i,0);//avec barre
        el* a2=(el*)malloc(sizeof(el));
        new (a2) el(getstring(number,size,s),number);
        rep.setel(a2,i+size-1,0);//sans barre
        
    }

    for (int line=1;line<size;line++){
        int number=latin->getel(line,0)->getnumber();
        string s=latin->getel(line,0)->getsymbols();
        el* a=(el*)malloc(sizeof(el));
        new (a) el(getstring(number,size,s),number);
        rep.setel(a,line,line+size-1);
        int column=1;
        while (latin->getel(0,column)->getnumber()!=number){column++;}
        int linel=1;
        while (latin->getel(linel,line)->getnumber()!=number){linel++;}
            
        string s2=latin->getel(0,line)->getsymbols();
        el* a2=(el*)malloc(sizeof(el));
        new (a2) el(getstring(latin->getel(0,line)->getnumber()+size-1,size,s2),latin->getel(0,line)->getnumber()+size-1);
        rep.setel(a2,linel+size-1,line+size-1);
            
    }
    for (int line=1;line<size;line++){
        int number=latin->getel(line,0)->getnumber();
        int column=1;
        while (latin->getel(0,column)->getnumber()!=number){column++;}
        int linel=1;
        while (latin->getel(linel,line)->getnumber()!=number){linel++;}

        //cout<<"column"<<column<<endl;

        //cout<<a3->getnumber()<<endl;
        int columnl=1;
        while (latin->getel(columnl,column)->getnumber()!=latin->getel(0,line)->getnumber()){columnl++;}
        //cout<<"colu"<<latin->getel(0,line)->getnumber()<<endl;
        //cout<<"line"<<latin->getel(columnl,column)->getnumber()<<endl;
        //cout<<"fin"<<endl;
        for (int k=1;k<size;k++){
            //cout<<"columnl"<<columnl<<endl;
            //cout<<"linel"<<linel<<endl;
            if (latin->getel(k,columnl)->getnumber()==0){
                 string s4=latin->getel(columnl,0)->getsymbols();
                el* a4=(el*)malloc(sizeof(el));
                new (a4) el(getstring(latin->getel(columnl,0)->getnumber()+size-1,size,s4),latin->getel(columnl,0)->getnumber()+size-1);
                rep.setel(a4,linel+size-1,k);
                //cout<<a4->getnumber()<<endl;
                }
            else{
                string s5=latin->getel(columnl,k)->getsymbols();
                el* a5=(el*)malloc(sizeof(el));
                new (a5) el(getstring(latin->getel(columnl,k)->getnumber()+size-1,size,s5),latin->getel(columnl,k)->getnumber()+size-1);
                rep.setel(a5,linel+size-1,k);}
        }
        string s3=latin->getel(0,column)->getsymbols();
        el* a3=(el*)malloc(sizeof(el));
        new (a3) el(getstring(latin->getel(0,column)->getnumber(),size,s3),latin->getel(0,column)->getnumber());
        rep.setel(a3,linel+size-1,column);
        //cout<<column<<endl;
        //cout<<a3->getnumber()<<endl;
    }
    //cout<<rep.getel(8,0)->getnumber()<<endl;
    return rep;
}

string getstring (int number, int size, string s){
    if (number>size-1)
    {return s+"a";}
    else
    {return s+"b";}
}
