// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"

void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();

    SetupGame();

    // PrintLine(TEXT("Hello, the hidden word is %s"), *HiddenWord);
}

void UBullCowCartridge::OnInput(const FString& Input) // When the player hits enter
{
    if (bGameOver)
    {
        ClearScreen();

        SetupGame();

        return;
    }

    if (Input.Equals(HiddenWord, ESearchCase::IgnoreCase))
    {
        PrintLine(TEXT("You have guessed the word!"));

        EndGame();

        return;
    }
    else
    {
        PrintLine(TEXT("Sorry. You failed to guess the word!"));

        PrintLine(TEXT("%i lives remaining."), --Lives);
    }

    if (Lives <= 0)
    {
        EndGame();
    }
}

void UBullCowCartridge::SetupGame()
{
    bGameOver = false;

    HiddenWord = TEXT("Orange");

    Lives = HiddenWord.Len();

    PrintLine(TEXT("You have %i lives. Guess the word (%i letters) and press Enter..."), Lives, HiddenWord.Len());
}

void UBullCowCartridge::EndGame()
{
    bGameOver = true;

    PrintLine(TEXT("Game over. Press Enter to continue."));
}