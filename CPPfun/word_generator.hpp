#pragma once
#include <vector>
#include <string>
#include <random>

using namespace std;

class WordGenerator {
	random_device random;
	vector<string> words = {"hello", "world", "comment", "poster", "college"};

public:
	string random_word() {
		mt19937 gen(random()); //seed
		uniform_int_distribution<> distr(0, words.size() - 1);
		
		return words[distr(gen)];
	}

};
