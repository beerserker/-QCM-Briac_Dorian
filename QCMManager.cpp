#include <iostream>
#include <string>
#include <vector>
#include "Question.h"
#include "Answer.h"
#include "QCM.h"
#include <fstream>
#include "QCMManager.h"
using namespace std;

bool QCMManager::save(QCM b)
{
    ofstream file;

    try
    {
        file.open("QCM.txt");
        
        file << "\"QCM\";\"" << b.getTitle() << "\"";
        //file << "\"Q\";\""<<
        file.close();
        return true;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
        
    }
    return false;
}
