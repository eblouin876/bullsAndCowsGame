#include "FBullCowGame.h"

FBullCowGame::FBullCowGame() { Reset(); } // Constructor function

int32 FBullCowGame::GetMaxTries() const { return MyMaxTries; }
int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }

void FBullCowGame::Reset()
{
	constexpr int32 MAX_TRIES = 8;
	MyMaxTries = MAX_TRIES;

	const FString HIDDEN_WORD = "planet";
	MyHiddenWord = HIDDEN_WORD;

	MyCurrentTry = 1;

	return;
}

// Receives a VALID guess, increments turn, and returns count
FBullCowCount FBullCowGame::SubmitGuess(FString Guess)
{
	// increment the turn number
	MyCurrentTry++;

	// setup return variable
	FBullCowCount BullCowCount;
	int32 HiddenWordLength = MyHiddenWord.length();
	// loop through all letters in the guess
	for (int32 i = 0; i < HiddenWordLength; i++) {
		// compare each letter against the hidden word
		for (int32 j = 0; j < HiddenWordLength; j++) {
			// if they match then
			if (Guess[i] == MyHiddenWord[j]) {
				if (i == j) {				
					// increment Bulls if they're in the same place
					BullCowCount.Bulls++;
				}
				else {
				// increment Cows if they're not
					BullCowCount.Cows++;
				}
			}	
		}
	}

	return BullCowCount;
}

bool FBullCowGame::IsGameWon() const
{
	return false;
}

bool FBullCowGame::CheckGuessValidity(FString)
{
	return false;
}
