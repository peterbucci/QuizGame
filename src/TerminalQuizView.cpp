module TerminalQuizView;

int TerminalQuizView::selectTopic(const std::vector<std::string>& topics) {
    std::cout << "Please select a topic:" << std::endl;
    for (size_t i = 0; i < topics.size(); ++i) {
        std::cout << i + 1 << ". " << topics[i] << std::endl;
    }

    int choice = 0;
    while (true) {
        std::cout << "Enter the number corresponding to your choice: ";
        if (std::cin >> choice && choice > 0 && choice <= topics.size()) {
            // Return the selected topic
			return choice - 1;
        }
        else {
            std::cout << "Invalid input. Please enter a valid number between 1 and " << topics.size() << "." << std::endl;
            std::cin.clear(); // Clear the error flags.
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore the rest of the input.
        }
    }
}

void TerminalQuizView::displayQuestion(const std::string& questionText) {
    std::cout << questionText << " (T/F): ";
}

bool TerminalQuizView::getUserAnswer() {
    char userInput;
    bool validInput = false;
    bool userAnswer = false;

    /*
	 * Loop until the user enters a valid input.
	 * The user must enter 'T' or 'F'.
     */
    while (!validInput && (std::cin >> userInput)) {
        if (userInput == 'T' || userInput == 't') {
            userAnswer = true;
            validInput = true;
        }
        else if (userInput == 'F' || userInput == 'f') {
            userAnswer = false;
            validInput = true;
        }
        else {
            std::cout << "Invalid input. Please enter 'T' or 'F': ";
			std::cin.clear(); // Clear the error flags.
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore the rest of the input.
        }
    }

    return userAnswer;
}

void TerminalQuizView::displayResult(bool correct) {
    if (correct) {
        std::cout << "Correct!" << std::endl;
    }
    else {
        std::cout << "Incorrect." << std::endl;
    }
}

void TerminalQuizView::displayFinalScore(int score) {
    std::cout << "Total penalty score: " << score << std::endl;
}
