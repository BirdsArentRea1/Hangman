#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <algorithm>
using namespace std;

const int MAX_INCORRECT = 6;
char incorrect[MAX_INCORRECT];
int numIncorrect = 0;
int misses = 0;

void displayHangman() {
    cout << "\n";
    switch (misses) {
        case 0:
            cout << "  +---+\n";
            cout << "  |   |\n";
            cout << "      |\n";
            cout << "      |\n";
            cout << "      |\n";
            cout << "      |\n";
            cout << "==========\n";
            break;
        case 1:
            cout << "  +---+\n";
            cout << "  |   |\n";
            cout << "  O   |\n";
            cout << "      |\n";
            cout << "      |\n";
            cout << "      |\n";
            cout << "==========\n";
            break;
        case 2:
            cout << "  +---+\n";
            cout << "  |   |\n";
            cout << "  O   |\n";
            cout << "  |   |\n";
            cout << "      |\n";
            cout << "      |\n";
            cout << "==========\n";
            break;
        case 3:
            cout << "  +---+\n";
            cout << "  |   |\n";
            cout << "  O   |\n";
            cout << "  |   |\n";
            cout << " /    |\n";
            cout << "      |\n";
            cout << "==========\n";
            break;
        case 4:
            cout << "  +---+\n";
            cout << "  |   |\n";
            cout << "  O   |\n";
            cout << "  |   |\n";
            cout << " / \\  |\n";
            cout << "      |\n";
            cout << "==========\n";
            break;
        case 5:
            cout << "  +---+\n";
            cout << "  |   |\n";
            cout << "  O   |\n";
            cout << "  |\\  |\n";
            cout << " / \\  |\n";
            cout << "      |\n";
            cout << "==========\n";
            break;
        case 6:
            cout << "  +---+\n";
            cout << "  |   |\n";
            cout << "  O   |\n";
            cout << " /|\\  |\n";
            cout << " / \\  |\n";
            cout << "      |\n";
            cout << "==========\n";
            break;
    }
}

void display(string guessedWord) {
    cout << "\n Word: ";
    for (int i = 0; i < guessedWord.length(); i++) {
        cout << guessedWord[i] << ' ';
    }
    cout << "\n Incorrect guesses: ";
    for (int i = 0; i < MAX_INCORRECT; i++) {
        cout << incorrect[i] << ' ';
    }
    cout << "\n Misses left: " << MAX_INCORRECT - misses << "\n";
    displayHangman();
}

string processGuess(char guess, string word, string guessedWord) {
    bool isCorrect = false;
    for (int i = 0; i < word.length(); i++) {
        if (word[i] == guess && guessedWord[i] == '_') {
            guessedWord[i] = guess;
            isCorrect = true;
        }
    }
    if (!isCorrect) {
        bool alreadyGuessed = false;
        for (int i = 0; i < numIncorrect; i++) {
            if (incorrect[i] == guess) {
                alreadyGuessed = true;
                break;
            }
        }
        if (!alreadyGuessed) {
            incorrect[numIncorrect++] = guess;
            misses++;
        }
    }
    return guessedWord;
}

int main() {
    string wordList[] = { "computer", "science", "programming", "hangman", "game" };
    srand(time(0));
    string word = wordList[rand() % 5];
    string guessedWord(word.length(), '_');

    cout << "Welcome to Hangman!\n";

    while (misses < MAX_INCORRECT && guessedWord != word) {
        display(guessedWord);
        cout << "Enter your guess: ";
        char guess;
        cin >> guess;

        string oldGuessedWord = guessedWord;
        guessedWord = processGuess(guess, word, guessedWord);

        if (guessedWord == oldGuessedWord) {
            cout << "That letter is wrong!\n";
        }
        else {
            cout << "Good guess!\n";
        }
    }

        if (guessedWord == word) {
            cout << "Congratulations! You guessed the word: " << word << "\n";
        }
        else {
            cout << "Game Over! The word was: " << word << "\n";
            displayHangman();
        }

        return 0;
    }

