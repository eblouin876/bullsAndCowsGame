#pragma once
#include <string>

using FString = std::string;
using int32 = int;

class FBullCowGame {
public:
	// Constructor method (automatically runs on instantiation)
	FBullCowGame();

	// Getter functions and other functions that don't change anything in the class
	int32 GetMaxTries() const; 
	int32 GetCurrentTry() const;
	bool IsGameWon() const;

	bool CheckGuessValidity(FString); // TODO make a more rich return value (something that tells us what comes back)
	void Reset(); // TODO make a more rich return value (something that tells us what comes back)
	// provide a method for counting bulls and cows, and incrementing try number


private:
	// Member variables and helper functions
	int32 MyCurrentTry; // Initialized in constructor
	int32 MyMaxTries; // Initialized in constructor
};