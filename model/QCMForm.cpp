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

void QCMForm::faireQCM(QCM qchoisi)
{
    vector<Question> question;
    vector <Answer> answer;

    int sizeq,sizea,point=0,rep;
    bool b;
    
    
    question = qchoisi.getQuestions();
    sizeq= question.size();
    for(int i=0;i<sizeq;i++)
    {
        affQUESTION(question[i].getTitle());
        //cout<<"\n"<<question[i].getTitle()<<endl;
        answer=question[i].getAnswers();
        sizea=answer.size();
        for(int y=0;y<sizea;y++)
        {
            cout<<"\n"<<y+1<<"- "<<answer[y].getTitle();
            
        }
        cout<<"\nvotre reponse :";
        cin>>rep;
        b=answer[rep-1].getIsAnswer();
        if(b)
        {
            cout<<"vrai !";
           point++; 
        }
        else
        {
            cout<<"faux !";
        }
        
        getch();

    }
    cout<<"\n vous avez reussi "<<point<<" questions sur "<<sizeq<<" questions !"<<endl;
}

void QCMForm::affListe(vector<QCMfille> vec)
{
    int taille = vec.size();
    
    for (int i = 0; i < taille; i++)
    {
        cout << "fichier n" << i + 1 << endl;
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