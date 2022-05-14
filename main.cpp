#include <iostream>
using namespace std;

class Hangman
{

public:
    void drawing(int position)
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
};
int main()
{
    Hangman hangMan;
    for (int i= 1; i<=7 ; i++){
        hangMan.drawing(i);
    }
    return 0;
}