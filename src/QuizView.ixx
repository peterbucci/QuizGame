export module QuizView;

import <string>;
import <vector>;

export class QuizView {
public:
	/**
	 * @brief Destructor for the QuizView class.
     */
    virtual ~QuizView() = default;

	/**
	 * @brief Gets the user's selection of a topic.
	 * @param topics The list of topics to choose from.
	 * @return The selected topic's index.
	 */
    virtual int selectTopic(const std::vector<std::string>& topics) = 0;
    /**
	* @brief Displays the question text to the user.
	* @param questionText The text of the question to display.
     */
    virtual void displayQuestion(const std::string& questionText) = 0;
    /**
	 * @brief Gets the user's answer to the question.
	 * @return The user's answer to the question.
     */
    virtual bool getUserAnswer() = 0;
    /**
	 * @brief Displays the result of the user's answer.
	 * @param True if the user's answer was correct, false otherwise.
     */
    virtual void displayResult(bool correct) = 0;
    /**
	 * @brief Displays the final score to the user.
	 * @param score The user's final score.
     */
    virtual void displayFinalScore(int score) = 0;
};
