#include <iostream>
#include "QCM.h"
#include "Question.h"
#include "Answer.h"
#include "QCMManager.h"
using namespace std;

int main(void)
{
    Answer a("titre : reponse 1", 0);
    Answer a1("titre : reponse 2", 1);
    Answer a2("titre : reponse 3", 0);
    Question Q0("titre : question 0");
    Question Q1("titre : question 1");
    Question Q2("titre : question 2");
    Question Q3("titre : question 3");

    Q0.addAnswer(a);
    Q0.addAnswer(a1);
    Q0.addAnswer(a2);
    Q1.addAnswer(a);
    Q1.addAnswer(a1);
    Q1.addAnswer(a2);
    Q2.addAnswer(a);
    Q2.addAnswer(a1);
    Q2.addAnswer(a2);
    Q3.addAnswer(a);
    Q3.addAnswer(a1);
    Q3.addAnswer(a2);
    vector<Answer> vans = Q0.getAnswers();
    for (int i = 0; i < vans.size(); i++)
    {
        cout << vans[i].getTitle() << endl;
    }
    cout << endl;
    /*Q0.removeAnswer(1);
    vans = Q0.getAnswers();
    for (int i = 0; i < vans.size(); i++)
    {
        cout << vans[i].getTitle() << endl;
    }
    */
    cout << endl;

    QCM qcm("QCM");
    qcm.addQuestion(Q0);
    qcm.addQuestion(Q1);
    qcm.addQuestion(Q2);
    qcm.addQuestion(Q3);
    vector<Question> vquest = qcm.getQuestions();
    for (int i = 0; i < vquest.size(); i++)
    {
        cout << vquest[i].getTitle() << endl;
    }
    cout << endl;
    /*
    qcm.removeQuestion(1);
    vquest = qcm.getQuestions();
    for (int i = 0; i < vquest.size(); i++)
    {
        cout << vquest[i].getTitle() << endl;
    }
    */
    cout << endl;
    QCMManager c;
    qcm.setTitle("de quelle couleur est la peau des ours polaire ?");
    c.save(qcm);
    QCM qcm2 = c.open("QCM.txt");
    c.save(qcm2);
    return 0;
}