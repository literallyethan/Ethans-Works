#include <iostream>
#include <string>
#include "word_generator.hpp"

using namespace std;

int main(int argc, char* argv[]) {
	WordGenerator gen;
	string input_word = gen.random_word();
	string censor;
	char guess;
	short lives = 3;


	cout << "Alright, lets begin the game." << endl;

	for(char letter : input_word) {
		censor.push_back('_');
	}

	
	while(true) {
		bool found = false;

		cout << censor << endl;
		cout << "Make a guess." << endl;
		cout << "Lives: " << lives << endl;

		cin >> guess;

		for(int i = 0; i < input_word.length(); i++) {
			if(input_word[i] == guess) {
				censor[i] = guess;
				found = true;
			}
		}

		if(!found) {
			cout << "[EXTREMELY LOUD INCORRECT BUZZER]" << endl;
			--lives;
		}

		if(lives == 0) {
			cout << "YOU LOSE!!" << endl;

			return 0;
		}
		
	}


	return 0;
}
