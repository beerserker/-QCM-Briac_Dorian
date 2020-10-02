#include <string>
#include <vector>
#ifndef ANSWER_h
#define ANSWER_h
using namespace std;

class Answer {
    private :
        string title;
        bool isAnswer;
    public :
        Answer(string title);
        Answer(string t,bool i);
        Answer();
        string getTitle();
        void setTitle(string t);
        void setIsAnswer(bool IsOrNot);
        bool getIsAnswer();
        ~Answer();

};
#endif