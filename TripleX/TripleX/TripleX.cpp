#include <iostream>
#include <cstring>
#include <ctime>

using namespace std;

void welcomeMessages(int Difficulty)
{
    // Welcome Messages  
    cout << "You are a secret agent breaking into a " << Difficulty << " secure server room..." << endl;
    cout << "Enter the correct code to continue..." << endl;
}

bool playGame(int Difficulty)
{

    // Declaration statements 
    const int a = rand() % Difficulty + Difficulty;
    const int b = rand() % Difficulty + Difficulty;
    const int c = rand() % Difficulty + Difficulty;

    const int codeSum = a + b + c;
    const int codeProduct = a * b * c;

    // Print out the sum and the product 
    cout << "--------------------------------------------" <<endl;
    cout << "\t There are 3 numbers in the code" << endl;
    cout << "\t The codes add-up to: " << codeSum << endl;
    cout << "\t The codes multiply to give: " << codeProduct << endl;

    // Declare 3 guessed input number and print them out
    int GuessA, GuessB, GuessC;
    cout << "Your first number: ";
    cin >> GuessA;
    cout << "Your second number: ";
    cin >> GuessB;
    cout << "Your Third number: ";
    cin >> GuessC;
    cout << "You entered: " << GuessA << GuessB << GuessC << endl;
    cout << endl;

    // Declare guess sum and product
    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;

    // Check if there are correct or not
    if (GuessSum == codeSum && GuessProduct == codeProduct)
    {
        cout << "*** Well done agent! You have extracted a file ! Keep going ! ***" << endl;
        return true;
    }
    else {
        cout << "*** Be careful, agent! You entered the wrong wode ! Try again !***" << endl;
        return false;
    }
}

int main()
{
    int levelDifficulty = 1;
    const int maxDifficulty = 3;
    int yourLife = 3;
    int collectedFile = 0;
    srand(time(NULL)); // create new random sequence based on time of day

    welcomeMessages(levelDifficulty);

    while (levelDifficulty <= maxDifficulty) // Loop game until all levels complete
    {
        bool bLevelComplete;


        bLevelComplete = playGame(levelDifficulty);

        cin.clear(); // Clears any errors
        cin.ignore(); // Discards the buffer

        if (bLevelComplete)
        {
            // Increase the level difficulty and count the wins
            ++levelDifficulty;
            collectedFile++;
        }
        else
        {
            --yourLife;
            cout << "You have " << yourLife << " chances left !" << endl;
        }

        if (yourLife == 0)
        {
            cout << "Mission Fail...Please restart !" << endl;
            break;
        }
    }

    if (collectedFile == 3)
        cout << "*** Great work agent! You got all the files! Now get out of there !***" << endl;

    return 0;
}