#include <iostream>
#include "QCM.h"
#include "Question.h"
#include "Answer.h"
#include "QCMManager.h"
using namespace std;

int main(void)
{
    Answer a("azerty");
    Answer a1("azerty1");
    Answer a2("azerty2");
    Question q1("question1");
    q1.addAnswer(a);
    q1.addAnswer(a1);
    q1.addAnswer(a2);
    vector<Answer> va = q1.getAnswers();
    for (int i = 0; i < va.size(); i++)
    {
        cout << va[i].getTitle() << endl;
    }
    q1.removeAnswer(1);
    va = q1.getAnswers();
    for (int i = 0; i < va.size(); i++)
    {
        cout << va[i].getTitle() << endl;
    }

    
    Question a3("az");
    Question a4("az1");
    Question a5("az2");
    QCM q2("question2");
    q2.addQuestion(a3);
    q2.addQuestion(a4);
    q2.addQuestion(a5);
    vector<Question> va2 = q2.getQuestions();
    for (int i = 0; i < va2.size(); i++)
    {
        cout << va2[i].getTitle() << endl;
    }
    q2.removeQuestion(1);
    va2 = q2.getQuestions();
    for (int i = 0; i < va2.size(); i++)
    {
        cout << va2[i].getTitle() << endl;
    }

    QCMManager c;
    q2.setTitle("de quelle couleur est la peau des ours polaire ?");
    c.save(q2);



    return 0;
}