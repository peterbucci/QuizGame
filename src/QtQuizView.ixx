export module QtQuizView;

import QuizView;
import <string>;
import <vector>;

export class QtQuizView : public QuizView {
public:
    QtQuizView();
    ~QtQuizView();

    int selectTopic(const std::vector<std::string>& topics) override;
    void displayQuestion(const std::string& questionText) override;
    bool getUserAnswer() override;
    void displayResult(bool correct) override;
    void displayFinalScore(int score) override;

private:
    std::string currentQuestionText;
    bool userAnswer;
};