#include <string>
#include <vector>
#include "Question.h"
using namespace std;

class QCM {
    private :
        string title;
        vector<Question> questions;
    public :
        QCM(string t);
        string getTitle();
        void setTitle(string t);
        Question setQuestions(string q);
        int addQuestion();
        void removeQuestion(int index);
        ~QCM();

};