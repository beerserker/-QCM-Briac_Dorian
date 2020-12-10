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
#define QCM_PATH "E:\\projects\\-QCM-Briac_Dorian\\QCM/"
#define LINE 80
class QCMForm
{
private:

public:
void affListe(vector<QCMfille>);
    void EnTete()
    {
        QCMForm line;
        line.Line();
        cout<<" c'est les qcm de bribri !"<<endl;
        line.Line();
    
    };
    void QCM(){

    };
    void QUESTION(){

    };
    void ANSWER(){

    };
    void Line()
    {
        int i;
        for (i = 0; i < LINE; i++)
        {
            cout << "-";
        }
    };
    
};

#endif
