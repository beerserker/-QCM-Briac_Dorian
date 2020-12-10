
#ifndef QCMManager_h
#define QCMManager_h
#include <string>
#include <vector>
#include "QCM.h"
#include "QCMfille.h"
#include "Question.h"
#include "Answer.h"
using namespace std;



class QCMManager
{
    private :
    string path;
    vector <string> split(string);

    public :
    QCMManager();
    
    vector<QCMfille> list();
    bool save(QCM);
    QCM open(string name);
    
    

};

#endif