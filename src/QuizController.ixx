export module QuizController;

import QuizModel;
import QuizView;
import <random>;

export class QuizController {
public:
    /**
	 * @brief Construct a new Quiz Controller object
	 * @param model The quiz model.
	 * @param view The quiz view.
     */
    QuizController(QuizModel& model, QuizView& view);

    /**
	 * @brief Run the quiz.
     */
    void run();

private:
    QuizModel& model;
    QuizView& view;
	std::mt19937 gen; // Random number generator for selecting questions.
	std::uniform_int_distribution<> dis; // Uniform distribution for generating random numbers, so each question has an equal chance of being selected.
};
