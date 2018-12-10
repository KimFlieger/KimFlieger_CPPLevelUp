#pragma once

#include <string>
#include <iostream>

class GuessingGame
{
public:
	void PlayGame();
	bool CheckGuess(const std::string& guess, const std::string& answer);
	bool Guess(const std::string& answer);

private:
	const std::string mAnswer = "games";
	const unsigned int mGuessesNum = 2;
	unsigned int mCorrectWords = 0;
	unsigned int mCorrectWordsInWrongSpot = 0;
	bool mIsCorrect = false;
};