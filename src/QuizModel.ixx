export module QuizModel;

import <vector>;
import <string>;
import <cstddef>; // For std::byte
import bitutils;
import QuizModule;

// QuizModel manages the logic of the quiz, including questions and scoring.
export class QuizModel {
public:
	/**
	 * @brief Construct a new QuizModel.
	 * @param questions The questions in the quiz.
	 * @param correctAnswers The correct answers for each question.
	*/
    QuizModel(std::vector<Quiz> quizzes);

    /**
	 * @brief Get the question at the given index.
	 * @param index The index of the question.
	 * @return The question.
     */
    const std::string& getQuestion(int index) const;
	/**
	 * @brief Check if the user's answer is correct for the question at the given index.
	 * @param index The index of the question.
	 * @param userAnswer The user's answer.
	 * @return True if the user's answer is correct, false otherwise.
	 */
    bool checkAnswer(int index, bool userAnswer) const;
    /**
	 * @brief Mark the question at the given index as asked.
	 * @param index The index of the question.
     */
    void markQuestionAsked(int index);
	/**
	 * @brief Check if the question at the given index has been asked.
	 * @param index The index of the question.
	 * @return True if the question has been asked, false otherwise.
	 */
    bool isQuestionAsked(int index) const;
	/**
	 * @brief Check if all questions have been asked.
	 * @return True if all questions have been asked, false otherwise.
	 */
    bool allQuestionsAsked() const;
	/**
	 * @brief Get the current score.
	 * @return The current score.
	 */
    int getScore() const;
	/**
	 * @brief Update the score based on whether the answer was correct.
	 * @param correct True if the answer was correct, false otherwise.
	 */
    void updateScore(bool correct);
	/**
	 * @brief Get the total number of questions.
	 * @return The total number of questions.
	 */
    int getTotalQuestions() const;
	/**
	 * @brief Get the topics of the quizzes.
	 * @return The topics of the quizzes.
	 */
	std::vector<std::string> getTopics() const;
	/**
	 * @brief Set the quiz to the one at the given index.
	 * @param index The index of the quiz.
	 */
	void setQuiz(int index);

private:
	std::vector<Quiz> quizzes; // The quizzes with questions and answers.
	std::vector<std::string> questions; // The questions in the quiz.
	std::byte correctAnswers; // The correct answers for each question.
	std::byte askedQuestions; // Bitmask to track which questions have been asked.
    int score;
};
