#pragma once

#include "FBullCowGame.h"
#include <map>

FBullCowGame::FBullCowGame()
{
	Reset();
}

int FBullCowGame::GetMaxTries () const {
	std::map<int, int> WordLengthToMaxTries{
		{3,4},{4,7},{5,10},{6,16},{7,20}
	};
	return WordLengthToMaxTries[MyHiddenWord.length()];
}

int FBullCowGame::GetCurrentTry() const {return MyCurrentTry;}
int FBullCowGame::GetHiddenWordLength() const{return MyHiddenWord.length();}
bool FBullCowGame::IsGameWon() const { return bGameIsWon;}

void FBullCowGame::Reset()
{
	const std::string HIDDEN_WORD = "donkey"; // this MUST be an isogram
	MyHiddenWord = HIDDEN_WORD;

	MyCurrentTry = 1;
	bGameIsWon = false;
	return;
}

// received a VALID guess, increments
FBullCowCount FBullCowGame::SubmitValidGuess(std::string Guess)
{
	// incriment the turn number
	MyCurrentTry++;

	// setup a return variable
	FBullCowCount BullCowCount;
	int WordLength = MyHiddenWord.length(); // assuming same length as guess

	// loop through all leters in the hidden word
	for (int MHWChar = 0; MHWChar < WordLength; MHWChar++) {
		// compare letters against the guess
		for (int GChar = 0; GChar < WordLength; GChar++) {
			// if they match then
			if (Guess[GChar] == MyHiddenWord[MHWChar]) {
				// if they're in the same place
				if (MHWChar == GChar) {
					BullCowCount.Bulls++; // Incriment bulls
				}
				else {
					BullCowCount.Cows++; // Must be a cow
				}
			}
		}
	}
	if (BullCowCount.Bulls == WordLength) {
		bGameIsWon = true;
	}
	else {
		bGameIsWon = false;
	}
	return BullCowCount;
}

bool FBullCowGame::IsIsogram(std::string Word) const
{
	// treat 0 and 1 letter words as isograms
	if (Word.length() <= 1) { return true;}
	std::map<char, bool> LetterSeen; // setup our map	
	for (auto Letter : Word) { // for all letters of the word
		Letter = tolower(Letter); // handle mixed case
		if (LetterSeen[Letter]) { // if the letter is in the map
			return false; // we do NOT have an isogram
		}
		else {
			LetterSeen[Letter] = true;
			// add letter to the map as seen
		}		
	}	

	return true; // for example in cases where /0 is entered
}

bool FBullCowGame::IsLowecrase(std::string Word) const
{
	for (auto Letter : Word) { 
		if (!islower(Letter)) { // if not a lowercase letter
			return false;
		}
	}
	return true;
}

EGuessStatus FBullCowGame::CheckGuessValidity(std::string Guess) const
{
	if (!IsIsogram(Guess)) // if the guest isn't an isogram 
	{
		return EGuessStatus::Not_Isogram;
	}
	else if (!IsLowecrase(Guess)) // if the guest isn't all lowercase
	{
		return EGuessStatus::Not_Lowercase;
	}
	else if (Guess.length() != GetHiddenWordLength()) // if the guest length is wrong
	{
		return EGuessStatus::Wrong_Length;
	}
	else
	{
		return EGuessStatus::OK;
	}
}
