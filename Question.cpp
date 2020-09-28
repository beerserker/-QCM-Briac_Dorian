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

bool Answer::getAnswer(){
return 0;
};

int Question::addAnswer(){


};

void Question::removeAnswer(int index){

};