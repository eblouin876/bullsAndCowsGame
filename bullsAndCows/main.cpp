#include <iostream>
#include <string>
#include "FBullCowGame.h"

void PrintIntro();
void PlayGame();
std::string GetGuess();
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
	constexpr int WORD_LENGTH = 9;
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

	int MaxTries = BCGame.GetMaxTries();

	// loop for the number of turns asking for guesses
	for (int i = 0; i < MaxTries; i++) { // TODO modify to while loop once we have built validation
		std::string Guess = GetGuess(); // TODO Validate guesses

		// Submit valid guess to BCGame
		// Print number of bulls and cows

		std::cout << "Your guess was: " << Guess << std::endl;
		std::cout << std::endl;
	}

	// TODO Summarise game
}

// Get a guess from the player and returns it as a string
std::string GetGuess()
{
	int CurrentGuess = BCGame.GetCurrentTry();
	std::cout << "Try "<< CurrentGuess << " Enter your guess: ";
	std::string Guess = "";
	std::getline(std::cin, Guess);

	return Guess;
}

// Ask the player if they want to play another game
bool AskToPlayAgain()
{
	std::cout << "Do you want to play again? (y/n) ";
	std::string Response = "";
	std::getline(std::cin, Response);
	return (Response[0] == 'y' || Response[0] == 'Y');
}
