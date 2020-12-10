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
#include "QCMForm.h"

#define QCM_PATH "E:\\projects\\-QCM-Briac_Dorian\\QCM\\"
using namespace std;





void QCMForm::affListe(vector <QCMfille> vec)
{
  int taille=vec.size();
    for(int i=0;i<taille;i++)
    {
        string path= vec[i].getpath();
        path = QCM_PATH + path;
        ifstream file(path);
        if (file)
        {

            string contenu;
            getline(file, contenu);
            cout<<"\n                      "<<contenu<<endl;
            if (contenu == "QCM")
                {
                    getline(file, contenu);
                    cout << contenu << endl;
                }
            

            file.close();
        }
        else
        {
            cerr << "Erreur, impossible d'ouvrir le fichier !" << endl;
        }
        
    }
}