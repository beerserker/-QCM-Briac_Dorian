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

#define QCM_PATH "C:\\Projet_BTS\\-QCM-Briac_Dorian\\QCM\\"
using namespace std;

QCMManager::QCMManager(){};

void QCMManager::list()
{
    
    QCMfille st;
    string t;
    int i;

    DIR *dr;
    dirent *en;

    dr = opendir(QCM_PATH);
    if (dr)
    {
        while ((en = readdir(dr)) != NULL)
        {
            t = (string)(en->d_name);
            if (strstr(t.c_str(), ".qcm") != NULL)
            {
                t = QCM_PATH + t;
                st.setpath(t);
                QCMlist.push_back(st);
            }
        }
        closedir(dr);
    }

    
}


