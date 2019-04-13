#pragma once
#include <string>



class FBullCowGame {
public:
	// Constructor method (automatically runs on instantiation)
	FBullCowGame();

	// Getter functions and other functions that don't change anything in the class
	int GetMaxTries() const; 
	int GetCurrentTry() const;
	bool IsGameWon() const;

	bool CheckGuessValidity(std::string); // TODO make a more rich return value (something that tells us what comes back)
	void Reset(); // TODO make a more rich return value (something that tells us what comes back)


private:
	// Member variables and helper functions
	int MyCurrentTry; // Initialized in constructor
	int MyMaxTries; // Initialized in constructor
};