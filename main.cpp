#include <iostream>
#include <string>
using namespace std;

class Hangman
{
public:
    int searchResultPos;
    int position;
    string guessAnswer;
    string userAnswer;
    string alreadyGuessed[26];
    string asteriskClue;
    void drawHangMan(int position)
    {
        switch (position)
        {
        case 1:
            cout << " ___________" << endl;
            cout << " |         }" << endl;
            cout << " |         " << endl;
            cout << "_|______________" << endl;
            break;
        case 2:
            cout << " ___________" << endl;
            cout << " |         }" << endl;
            cout << " |       \\  " << endl;
            cout << "_|______________" << endl;
            break;
        case 3:
            cout << " ___________" << endl;
            cout << " |         }" << endl;
            cout << " |       \\ 0 " << endl;
            cout << "_|______________" << endl;
            break;
        case 4:
            cout << " ___________" << endl;
            cout << " |         }" << endl;
            cout << " |       \\ 0 /" << endl;
            cout << "_|______________" << endl;
            break;
        case 5:
            cout << " ___________" << endl;
            cout << " |         }" << endl;
            cout << " |       \\ 0 /" << endl;
            cout << " |         |" << endl;
            cout << "_|______________" << endl;
            break;
        case 6:
            cout << " ___________" << endl;
            cout << " |         }" << endl;
            cout << " |       \\ 0 /" << endl;
            cout << " |         |" << endl;
            cout << " |        /  " << endl;
            cout << "_|______________" << endl;
            break;
        case 7:
            cout << " ___________" << endl;
            cout << " |         }" << endl;
            cout << " |       \\ 0 /" << endl;
            cout << " |         |" << endl;
            cout << " |        / \\ " << endl;
            cout << "_|______________" << endl;
        }
    }

    int findLengthofAnswer()
    {
        return guessAnswer.length();
    }

    void showClue()
    {
        int len = findLengthofAnswer();
        for (int i = 0; i < len; i++)
        {
            asteriskClue += "*";
        }
        cout << asteriskClue << endl;
    }

    void askToGuess()
    {
        cout << "\nGuess alphabet : ";
        cin >> userAnswer;
        userAnswer = userAnswer[0]; // Taking only first letter
    }
    void checkGuess()
    {
        searchResultPos = guessAnswer.find_first_of(userAnswer);
        if (searchResultPos == -1)
        {
            //  Further Hanged
            cout << "Milena" << endl;
        }
        else
        {
            //  Guessed correctly
            asteriskClue.replace(searchResultPos, 1, string(userAnswer));
            cout << "Milyo" << endl;
        }
    }
    // Constructor
    Hangman(int hangmanLevel, string answer)
    {
        position = hangmanLevel;
        guessAnswer = answer;
    }
};

int main()
{
    string answer = "monkey";
    Hangman h = Hangman(1, answer);
    // while (1){
    //     h.drawHangMan(h.position);
    // }
    h.showClue();
    h.askToGuess();
    h.checkGuess();
    cout << "\n Your answer : " << h.userAnswer;
    return 0;
}