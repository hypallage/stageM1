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
    for (int k=0;k<2*size-1;k++){rep.addline();}
    for (int i=1;i<size;i++){
        for (int j=1;j<size;j++){
            int number=latin->getel(i,j)->getnumber();
            el* a=(el*)malloc(sizeof(el));
            new (a) el(getstring(number,size),number);
            rep.setel(a,i,j); //1 ere matrice

            el* a2=(el*)malloc(sizeof(el));
            new (a2) el(getstring(number,size),number);
            rep.setel(a2,i+size-1,j+size-1); //2 eme matrice
            if (number!=0){
                el* a3=(el*)malloc(sizeof(el));
                new (a3) el(getstring(number+size-1,size),number+size-1);
                rep.setel(a3,i,j+size-1);
            }
            else{v.push_back(j);}

        }
    }
    el* a=(el*)malloc(sizeof(el));
    new (a) el(getstring(latin->getel(0,0)->getnumber(),size),latin->getel(0,0)->getnumber());
    rep.setel(a,0,0);
    for (int i=1;i<size;i++){//bord horizontal
        int number=latin->getel(0,i)->getnumber();
        el* a=(el*)malloc(sizeof(el));
        new (a) el(getstring(number+size-1,size),number+size-1);
        rep.setel(a,0,i);//avec barre
        el* a2=(el*)malloc(sizeof(el));
        new (a2) el(getstring(number,size),number);
        rep.setel(a2,0,i+size-1);//sans barre
        //cout<<a2->getnumber();
    }
    for (int i=1;i<size;i++){//bord vertical
        int number=latin->getel(i,0)->getnumber();
        el* a=(el*)malloc(sizeof(el));
        new (a) el(getstring(number+size-1,size),number+size-1);
        rep.setel(a,i,0);//avec barre
        el* a2=(el*)malloc(sizeof(el));
        new (a2) el(getstring(number,size),number);
        rep.setel(a2,i+size-1,0);//sans barre
        //cout<<a2->getnumber()<<endl;
    }
    //cout<<rep.getel(7,0)->getnumber()<<endl;

    for (int line=1;line<size;line++){
        int number=latin->getel(line,0)->getnumber();
        el* a=(el*)malloc(sizeof(el));
        new (a) el(getstring(number,size),number);
        rep.setel(a,line,line+size-1);
        int column=1;
        while (latin->getel(0,column)->getnumber()!=number){column++;}
        int linel=1;
        while (latin->getel(linel,line)->getnumber()!=number){linel++;}
            //cout<<"linel"<<linel<<endl;
        el* a2=(el*)malloc(sizeof(el));
        new (a2) el(getstring(latin->getel(0,line)->getnumber()+size-1,size),latin->getel(0,line)->getnumber()+size-1);
        rep.setel(a2,linel+size-1,line+size-1);
            //cout<<a2->getnumber()<<endl;
            //cout<<linel<<endl;
    }
        cout<<rep.getel(8,0)->getnumber()<<endl;
        cout<<"nb"<<rep.getel(1,7)->getnumber()<<endl;

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
            cout<<"columnl"<<columnl<<endl;
            cout<<"linel"<<linel<<endl;
            if (latin->getel(k,columnl)->getnumber()==0){
                el* a4=(el*)malloc(sizeof(el));
                new (a4) el(getstring(latin->getel(columnl,0)->getnumber()+size-1,size),latin->getel(columnl,0)->getnumber()+size-1);
                rep.setel(a4,linel+size-1,k);
                //cout<<a4->getnumber()<<endl;
                }
            else{
                el* a5=(el*)malloc(sizeof(el));
                new (a5) el(getstring(latin->getel(columnl,k)->getnumber()+size-1,size),latin->getel(columnl,k)->getnumber()+size-1);
                rep.setel(a5,linel+size-1,k);}
        }
        el* a3=(el*)malloc(sizeof(el));
        new (a3) el(getstring(latin->getel(0,column)->getnumber(),size),latin->getel(0,column)->getnumber());
        rep.setel(a3,linel+size-1,column);
        cout<<column<<endl;
        cout<<a3->getnumber()<<endl;
    }
    //cout<<rep.getel(8,0)->getnumber()<<endl;
    return rep;
}

string getstring (int number, int size){
    if (number>size-1)
    {return to_string(number-size)+"'";}
    else
    {return to_string(number);}
}