#include <iostream>
#include <string>
#include <vector>
#include "Question.h"
#include "Answer.h"
#include "QCM.h"
using namespace std;

QCM::QCM(string t){

};
QCM::QCM(){};

string QCM::getTitle()
{
    return title;
};

void QCM::setTitle(string t)
{
    title = t;
};

vector<Question> QCM::getQuestions(){
return questions;
}; 

int QCM::addQuestion(Question a)
{
    questions.push_back(a);
    return questions.size();
    
};

void QCM::removeQuestion(int index){
questions.erase(questions.begin()+index);
};

QCM::~QCM(){

};
