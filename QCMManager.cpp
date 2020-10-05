#include <iostream>
#include <string>
#include <vector>
#include "Question.h"
#include "Answer.h"
#include "QCM.h"
#include <fstream>
#include <sstream>
#include "QCMManager.h"
using namespace std;

QCMManager::QCMManager(){};

bool QCMManager::save(QCM quest)
{
    ofstream file;

    try
    {

        file.open("QCM.txt");
        file << "\"QCM\";\"" << quest.getTitle() << "\"\n";

        vector<Question> vQuest = quest.getQuestions();

        for (int i = 0; i < vQuest.size(); i++)
        {
            file << ""
                 << "\"Q\";\"" << vQuest[i].getTitle() << "\"" << endl;
            vector<Answer> vAns = vQuest[i].getAnswers();
            for (int j = 0; j < vAns.size(); j++)
            {
                file << "\"A\";\"" << vAns[j].getTitle() << "\";\"" << vAns[j].getIsAnswer() << "\"" << endl;
            }
        }

        file.close();
        return true;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
    return false;
}

QCM QCMManager::open(string name)
{
    QCM qcm;
    Answer ans;
    Question quest;
    int sizeQ, sizeA;
    ifstream file(name);
    if (file)
    {

        string contenu;
        while (getline(file, contenu))
        {
            vector<string> line = split(contenu);
            if (line[0] == "QCM")
            {
                qcm.setTitle(line[1]);
                cout << qcm.getTitle() << endl;
            }
            if (line[0] == "Q")
            {
                quest.getTitle(line[1]);// faire un if pour controler si le titre par defaut ou non
                quest.setTitle(line[1]);
                sizeQ = qcm.addQuestion(quest);
                cout << quest.getTitle() << endl;
            }
            if (line[0] == "A")
            {
                ans.setTitle(line[1]);
                sizeA = quest.addAnswer(ans);
                    bool b=(line[2]=="1");
                        ans.setIsAnswer(b);
                cout << ans.getTitle() <<" "<<ans.getIsAnswer()<< endl;
            }
        }

        file.close();
    }
    else
    {
        cerr << "Erreur, impossible d'ouvrir le fichier !" << endl;
    }
    return qcm;
}

vector<string> QCMManager::split(string line)
{
    stringstream sLine(line);
    string buffer;
    vector<string> vLine;
    while (getline(sLine, buffer, ';'))
    {

        vLine.push_back(buffer.substr(1, buffer.length() - 2));
    }

    return vLine;
}