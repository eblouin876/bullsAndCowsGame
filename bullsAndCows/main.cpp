/* 
This is the console executable that makes use of the BullCow Class.
This is the console executable that makes use of the BullCow Class.
This acts as the view in a MVC pattern and is responsible for all
user interaction. For game logic, see the FBullCowGame class.
*/

#include <iostream>
#include <string>
#include "FBullCowGame.h"

using FText = std::string; // FText is typcially used for user interaction
using int32 = int;

void PrintIntro();
void PlayGame();
FText GetGuess();
bool AskToPlayAgain();

// Instantiate a new game
FBullCowGame BCGame;


// Entry point for the application
int main()
{
	bool bPlayAgain = false;
	do {
		PrintIntro();
		PlayGame();
		bPlayAgain = AskToPlayAgain();
	} 
	while (bPlayAgain);

	return 0; // Exit the application
}

// Introduce the game
void PrintIntro()
{
	constexpr int32 WORD_LENGTH = 9;
	std::cout << "Welcome to Bulls and Cows, a fun word game.\n";
	std::cout << "Can you guess the " << WORD_LENGTH;
	std::cout << " letter isogram I'm thinking of?\n";
	std::cout << std::endl;
	return;
}

// Loop for the number of turns asking for guesses
void PlayGame()
{
	BCGame.Reset();

	int32 MaxTries = BCGame.GetMaxTries();

	// loop for the number of turns asking for guesses
	for (int32 i = 0; i < MaxTries; i++) { // TODO modify to while loop once we have built validation
		FText Guess = GetGuess(); // TODO Validate guesses

		// Submit valid guess to BCGame
		// Print number of bulls and cows

		std::cout << "Your guess was: " << Guess << std::endl;
		std::cout << std::endl;
	}

	// TODO Summarise game
}

// Get a guess from the player and returns it as a string
FText GetGuess()
{
	int32 CurrentGuess = BCGame.GetCurrentTry();
	std::cout << "Try "<< CurrentGuess << " Enter your guess: ";
	FText Guess = "";
	std::getline(std::cin, Guess);

	return Guess;
}

// Ask the player if they want to play another game
bool AskToPlayAgain()
{
	std::cout << "Do you want to play again? (y/n) ";
	FText Response = "";
	std::getline(std::cin, Response);
	return (Response[0] == 'y' || Response[0] == 'Y');
}
