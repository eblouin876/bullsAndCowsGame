#pragma once
#include <string>



class FBullCowGame {
public:
	void Reset(); // TODO make a more rich return value (something that tells us what comes back)
	int GetMaxTries(); 
	int GetCurrentTry();
	bool IsGameWon();
	bool CheckGuessValidity(std::string); // TODO make a more rich return value (something that tells us what comes back)


private:
	// Member variables and helper functions
	int MyCurrentTry;
	int MyMaxTries;
};