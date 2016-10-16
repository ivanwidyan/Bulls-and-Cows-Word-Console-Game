#include <iostream>
#include <string>

void PrintIntro();
void PlayGame();
std::string GetGuess();
bool AskToPlayAgain();

//The entry point for our application
int main() {
	bool bPlayAgain = false;
	do {
		PrintIntro();
		PlayGame();
		bPlayAgain = AskToPlayAgain();
	} while (bPlayAgain);
	return 0; //Exit the applicationasds
}

void PrintIntro() {
	constexpr int WORLD_LENGTH = 9;
	std::cout << "Welcome to out Bulls and Cows Word Console Game" << std::endl;
	std::cout << "Can you guess the" << WORLD_LENGTH << "letter isogram I'm thinking of?" << std::endl;
	return;
}

void PlayGame()
{
	// loop for the number of turns asking for guesses
	constexpr int NUMBER_OF_TURNS = 5;
	for (int count = 1; count <= 5; count++) {
		std::string Guess = GetGuess();
		std::cout << "Your guess was: " << Guess << std::endl;
		std::cout << std::endl;
	}
}

std::string GetGuess() {
	// Get a Guess from the Player
	std::cout << "Enter your guess: ";
	std::string Guess = "";
	std::getline(std::cin, Guess);
	return Guess;
}

bool AskToPlayAgain() {
	std::cout << "Do you want to play again (y/n)? ";
	std::string Response = "";
	std::getline(std::cin, Response);
	return (Response[0] == 'y') || (Response[0] == 'Y');
}