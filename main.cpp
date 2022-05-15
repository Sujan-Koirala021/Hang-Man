#include <iostream>
#include <string>
using namespace std;

class Hangman
{
public:
    int position;
    string guessAnswer;
    char userAnswer;
    string alreadyGuessed[26];
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
        for (int i = 0; i<len; i++){
            cout << "*";
        }
    }
    void askToGuess(){
        cout << "\nGuess alphabet : " ;
        cin >> userAnswer;

    }
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
    cout << "\n Your answer : " << h.userAnswer;
    return 0;
}