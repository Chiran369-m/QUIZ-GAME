#include <iostream>
#include <string>
#include <stack>
#include <queue>

using namespace std;


struct MCQQuestion {
    string question;
    string optionA;
    string optionB;
    string optionC;
    string correctAnswer;
};


void displayMenu() {
    cout << "\nMenu:\n";
    cout << "1. Answer the current question\n";
    cout << "2. Skip the question\n";
    cout << "3. Quit the game\n";
    cout << "Enter your choice: ";
}

int main() {
   
    stack<MCQQuestion> skippedQuestions;

  
    queue<MCQQuestion> mcqQuestions;

 
    MCQQuestion q1 = {"Which data structure uses LIFO (Last In, First Out) order?", "A) Stack", "B) Queue", "C) Linked List", "A"};
    MCQQuestion q2 = {"What is the time complexity of inserting an element at the end of an array?", "A) O(1)", "B) O(n)", "C) O(log n)", "A"};
    MCQQuestion q3 = {"Which data structure follows the FIFO (First In, First Out) principle?", "A) Queue", "B) Stack", "C) Linked List", "A"};
    MCQQuestion q4 = {"What is the worst-case time complexity of searching in a binary search tree?", "A) O(n)", "B) O(log n)", "C) O(n log n)", "B"};
    MCQQuestion q5 = {"Which sorting algorithm has the best average-case time complexity?", "A) Quick Sort", "B) Bubble Sort", "C) Selection Sort", "A"};
    MCQQuestion q6 = {"In a circular linked list, the last node points to the ____.", "A) this pointer", "B) tail pointer", "C) first node", "C"};
   

    mcqQuestions.push(q1);
    mcqQuestions.push(q2);
    mcqQuestions.push(q3);
    mcqQuestions.push(q4);
    mcqQuestions.push(q5);
    mcqQuestions.push(q6);
 

    int score = 0; 

    while (!mcqQuestions.empty()) {
        MCQQuestion currentQuestion = mcqQuestions.front();
        mcqQuestions.pop();

        cout << "\nQuestion: " << currentQuestion.question << endl;
        cout << currentQuestion.optionA << endl;
        cout << currentQuestion.optionB << endl;
        cout << currentQuestion.optionC << endl;

        displayMenu();

        int choice;
        cin >> choice;

        switch (choice) {
            case 1:
                {
                    cout << "Enter your answer (A/B/C): ";
                    string userAnswer;
                    cin >> userAnswer;
                    if (userAnswer == currentQuestion.correctAnswer) {
                        cout << "Correct! +1 point\n";
                        score++;
                    } else {
                        cout << "Incorrect! The correct answer is " << currentQuestion.correctAnswer << endl;
                    }
                }
                break;
            case 2: 
                skippedQuestions.push(currentQuestion);
                cout << "Question skipped.\n";
                break;
            case 3: 
                cout << "Game over. ";
                if (score == 0) {
                    cout << "You scored only 0.\n";
                } else {
                    cout << "Congratulations! You scored " << score << ".\n";
                }
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
        }

    
        if (!skippedQuestions.empty()) {
            cout << "\nSkipped question:\n";
            MCQQuestion skipped = skippedQuestions.top();
            skippedQuestions.pop();
            cout << skipped.question << endl;
          
        }
    }

    cout << "Your final score: " << score << endl;

    return 0;
}
