//
// Created by Csala on 2024. 10. 21..
//

#ifndef LAB5_QUIZGAME_H
#define LAB5_QUIZGAME_H
#include "Quiz.h"

class QuizGame {
private:
Quiz quiz;
public:
    explicit QuizGame(const Quiz &quiz);
    void startQuiz();
};


#endif //LAB5_QUIZGAME_H
