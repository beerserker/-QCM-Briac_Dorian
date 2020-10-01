#include <string>
#include <vector>
#include "Question.h"
#ifndef QCM_h
#define QCM_h
using namespace std;

class QCM {
    private :
        string title;
        vector<Question> questions;
    public :
        QCM(string t);
        string getTitle();
        void setTitle(string t);
        vector<Question> getQuestions();
        int addQuestion(Question);
        void removeQuestion(int index);
        ~QCM();

};
#endif
