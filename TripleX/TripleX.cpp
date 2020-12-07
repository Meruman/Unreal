#include <iostream>
#include <ctime>

void PrintIntroduction(int LevelDificulty)
{
    //Story of the game
    std::cout << "Level: " << LevelDificulty;
    std::cout<< "\nThere is an organization called 'The institution' that have been doing experiments on humans, \ntheir goal is to make a superhuman army that will dominate the world, \nthey are close to achieve this and you are a part of a \nrebellion that wants to shut this organization down, \nyou have infiltrated in their main building and now you \nhave to set the main computer to self-destruct mode";
    std::cout<< "\n\nYou need to enter the correct codes to continue";
}

bool PlayGame (int LevelDificulty)
{
    PrintIntroduction(LevelDificulty);

    //Declare variables
    const int CodeA = rand()%LevelDificulty + LevelDificulty;
    const int CodeB = rand()%LevelDificulty + LevelDificulty;
    const int CodeC = rand()%LevelDificulty + LevelDificulty;

    const int CodeSum = CodeA + CodeB + CodeC;
    const int CodeProduct = CodeA * CodeB * CodeC;

    //Print out the clues
    std::cout<< "\n\nThere are 3 numbers in the code";
    std::cout<< "\nThe numbers add up to: " << CodeSum;
    std::cout<< "\nThe codes multiply to give: " << CodeProduct << std::endl;

    int GuessA, GuessB, GuessC, ProductGuess, SumGuess;

    std::cin >> GuessA >> GuessB >> GuessC;

    SumGuess = GuessA + GuessB + GuessC;
    ProductGuess = GuessA * GuessB * GuessC;

    if(SumGuess == CodeSum && ProductGuess == CodeProduct)
    {
        std::cout<< "You got the correct code, keep going!\n\n";
        return true;
    }
    else
    {
        std::cout<< "Guess again\n\n";
        return false;
    }
}

int main()
{
    srand(time(NULL));
    int LevelDifficulty = 1;
    int MaxDifficulty = 5;
    while(LevelDifficulty <= MaxDifficulty) //Loop the game until the max difficulty is reached
    {
        bool bLevelComplete;
        bLevelComplete = PlayGame(LevelDifficulty);
        std::cin.clear();
        std::cin.ignore();

        if(bLevelComplete)
        {
            ++LevelDifficulty;
        }
    }

    std::cout<<"Congratulations, you defeted the institution and saved the world";
    return 0;
}