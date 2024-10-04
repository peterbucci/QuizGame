export module TerminalQuizView;

import QuizView;
import <iostream>;
import <limits>;

// A terminal-based implementation of the QuizView interface.
export class TerminalQuizView : public QuizView {
public:
	/**
	 * @brief Gets the user's selection of a topic.
	 * @param topics The list of topics to choose from.
	 * @return The selected topic's index.
	 */
	int selectTopic(const std::vector<std::string>& topics);
    /**
	 * @brief Displays the question text to the user.
	 * @param questionText The text of the question to display. 
     */
    void displayQuestion(const std::string& questionText) override;
	/**
	 * @brief Gets the user's answer to the question.
	 * @return The user's answer to the question.
	 */
    bool getUserAnswer() override;
	/**
	 * @brief Displays the result of the user's answer.
	 * @param correct True if the user's answer was correct, false otherwise.
	 */
    void displayResult(bool correct) override;
	/**
	 * @brief Displays the final score to the user.
	 * @param score The final score to display.
	 */
    void displayFinalScore(int score) override;
};
