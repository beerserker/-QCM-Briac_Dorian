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
//#define QCM_PATH "E:\\projects\\-QCM-Briac_Dorian\\QCM\\"

bool QCMfille::save(QCM quest)
{
    ofstream file;

    try
    {

        file.open(path);
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

void QCMfille::open()
{
    
    Answer ans;
    Question quest;
    
    //path=QCM_PATH+path;
    ifstream file;file.open(path);
    if (file.is_open())
    {

        string contenu;
        while (getline(file, contenu))
        {
            vector<string> line = split(contenu);
            if (line[0] == "QCM")
            {
                setTitle(line[1]);
                //cout << qcm.getTitle() << endl;
            }
            if (line[0] == "Q")
            {
               if((quest.getTitle())!="noTitle")
               {
                    addQuestion(quest);
                    quest=Question();
               }
                quest.setTitle(line[1]);
                
                //cout << quest.getTitle() << endl;
            }
            if (line[0] == "A")
            {
                ans.setTitle(line[1]);
                bool b=(line[2]=="1");
                ans.setIsAnswer(b);
                quest.addAnswer(ans);
                //cout << ans.getTitle() <<" "<<ans.getIsAnswer()<< endl;
            }
             if (line[0] == "END")
            {
               if(quest.getTitle()!="noTitle")
               {
                    addQuestion(quest);
                    quest=Question();
               }
            }
        }

        file.close();
    }
    else
    {
        cerr << "Erreur, impossible d'ouvrir le fichier !" << endl;
    }
    
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
