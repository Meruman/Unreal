// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"

void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();
    const FString WordListPath = FPaths::ProjectContentDir() / TEXT("WordsList/HiddenWordsList.txt");
    FFileHelper::LoadFileToStringArray(Words, *WordListPath);
    SetupGame();
    
}

void UBullCowCartridge::OnInput(const FString& Input) // When the player hits enter
{
    if (bGameOver)
    {
        ClearScreen();
        SetupGame();
    }
    else
    {
        ProcessGuess(Input);
    }
    
}

void UBullCowCartridge::SetupGame()
{
    HiddenWord = TEXT("cakes");
    Lives = HiddenWord.Len();
    bGameOver = false;

    PrintLine(TEXT("Hey there!"));
    PrintLine(TEXT("Guess the %i letter word!"), HiddenWord.Len());
    PrintLine(TEXT("You have %i lives to try and guess!"), Lives);
    PrintLine(TEXT("Press enter to continue..."));
    //PrintLine(TEXT("The hidden word is: %s"),*HiddenWord);
}

void UBullCowCartridge::EndGame()
{
    bGameOver = true;
    PrintLine(TEXT("Press enter to play again..."));
}

void UBullCowCartridge::ProcessGuess(FString Guess)
{
    //Check for isogram

        if(Guess.Len()!=HiddenWord.Len())
        {
            PrintLine(TEXT("the hidden word is %i characters long"), HiddenWord.Len());
        }
    
        else if (Guess == HiddenWord)
        {
            PrintLine(TEXT("You are correct!"));
            EndGame();
        }
        else if(!IsIsogram(Guess.ToLower()))
        {
            PrintLine(TEXT("No repeating Letters!"));
        }
        else
        {
            //Check bulls and cows
            --Lives;
            if(Lives==0)
            {
                PrintLine(TEXT("You ran out of lives"));
                PrintLine(TEXT("The hidden word was: %s"),*HiddenWord);
                EndGame();
            }
            else
            {
                PrintLine(TEXT("No, You lost a live, Lives: %i"),Lives);
                PrintLine(TEXT("Guess again!"));
            }
        }
}

bool UBullCowCartridge::IsIsogram(FString Word) const
{
    for(int32 i = 0; i<Word.Len()-1; i++)
    {
        for (int32 j = i+1; j<Word.Len();j++)
        {
            if(Word[i] == Word[j])
            {
                return false;
            }
        }
    }
    return true;
}