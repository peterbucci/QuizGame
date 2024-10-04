module QuizModel;

QuizModel::QuizModel(std::vector<Quiz> quizzes)
	: quizzes(quizzes),
    askedQuestions(std::byte{ 0 }),
    score(0)
{}

const std::string& QuizModel::getQuestion(int index) const {
    return questions[index];
}

bool QuizModel::checkAnswer(int index, bool userAnswer) const {
	bool correctAnswer = BitUtils::getBit(correctAnswers, index); // Get the bit at the index from the correctAnswers byte
    return userAnswer == correctAnswer;
}

void QuizModel::markQuestionAsked(int index) {
	BitUtils::setBit(askedQuestions, index); // Set the bit at the index to 1
}

bool QuizModel::isQuestionAsked(int index) const {
	return BitUtils::getBit(askedQuestions, index); // Check if the bit at the index is 1
}

bool QuizModel::allQuestionsAsked() const {
    return askedQuestions == std::byte{ 0xFF };
}

int QuizModel::getScore() const {
    return score;
}

void QuizModel::updateScore(bool correct) {
    if (!correct) {
		score = (score == 0) ? 2 : score << 1; // Double the score if it's not 0 by shifting the bits to the left by 1, otherwise set it to 2.
    }
}

int QuizModel::getTotalQuestions() const {
    return static_cast<int>(questions.size());
}

std::vector<std::string> QuizModel::getTopics() const {
	std::vector<std::string> topics;
	for (const auto& quiz : quizzes) {
		topics.push_back(quiz.topic);
	}
	return topics;
}

void QuizModel::setQuiz(int index) {
	questions = quizzes[index].questions; // Get the questions from the first quiz
	correctAnswers = quizzes[index].answers; // Get the correct answers from the first quiz
}
