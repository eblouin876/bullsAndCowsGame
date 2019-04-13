/* 
This is the console executable that makes use of the BullCow Class.
This is the console executable that makes use of the BullCow Class.
This acts as the view in a MVC pattern and is responsible for all
user interaction. For game logic, see the FBullCowGame class.
*/

#include <iostream>
#include <string>
#include "FBullCowGame.h"

// making syntax Unreal friendly
using FText = std::string; // FText is typcially used for user interaction
using int32 = int;

// prototypes outside class
void PrintIntro();
void PlayGame();
void PrintGameSummary();
FText GetValidGuess();
bool AskToPlayAgain();
void ChooseDifficulty();

FBullCowGame BCGame; // Instantiate a new game


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

void PrintIntro()
{
	std::cout << "\n\nWelcome to Bulls and Cows, a fun word game.\n";
	std::cout << "	                               /;    ;\\ \n";
	std::cout << "                                   __  \\\\____//   \n";
	std::cout << "                                  /{_\\_/   `'\\____ \n";
	std::cout << "                                  \\___   (o)  (o  } \n";
	std::cout << "       _____________________________/          :--'  \n";
	std::cout << "   ,-,'`@@@@@@@@       @@@@@@         \\_    `__\\     \n";
	std::cout << "  ;:(  @@@@@@@@@        @@@             \\___(o'o)    \n";
	std::cout << "  :: )  @@@@          @@@@@@        ,'@@(  `===='     \n";
	std::cout << "  :: : @@@@@:          @@@@         `@@@:				\n";
	std::cout << "  :: \\  @@@@@:       @@@@@@@)    (  '@@@' \n";
	std::cout << "  ;; /\\      /`,    @@@@@@@@@\\   :@@@@@) \n";
	std::cout << "  ::/  )    {_----------------:  :~`,~~; \n";
	std::cout << " ;;'`; :   )                  :  / `; ; \n";
	std::cout << ";;;; : :   ;                  :  ;  ; :        \n";
	std::cout << "`'`' / :  :                   :  :  : : \n";
	std::cout << "    )_ \\__;                   :_ ;  \\_\\       \n";
	std::cout << "    :__\\  \\                   \\  \\  :  \\    \n";
	std::cout << "        `^'                    `^'  `-^-'     \n";
	ChooseDifficulty();
	std::cout << "Can you guess the " << BCGame.GetHiddenWordLength();
	std::cout << " letter isogram I'm thinking of?\n";
	std::cout << std::endl;
	return;
}

// Primary function that handles gameplay
void PlayGame()
{
	BCGame.Reset();
	int32 MaxTries = BCGame.GetMaxTries();

	// loop asking for guesses while the game is NOT won
	// and there are still tries remaining
	while(!BCGame.IsGameWon() && BCGame.GetCurrentTry() <= MaxTries) { 
		FText Guess = GetValidGuess();

		// Submit valid guess to BCGame and receive counts
		FBullCowCount BullCowCount = BCGame.SubmitValidGuess(Guess);

		std::cout << "Bulls = " << BullCowCount.Bulls; 
		std::cout << ", Cows = " << BullCowCount.Cows << "\n\n";
	}

	PrintGameSummary();

	return;
}

// Prints out win/loss condition to player
void PrintGameSummary()
{
	if (BCGame.IsGameWon()) {
		std::cout << "Congratulations! You guessed the word!";
	}
	else {
		std::cout << "Sorry, better luck next time!";
	}
	std::cout << std::endl;
}

// Loop continually until the user gives a valid guess
FText GetValidGuess() 
{		
	FText Guess = "";
	EGuessStatus Status = EGuessStatus::Invalid_Status;
	do {
		int32 CurrentGuess = BCGame.GetCurrentTry();
		std::cout << "Try " << CurrentGuess << " of " << BCGame.GetMaxTries() << ". Enter your guess: ";
		std::getline(std::cin, Guess);


		Status = BCGame.CheckGuessValidity(Guess);

		switch (Status)
		{
		case EGuessStatus::Not_Isogram:
			std::cout << "Please enter a word without repeating letters.\n\n";
			break;
		case EGuessStatus::Wrong_Length:
			std::cout << "Please enter a " << BCGame.GetHiddenWordLength() << " letter word.\n\n";
			break;
		case EGuessStatus::Not_Lowercase:
			std::cout << "Please enter a word that is all lowercase.\n\n";
			break;
		default:
			// Assume valid
			break;
		}
	} while (Status != EGuessStatus::OK); // Keep looping until there are no errors
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

// Allows the player to select difficulty between 1 and 5
void ChooseDifficulty() 
{
	std::cout << "Please select a difficulty between 1 and 5. ";
	FText Response = "";
	std::getline(std::cin, Response);
	if (Response == "1") { BCGame.SelectDifficulty("1"); }
	else if (Response == "2") { BCGame.SelectDifficulty("2"); }
	else if (Response == "3") { BCGame.SelectDifficulty("3"); }
	else if (Response == "4") { BCGame.SelectDifficulty("4"); }
	else if (Response == "5") { BCGame.SelectDifficulty("5"); }
	else { ChooseDifficulty(); }
}