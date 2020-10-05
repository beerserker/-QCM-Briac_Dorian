#include <iostream>
#include <string>
#include <vector>
#include "Answer.h"
using namespace std;
Answer::Answer(string t)
{
        title = t;
        isAnswer=false;
};
Answer::Answer(string t,bool i)
{
        title = t;
        isAnswer=i;
};

string Answer::getTitle()
{
        return title;
}

void Answer::setTitle(string chaine)
{
        title = chaine;
}

void Answer::setIsAnswer(bool IsOrNot)
{
        isAnswer = IsOrNot;
}

bool Answer::getIsAnswer()
{
        return isAnswer;
}

Answer::Answer(){};
