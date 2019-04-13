#include "FBullCowGame.h"
#include <map>
#define TMap std::map

using int32 = int;

FBullCowGame::FBullCowGame() { Reset(); } // Constructor function

int32 FBullCowGame::GetMaxTries() const { return MyMaxTries; }
int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }
int32 FBullCowGame::GetHiddenWordLength() const { return MyHiddenWord.length(); }
bool FBullCowGame::IsGameWon() const { return bGameIsWon; }


void FBullCowGame::Reset()
{
	constexpr int32 MAX_TRIES = 8;
	MyMaxTries = MAX_TRIES;

	const FString HIDDEN_WORD = "planet";
	MyHiddenWord = HIDDEN_WORD;

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
	// treat 0 and 1 letter words as isograms
	// Define a hash table (map)
	// For each letter in our input
		// If the letter is not in our hash table
			// Place it in the table
		// Otherwise the letter is in the hash table
			// the word is not an isogram
	return true;
}

EGuessStatus FBullCowGame::CheckGuessValidity(FString Guess) const
{
	if (!IsIsogram(Guess))// if the guess isn't an isogram
	{
		return EGuessStatus::Not_Isogram; // TODO write function to check isogram
	}
	else if (false)// if the guess isn't all lowercase 
	{
		return EGuessStatus::Not_Lowercase; // TODO write function to check lowercase
	}
	else if (Guess.length() != GetHiddenWordLength())// if the guess is the wrong length 
	{
		return EGuessStatus::Wrong_Length;
	}
	else
	{
		return EGuessStatus::OK;
	}
}
