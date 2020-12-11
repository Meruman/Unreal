// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"



void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();
    const FString WordListPath = FPaths::ProjectContentDir() / TEXT("WordsList/HiddenWordsList.txt");
    //FFileHelper::LoadFileToStringArray(WordsList, *WordListPath);
    FFileHelper::LoadFileToStringArrayWithPredicate(WordsList, *WordListPath, [](const FString& Word) { return Word.Len() < 8; });
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
        ProcessGuess(*Input);
    }
    
}

void UBullCowCartridge::SetupGame()
{
    HiddenWord = WordsList[FMath::RandRange(0,WordsList.Num()-1)];
    Lives = HiddenWord.Len();
    bGameOver = false;

    PrintLine(TEXT("Hey there!"));
    PrintLine(TEXT("Guess the %i letter word!"), HiddenWord.Len());
    PrintLine(TEXT("You have %i lives to try and guess!"), Lives);
    PrintLine(TEXT("Press enter to continue..."));
    PrintLine(TEXT("The hidden word is: %s"),*HiddenWord);
}

void UBullCowCartridge::EndGame()
{
    bGameOver = true;
    PrintLine(TEXT("Press enter to play again..."));
}

void UBullCowCartridge::ProcessGuess(const FString& Guess)
{
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
        --Lives;
        if(Lives==0)
        {
            PrintLine(TEXT("You ran out of lives"));
            PrintLine(TEXT("The hidden word was: %s"),*HiddenWord);
            EndGame();
        }
        else
        {
            FBullsCows Counters;
            Counters = GetBullCows(Guess);
            PrintLine(TEXT("You have %i Bulls and %i Cows"), Counters.BullsCount, Counters.CowsCount);
            PrintLine(TEXT("You lost a live, Lives: %i"),Lives);
            PrintLine(TEXT("Guess again!"));
        }
    }
}

bool UBullCowCartridge::IsIsogram(const FString& Word) const
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

FBullsCows UBullCowCartridge::GetBullCows(const FString& Guess) const
{
    FBullsCows Counters;
    for(int32 index = 0; index < Guess.Len(); index++)
    {
        if(Guess[index] == HiddenWord[index])
        {
            Counters.BullsCount++;
            continue;
        }
        for(int32 compare = 0; compare < Guess.Len(); compare++)
        {
            if(index!=compare && Guess[index] == HiddenWord[compare])
            {
                Counters.CowsCount++;
                break;
            }
        }
    }
    return Counters;
}