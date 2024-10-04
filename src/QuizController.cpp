module QuizController;

QuizController::QuizController(QuizModel& model, QuizView& view)
    : model(model),
    view(view),
	gen(std::random_device{}()) // Seed the random number generator
{}

void QuizController::run() {
	int selectedTopic = view.selectTopic(model.getTopics()); // Get the user's selected topic
	model.setQuiz(selectedTopic); // Set the quiz to the selected topic

    int totalQuestions = model.getTotalQuestions(); // Get total number of questions for the selected quiz
    std::uniform_int_distribution<int> dis(0, totalQuestions - 1); // Initialize the distribution based on the total number of questions

    while (!model.allQuestionsAsked()) {
		int questionIndex = dis(gen); // Get a random question index

		// Skip questions that have already been asked
        if (model.isQuestionAsked(questionIndex)) {
            continue;
        }

		model.markQuestionAsked(questionIndex); // Mark the question as asked

		view.displayQuestion(model.getQuestion(questionIndex)); // Display the question
		bool userAnswer = view.getUserAnswer(); // Get the user's answer
		bool correct = model.checkAnswer(questionIndex, userAnswer); // Check if the answer is correct

		model.updateScore(correct); // Update the score
		view.displayResult(correct); // Display the result
    }

	view.displayFinalScore(model.getScore()); // Display the final score
}
