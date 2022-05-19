#include <iostream>
#include <string>
using namespace std;

class Hangman
{
public:
    string guessList[20];
    int searchResultPos;
    int position;
    string guessAnswer;
    int guessIndex = 0;
    string userAnswer;
    string asteriskClue;
    bool hasWon = false;
    bool outOfLoop = false;
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

    void makeAsteriskClue(){
        int len = findLengthofAnswer();
        for (int i = 0; i < len; i++)
        {
            asteriskClue += "*";
        }
    }  

    void showClue()
    {
        cout << "\n" << asteriskClue <<"\n"<<"Guessed: ";
        displayPreviousGuess();
    }

    void askToGuess()
    {
        cout << "\nGuess alphabet : ";
        cin >> userAnswer;
        // Taking only first letter
        userAnswer = userAnswer[0];  
        guessList[guessIndex] = userAnswer;
        guessIndex += 1;
    }

    //  Check mechanism
    void checkGuess()
    {
        searchResultPos = guessAnswer.find_first_of(userAnswer);
        if (searchResultPos == -1)
        {   
            //  Guessed incorrectly
            position++;     
        }
        else
        {
            //  Guessed correctly
            asteriskClue.replace(searchResultPos, 1, string(userAnswer));
        }

    }
    void checkHasWon(){
        int pos = asteriskClue.find_first_of("*");
        if (pos == -1){
            //  No asterisk remaining
            outOfLoop = true;
            hasWon = true;
        }
    }
    void displayPreviousGuess(){
        int len = guessIndex;
        for (int i=0; i<guessIndex; i++){
            cout << guessList[i] << ", ";
        }
    }

    void checkGameOver(){
        if (position == 7){
            //  Game Over or Hanged
            cout << "Game Over"<<endl;
            outOfLoop = true;
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
    string answer = "tokha";
    Hangman h = Hangman(1, answer);
    //  Make asterisk Clue
    h.makeAsteriskClue();
    while (1){
        h.drawHangMan(h.position);
        h.showClue();
        h.askToGuess();
        h.checkGuess();
        h.checkHasWon();
        h.checkGameOver();
        if (h.outOfLoop == true)    break;
    }
    if (h.hasWon)   cout << "\n\n Yay!! You were saved."<<endl;
    else    {
        cout << "\n\nOops!!You got hanged."<< endl;
        h.drawHangMan(7);
    }return 0;
}