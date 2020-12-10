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

#define QCM_PATH "C:\\Projet_BTS\\-QCM-Briac_Dorian\\QCM\\"
using namespace std;

void faireQCM(QCM qchoisi)
{
    vector<Question> question;
    vector <Answer> answer;

    Question quest;
    Answer ans;
    int sizeq,sizea,point=0,rep;
    bool b;
    
    
    question = qchoisi.getQuestions();
    sizeq= question.size();
    for(int i=0;i<sizeq;i++)
    {
        quest=question[i];
        cout<<"\n"<<quest.getTitle()<<endl;
        answer=quest.getAnswers();
        sizea=answer.size();
        for(int y=0;y<sizea;y++)
        {
            ans=answer[y];
            cout<<"\n"<<y+1<<"- "<<ans.getTitle();
            
        }
        cout<<"n votre reponse :";
        cin>>rep;
        b=answer[rep-1].getIsAnswer();
        if(b)
        {
           point++; 
        }


    }
    cout<<"\n vous avez reussi "<<point<<" questions sur "<<sizeq<<"questions !"<<endl;
}

void QCMForm::affListe(vector<QCMfille> vec)
{
    int taille = vec.size();
    cout << "taille = " << taille << endl;
    for (int i = 0; i < taille; i++)
    {
        cout << "fichier n°" << i + 1 << endl;
        string path = vec[i].getpath();

        ifstream file;
        file.open(path);

        if (file.is_open())
        {

            string contenu;
            getline(file, contenu);
            cout << "\n                      " << contenu << endl;
            if (contenu == "QCM")
            {
                getline(file, contenu);
                cout << i << "- " << contenu << endl;
            }

            file.close();
        }
        else
        {
            cerr << "Erreur, impossible d'ouvrir le fichier !" << endl;
        }
    }
}