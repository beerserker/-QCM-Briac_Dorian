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
#include "QCMForm.h"
#include <windows.h>
using namespace std;

int main(void)
{
   /* Answer a("titre : reponse 1", 0);
    Answer a1("titre : reponse 2", 1);
    Answer a2("titre : reponse 3", 0);
    Question Q0("titre : question 0");
    Question Q1("titre : question 1");
    Question Q2("titre : question 2");
    Question Q3("titre : question 3");

    Q0.addAnswer(a);
    Q0.addAnswer(a1);
    Q0.addAnswer(a2);
    Q1.addAnswer(a);
    Q1.addAnswer(a1);
    Q1.addAnswer(a2);
    Q2.addAnswer(a);
    Q2.addAnswer(a1);
    Q2.addAnswer(a2);
    Q3.addAnswer(a);
    Q3.addAnswer(a1);
    Q3.addAnswer(a2);
    vector<Answer> vans = Q0.getAnswers();
    for (int i = 0; i < vans.size(); i++)
    {
        cout << vans[i].getTitle() << endl;
    }
    cout << endl;
    /*Q0.removeAnswer(1);
    vans = Q0.getAnswers();
    for (int i = 0; i < vans.size(); i++)
    {
        cout << vans[i].getTitle() << endl;
    }
    
    cout << endl;

    QCM qcm("QCM");
    qcm.addQuestion(Q0);
    qcm.addQuestion(Q1);
    qcm.addQuestion(Q2);
    qcm.addQuestion(Q3);
    vector<Question> vquest = qcm.getQuestions();
    for (int i = 0; i < vquest.size(); i++)
    {
        cout << vquest[i].getTitle() << endl;
    }
    cout << endl;
    
    qcm.removeQuestion(1);
    vquest = qcm.getQuestions();
    for (int i = 0; i < vquest.size(); i++)
    {
        cout << vquest[i].getTitle() << endl;
    }
    
    cout << endl;
    QCMfille c;
    qcm.setTitle("de quelle couleur est la peau des ours polaire ?");
    c.save(qcm);


//le listing
    string fichier="OURS.txt";
    c.setpath(fichier);
    QCM qcm2 = c.open();
    c.save(qcm2);
 
    QCMManager a;
    a.list();
    return 0;
    */
   system("cls");
    QCMForm form;
    QCMfille fille;
    QCM qchoisi;
    vector <QCMfille> vec;
    QCMManager list;
    form.EnTete();
    
    list.list();
    cout<<" liste des QCM disponible"<<endl;
    form.affListe(list.QCMlist);
    cout<<"\nvotre choix :";
    int choix;
    cin>>choix;
    fille.setpath((list.QCMlist[choix-1]).getpath());
    qchoisi=fille.open();
    form.faireQCM(qchoisi);
    



























}


/*!
 * \fn          int setConsoleScreenBufferInfo(COORD dwSize)
 * \brief       Modifie la taille de la console en cours.
 * \param[in]   dwSize  Spécifie la nouvelle taille de la console.
 * \return      Si l'opération a réussi, retourne \c EXIT_SUCCESS,
 *              sinon \c EXIT_FAILURE.
 * \note        To get extended error information, call GetLastError.
 */
// int setConsoleScreenBufferInfo(COORD dwSize)
// {   HANDLE hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE) ;
//     COORD bakDwSize = dwSize ;
//     SMALL_RECT srctWindow ;
//     CONSOLE_SCREEN_BUFFER_INFO csbiInfo ;
 
//     // Obtenir les informations de la console
//     if(!GetConsoleScreenBufferInfo(hConsoleOutput, &csbiInfo)) return EXIT_FAILURE ;
 
//     // Adapter le buffer de la console en fonction des tailles maximales
//     dwSize.X = (dwSize.X>csbiInfo.srWindow.Right)?dwSize.X:csbiInfo.dwSize.X ;
//     dwSize.Y = (dwSize.Y>csbiInfo.srWindow.Bottom)?dwSize.Y:csbiInfo.dwSize.Y ;
//     if(!SetConsoleScreenBufferSize(hConsoleOutput, dwSize)) return EXIT_FAILURE ;
 
//     // Modifier la taille de la console
//     dwSize = bakDwSize ;
//     srctWindow = csbiInfo.srWindow ;
//     srctWindow.Right = dwSize.X - 1 ;
//     srctWindow.Bottom = dwSize.Y - 1 ;
//     if(!SetConsoleWindowInfo(hConsoleOutput, TRUE, &srctWindow)) return EXIT_FAILURE ;
 
//     // Adapter la taille du buffer de la console à sa taille (pas d'ascenseurs)
//     dwSize = bakDwSize ;
//     if(!SetConsoleScreenBufferSize(hConsoleOutput, dwSize)) return EXIT_FAILURE ;
 
//     return EXIT_SUCCESS ;
// }