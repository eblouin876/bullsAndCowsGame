#pragma once

#include "FBullCowGame.h"
#include <map>
#define TMap std::map // making syntax Unreal friendly

using int32 = int;

FBullCowGame::FBullCowGame() { Reset(); } // Constructor function

int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }
int32 FBullCowGame::GetHiddenWordLength() const { return MyHiddenWord.length(); }
bool FBullCowGame::IsGameWon() const { return bGameIsWon; }

int32 FBullCowGame::GetMaxTries() const 
{
	TMap<int32, int32> WordLengthToMaxTries{ {3, 5}, {4, 6}, {5, 9}, {6, 14}, {7, 20} };
	return WordLengthToMaxTries[MyHiddenWord.length()];
}

// Resets the game state
void FBullCowGame::Reset()
{
	MyCurrentTry = 1;
	bGameIsWon = false;

	return;
}


// Receives a VALID guess, increments turn, and returns count
FBullCowCount FBullCowGame::SubmitValidGuess(FString Guess)
{
	MyCurrentTry++;
	FBullCowCount BullCowCount;
	int32 WordLength = MyHiddenWord.length(); // assuming same length as guess
	
	for (int32 MHWChar = 0; MHWChar < WordLength; MHWChar++) { // loop through all letters in the guess
		for (int32 GChar = 0; GChar < WordLength; GChar++) { // compare each letter against the hidden word
			if (Guess[MHWChar] == MyHiddenWord[GChar]) { // if they match then
				if (MHWChar == GChar) { // increment Bulls if they're in the same place
					BullCowCount.Bulls++;
				}
				else { // increment Cows if they're not
					BullCowCount.Cows++;
				}
			}	
		}
	}
	if (BullCowCount.Bulls == WordLength) { bGameIsWon = true; }; // If the guess is correct, we set the gamestate to true
	return BullCowCount;
}

bool FBullCowGame::IsIsogram(FString Word) const
{
	if (Word.length() <= 1) { return true; } // treat 0 and 1 letter words as isograms

	TMap<char, bool> LetterSeen; // Define a hash table (map)
	for (auto Letter : Word) // for each letter in the word
	{
		Letter = tolower(Letter); // handles case insensitively
		if (LetterSeen[Letter]) { return false; }
		else { LetterSeen[Letter] = true; }
	}
	return true;
}

bool FBullCowGame::IsLowercase(FString Word) const
{
	for (auto Letter : Word)
	{
		if (!islower(Letter)) { return false; }
	}
	return true;
}

void FBullCowGame::SelectDifficulty(FString Difficulty) 
{
	TMap<FString, FString> WordList{ {"1", "pen"}, {"2", "soul"}, {"3", "ideas"}, {"4", "rocket"}, {"5", "capture"} };
	if(IsIsogram(WordList[Difficulty])) { MyHiddenWord = WordList[Difficulty]; }
}

EGuessStatus FBullCowGame::CheckGuessValidity(FString Guess) const
{
	if (!IsIsogram(Guess))
	{
		return EGuessStatus::Not_Isogram;
	}
	else if (!IsLowercase(Guess))
	{
		return EGuessStatus::Not_Lowercase; 
	}
	else if (Guess.length() != GetHiddenWordLength())
	{
		return EGuessStatus::Wrong_Length;
	}
	else
	{
		return EGuessStatus::OK;
	}
}
