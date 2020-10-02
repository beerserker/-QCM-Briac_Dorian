#include <iostream>
#include <string>
#include <vector>
#include "Question.h"
#include "Answer.h"
#include "QCM.h"
#include <fstream>
#include "QCMManager.h"
using namespace std;

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
            file <<""<< "\"Q\";\"" << vQuest[i].getTitle() << "\""<<endl;
            vector<Answer> vAns=vQuest[i].getAnswers();
            for (int j = 0; j < vAns.size(); j++)
            {
                file << "\"A\";\"" << vAns[j].getTitle() << "\";\"" << vAns[j].getIsAnswer() << "\""<<endl;
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
