/*
Game logic - no view code or direct user interaction
The game is a simple word guess game based on mastermind
*/

#pragma once
#include <string>

// making syntax Unreal friendly
using FString = std::string;
using int32 = int;

struct FBullCowCount
{
	int32 Bulls = 0;
	int32 Cows = 0;
};

// Status codes for checking the input word status
enum class EGuessStatus
{
	Invalid_Status,
	OK,
	Not_Isogram,
	Wrong_Length,
	Not_Lowercase
};

class FBullCowGame {
public:
	FBullCowGame(); // Constructor method (automatically runs on instantiation)

	// Getter functions and other functions that don't mutate any of the private variables in the class
	int32 GetMaxTries() const; 
	int32 GetCurrentTry() const;
	int32 GetHiddenWordLength() const;
	void SelectDifficulty(FString);

	bool IsGameWon() const;
	EGuessStatus CheckGuessValidity(FString) const;
	
	void Reset();
	FBullCowCount SubmitValidGuess(FString);


private:
	// Member variables and helper functions
	int32 MyCurrentTry; // Initialized in constructor
	FString MyHiddenWord; // Initialized in constructor
	bool bGameIsWon;

	bool IsIsogram(FString) const;
	bool IsLowercase(FString) const;

};