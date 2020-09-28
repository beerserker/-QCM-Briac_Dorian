#include <iostream>
#include <string>
#include <vector>
#include "Question.h"
#include "Answer.h"
using namespace std;


Question::Question(string t){
    title = t;
};

string Question::getTitle(){
return title;
};

void Question::setTitle(string t){
title = "titre";
};

vector<Answer> Question::getAnswers(){

};

int Question::addAnswer(){


};

void Question::removeAnswer(int index){

};