//	--- Day 1: Trebuchet?! ---
//	Something is wrong with global snow production, and you've been selected to take a look.
//	The Elves have even given you a map; on it, they've used stars to mark the top fifty locations that are likely to be having problems.
//	
//	You've been doing this long enough to know that to restore snow operations, you need to check all fifty stars by December 25th.
//	
//	Collect stars by solving puzzles. Two puzzles will be made available on each day in the Advent calendar; the second puzzle is unlocked when you complete the first.
//	Each puzzle grants one star. Good luck!
//	
//	You try to ask why they can't just use a weather machine ("not powerful enough") and where they're even sending you ("the sky") and
//	why your map looks mostly blank ("you sure ask a lot of questions") and hang on did you just say the sky ("of course, where do you think snow comes from") when
//	you realize that the Elves are already loading you into a trebuchet ("please hold still, we need to strap you in").
//	
//	As they're making the final adjustments, they discover that their calibration document (your puzzle input) has been amended by a very young Elf who was apparently just excited to
//  show off her art skills. Consequently, the Elves are having trouble reading the values on the document.
//	
//	The newly-improved calibration document consists of lines of text; each line originally contained a specific calibration value that the Elves now need to recover.
//	On each line, the calibration value can be found by combining the first digit and the last digit (in that order) to form a single two-digit number.
//	
//	For example:
//	
//	1abc2
//	pqr3stu8vwx
//	a1b2c3d4e5f
//	treb7uchet
// 
//	In this example, the calibration values of these four lines are 12, 38, 15, and 77. Adding these together produces 142.
//	
//	Consider your entire calibration document. What is the sum of all of the calibration values?

#include <fstream>
#include <iostream>
#include <unordered_map>
#include <string>

void Part1();
void Part2();

int main(int argc, char* argv[])
{
	Part1();
	Part2(); // Not correct result.
}

////////////////////////////////////////////////////

void Part1()
{
	// Read file
	std::ifstream file("sample.txt");
	if (!file)
		return;

	// Parse lines
	std::vector<uint32_t> numsPerLine;
	std::string line;
	for (uint32_t i = 0; std::getline(file, line); i++)
	{
		std::vector<uint32_t> numbers;
		for (uint32_t j = 0; j < line.size(); j++)
		{
			if (isdigit(line.c_str()[j]))
				numbers.push_back(line.c_str()[j] - 48);
		}

		std::string numberA = std::to_string(numbers.at(0));
		std::string numberB = std::to_string(numbers.at(numbers.size() - 1));
		std::string combinedNumber = numberA + numberB;

		numsPerLine.push_back(atoi(combinedNumber.c_str()));
	}

	uint32_t sum = 0;
	for (uint32_t number : numsPerLine)
		sum += number;

	std::cout << sum << std::endl;
}

void Part2()
{
	// Read file
	std::ifstream file("sample.txt");
	if (!file)
		return;

	// Numbers but then words
	std::vector<std::string> numberWords = { "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };
	std::vector<uint32_t> numsPerLine;
	std::string line;

	// Parse lines
	for (uint32_t i = 0; std::getline(file, line); i++)
	{
		std::vector<uint32_t> numbers;

		// For each character in the line
		for (uint32_t j = 0; j < line.size(); j++)
		{
			// If it is a digit, save it
			if (isdigit(line.c_str()[j]))
				numbers.push_back(line.c_str()[j] - 48);
			// If it is a word starting at exactly that character position, save it
			else
			{
				for (uint32_t i = 0; i < numberWords.size(); i++)
				{
					if (line.find(numberWords[i]) == j)
						numbers.push_back(i + 1);
				}
			}
		}

		// Combine first and last number
		std::string numberA = std::to_string(numbers[0]);
		std::string numberB = std::to_string(numbers[numbers.size() - 1]);
		std::string combinedNumber = numberA + numberB;

		numsPerLine.push_back(atoi(combinedNumber.c_str()));
	}

	// Calculate the sum of the combined number from each line
	uint32_t sum = 0;
	for (uint32_t number : numsPerLine)
		sum += number;

	std::cout << sum << std::endl;
}