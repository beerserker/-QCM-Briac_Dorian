#include "Answer.h"
#include <vector>
#include <string>
#ifndef QUESTION_h
#define QUESTION_h

class Question {
    private :
        string title;
        vector<Answer> answers;
    public :
        Question(string t);
        string getTitle();
        void setTitle(string t);
        Answer getAnswer(string a);
        int addAnswer();
        void removeAnswer(int index);
        ~Question();
};
#endif