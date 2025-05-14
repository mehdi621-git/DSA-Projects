#include <iostream>
#include <vector>
#include <queue>
#include <thread>
#include <chrono>
#include <atomic>
#include <limits>
#include <mutex>
#include <iomanip>

using namespace std;
using namespace std::chrono;

struct Question {
    string questionText;
    vector<string> options;
    int correctOption;
};

atomic<bool> timeUp(false);
atomic<bool> answered(false);
mutex inputMutex;
int userInput = -1;

void showCountdown(int seconds) {
    for (int i = seconds; i > 0; i--) {
        if (answered) return;
        cout << "\rTime left: " << i << " seconds " << flush;
        this_thread::sleep_for(1s);
    }
    if (!answered) {
        timeUp = true;
        cout << "\rTime's up!                          \n";
    }
}

void getUserAnswer() {
    int answer;
    //cout << "Your answer: ";
    if (cin >> answer) {
        lock_guard<mutex> lock(inputMutex);
        userInput = answer - 1;
        answered = true;
    } else {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

int askQuestionWithTimer(Question q, int timeLimitInSeconds) {
    cout << "\n" << q.questionText << "\n";
    for (int i = 0; i < q.options.size(); i++) {
        cout << i + 1 << ". " << q.options[i] << "\n";
    }

    timeUp = false;
    answered = false;
    userInput = -1;

    thread timerThread(showCountdown, timeLimitInSeconds);
    thread inputThread(getUserAnswer);

    auto startTime = steady_clock::now();
    while (true) {
        if (answered || timeUp) break;
        this_thread::sleep_for(milliseconds(100));
    }

    if (inputThread.joinable()) inputThread.detach(); // stop waiting for input
    timerThread.join();

    if (timeUp || userInput < 0 || userInput >= q.options.size()) return -1;

    return userInput;
}

int main() {
    cout << "------- Welcome to the Quiz! --------\n\n";
    cout << "You will be given 10 seconds for each question to answer.\n";
    cout << "Press 'y' to start Quiz or 'n' to exit: ";

    char start;
    cin >> start;

    if (start == 'y' || start == 'Y') {
        queue<Question> quiz;
        int score = 0;

        quiz.push({"What is 2 + 2?", {"3", "4", "5", "6"}, 1});
        quiz.push({"Capital of Pakistan?", {"Lahore", "Karachi", "Islamabad", "Multan"}, 2});
        quiz.push({"What color is the sky?", {"Blue", "Green", "Red", "Yellow"}, 0});
        quiz.push({"What is 6-5*6+7?",{"13", "17", "-59", "50"},1}); 

        int totalQuestions = quiz.size();
        int timeLimit = 10;

        while (!quiz.empty()) {
            Question q = quiz.front();
            quiz.pop();

            int userAnswer = askQuestionWithTimer(q, timeLimit);

            if (userAnswer == -1) {
                cout << "No valid answer provided in time.\n";
            } else if (userAnswer == q.correctOption) {
                cout << "Correct Answer!\n";
                score++;
            } else {
                cout << "Wrong Answer! Correct was: " << q.options[q.correctOption] << "\n";
            }
            
            cout << "--------------------------\n";
            this_thread::sleep_for(1s); // Small pause for readability
        }
        
        cout << "Quiz Complete! Your final score: " << score << "/" << totalQuestions << "\n";
        float prtg = ((float)score/(float)totalQuestions)*100;
        cout << fixed << setprecision(2) << endl;
        cout << "And percentage is :" << prtg <<"%"<< endl;
        if( prtg < 50 ){
            cout << "You fail to pass the quiz!" << endl;
        }else if( prtg >= 50 && prtg <= 70 ){
            cout << "You maybe considered for the interview stay updated!" << endl;
        }
        else if(prtg > 70 ){
            cout << "Congratulations You will be invited for the interview stay updated!" << endl;
        }
    } else {
        cout << "You exited the quiz!\n";
    }
    
    return 0;
}