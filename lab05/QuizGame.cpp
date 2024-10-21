//
// Created by Csala on 2024. 10. 21..
//

#include "QuizGame.h"
#include <iostream>
#include <vector>
#include <algorithm> // std::shuffle
#include <random>

QuizGame::QuizGame(const Quiz &quiz) : quiz(quiz) {
    this->quiz = quiz;
}

void QuizGame::startQuiz() {
    std::vector<int> numbers;
    numbers.reserve(this->quiz.num_questions);
for (int i = 0; i < this->quiz.num_questions; ++i) {
        numbers.push_back(i);
    }

    std::random_device rd;
    std::mt19937 g(rd());

    std::shuffle(numbers.begin(), numbers.end(), g);

    for (int i = 0; i < numbers.size(); ++i) {
        quiz.

    }

}
