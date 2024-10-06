// Include Qt headers using #include
#include <QApplication>
import <vector>;

import QuizModel;
import QtQuizView;
import QuizController;
import QuizModule;

/**
 * @brief Creates a vector of quizzes with questions and answers.
 * @return A vector of quizzes.
 */
std::vector<Quiz> createQuizzes() {
    const Quiz GENERAL_QUIZ = {
        "General Knowledge",
        {
            "The Earth is the third planet from the Sun.",
            "Penguins can fly.",
            "Water boils at 100 degrees Celsius at sea level.",
            "Gold is a gas at room temperature.",
            "The human body has 206 bones.",
            "The Pacific Ocean is the largest ocean on Earth.",
            "There are 8 continents on Earth.",
            "An octopus has three hearts."
        },
        std::byte{ 0b10110101 } // Answers for general quiz
    };

    const Quiz SCIENCE_QUIZ = {
        "Science",
        {
            "The speed of light is approximately 300,000 kilometers per second.",
            "Humans have five senses.",
            "Water is made up of two hydrogen atoms and one oxygen atom.",
            "The chemical symbol for gold is Au.",
            "The Earth orbits the Moon.",
            "Lightning never strikes the same place twice.",
            "Humans and dinosaurs coexisted at the same time.",
            "Sound travels faster in water than in air.",
        },
        std::byte{ 0b10001101 } // Answers for science quiz
    };

    // Store quizzes in a vector and return it
    std::vector<Quiz> quizzes = { GENERAL_QUIZ, SCIENCE_QUIZ };
    return quizzes;
}

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);

    std::vector<Quiz> quizzes = createQuizzes();

    QuizModel model(quizzes);
    QtQuizView view;
    QuizController controller(model, view);

    controller.run();

    return 0;
}