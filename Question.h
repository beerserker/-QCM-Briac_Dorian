#include "Answer.h"
#include <vector>
#include <string>
#ifndef QUESTION_h
#define QUESTION_h
using namespace std;

class Question {
    private :
        string title;
        vector<Answer> answers;
    public :
        Question(string t);
        string getTitle();
        void setTitle(string t);
        vector<Answer> getAnswers();
        int addAnswer();
        void removeAnswer(int index);
        ~Question();
};
#endif