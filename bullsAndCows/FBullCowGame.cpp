#include "FBullCowGame.h"

FBullCowGame::FBullCowGame() { Reset(); } // Constructor function

int32 FBullCowGame::GetMaxTries() const { return MyMaxTries; }
int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }
int32 FBullCowGame::GetHiddenWordLength() const { return MyHiddenWord.length(); }

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
	MyCurrentTry++; // increment the turn number

	FBullCowCount BullCowCount;	// setup return variable
	int32 HiddenWordLength = MyHiddenWord.length();
	
	for (int32 MHWChar = 0; MHWChar < HiddenWordLength; MHWChar++) { // loop through all letters in the guess
		for (int32 GChar = 0; GChar < HiddenWordLength; GChar++) { // compare each letter against the hidden word
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
	return BullCowCount;
}

bool FBullCowGame::IsGameWon() const
{
	return false;
}

bool FBullCowGame::CheckGuessValidity(FString Guess) const
{
	if (Guess == MyHiddenWord) {
		return true;
	}
	else {
	return false;
	}
}
