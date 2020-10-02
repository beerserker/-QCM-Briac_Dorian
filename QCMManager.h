#include <string>
#include <vector>
#include "QCM.h"
#include "Question.h"
#include "Answer.h"
using namespace std;



class QCMManager
{
    private :
    string path;


    public :
    QCMManager();
    bool save(QCM);
    QCM open(string name);
    

};

