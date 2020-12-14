#ifndef QCMForm_h
#define QCMForm_h
#include <iostream>
#include <string>
#include <vector>
#include "Question.h"
#include "Answer.h"
#include "QCM.h"
#include <fstream>
#include <sstream>
#include "QCMManager.h"
#include <filesystem>
#include "QCMfille.h"
#include <dirent.h>
#include <conio.h>
#define LINE 80
class QCMForm
{
private:

public:
void faireQCM(QCM);
void affListe(vector<QCMfille>);
    void EnTete()
    {
        
        cout<<"╔";
        Line();
        cout<<"╗";        
        cout<<"\n╠                          c'est les qcm de bribri !                           ╢"<<endl;
        cout<<"╚";
        Line();
        cout<<"╝";
        cout<<endl;
    };
    void affQCM(){

    };
    void affQUESTION(string t){
        system("cls");
        int i;
        cout<<endl;
        Line();cout << "═";cout << "═"<<endl;
        for (i = 0; i < (LINE/2); i++)
        {
            cout<<"┈┈";
        }
        
        cout<<"\n"<<t<<endl;
        
    };
    void affANSWER(){

    };
    void Line()
    {
        int i;
        for (i = 0; i < (LINE-2); i++)
        {
            cout << "═";
        }
    };
    
};

#endif
