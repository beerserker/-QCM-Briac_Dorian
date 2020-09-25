#include <string>
#include <vector>
#ifndef ANSWER_h
#define ANSWER_h

class Answer {
    private :
        string title;
        bool isAnswer;
    public :
        Answer(string title);
        string getTitle();
        void setTitle(string t);
        void setAnswer(bool IsOrNot);
        bool getAnswer();

};
#endif