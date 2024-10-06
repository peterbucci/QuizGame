module;
// Include Qt headers using #include
#include <QApplication>
#include <QDialog>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QInputDialog>
#include <QMessageBox>
#include <QStringList>

module QtQuizView;

QtQuizView::QtQuizView() {
    // Constructor implementation
}

QtQuizView::~QtQuizView() {
    // Destructor implementation
}

int QtQuizView::selectTopic(const std::vector<std::string>& topics) {
    QStringList items;
    for (const auto& topic : topics) {
        items << QString::fromStdString(topic);
    }

    bool ok = false;
    QString item = QInputDialog::getItem(nullptr, "Select Topic",
        "Please select a topic:", items, 0, false, &ok);
    if (ok && !item.isEmpty()) {
        int index = items.indexOf(item);
        return index;
    }
    else {
        // If the user cancels, return -1 (work on later)
        return -1;
    }
}

void QtQuizView::displayQuestion(const std::string& questionText) {
    currentQuestionText = questionText;
}

bool QtQuizView::getUserAnswer() {
    QDialog dialog;
    dialog.setWindowTitle("Quiz Question");

    QVBoxLayout* layout = new QVBoxLayout(&dialog);

    QLabel* label = new QLabel(QString::fromStdString(currentQuestionText));
    layout->addWidget(label);

    QPushButton* trueButton = new QPushButton("True");
    QPushButton* falseButton = new QPushButton("False");

    layout->addWidget(trueButton);
    layout->addWidget(falseButton);

    QObject::connect(trueButton, &QPushButton::clicked, [&]() {
        userAnswer = true;
        dialog.accept();
        });
    QObject::connect(falseButton, &QPushButton::clicked, [&]() {
        userAnswer = false;
        dialog.accept();
        });

    dialog.exec();
    return userAnswer;
}

void QtQuizView::displayResult(bool correct) {
    QString message = correct ? "Correct!" : "Incorrect.";
    QMessageBox::information(nullptr, "Result", message);
}

void QtQuizView::displayFinalScore(int score) {
    QString message = QString("Total penalty score: %1").arg(score);
    QMessageBox::information(nullptr, "Final Score", message);
}
