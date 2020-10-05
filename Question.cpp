#include <iostream>
#include <string>
#include <vector>
#include "Question.h"
#include "Answer.h"
using namespace std;

Question::Question(string t)
{
    title = t;
};
Question::~Question(){}

string Question::getTitle()
{
    return title;
};

void Question::setTitle(string t)
{
    title = t;
};

vector<Answer> Question::getAnswers(){
return answers;
};

int Question::addAnswer(Answer a)
{

    answers.push_back(a);
    return answers.size();
};

void Question::removeAnswer(int index){
answers.erase(answers.begin()+index);
};

Question::Question(){};