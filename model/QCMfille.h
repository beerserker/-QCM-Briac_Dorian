#include <iostream>
#include <string>
#include <vector>
#include "Question.h"
#include "Answer.h"
#include "QCM.h"
#include <filesystem>	
#ifndef QCMfille_h
#define QCMfille_h
using namespace std;

class QCMfille : public QCM
{
    private:
    string path;
    vector <string> split(string);
    public:
    
    bool save(QCM);
    void open();
    void setpath(string chemin){path=chemin;};
    string getpath(){return path;};

    





};


#endif