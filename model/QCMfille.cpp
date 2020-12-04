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

using namespace std;
#define QCM_PATH "E:\\projects\\-QCM-Briac_Dorian\\QCM"

bool QCMfille::save(QCM quest)
{
    ofstream file;

    try
    {

        file.open(QCM_PATH);
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

QCM QCMfille::open()
{
    QCM qcm;
    Answer ans;
    Question quest;
    int sizeQ, sizeA;
    path=QCM_PATH+path;
    ifstream file(path);
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
                quest.getTitle();
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
vector<string> QCMfille::split(string line)
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
