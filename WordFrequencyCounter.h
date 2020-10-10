#ifndef WordFrequencyCounter_h
#define WordFrequencyCounter_h
#include "EventManager.h"
#include <map>
#include <iostream>
#include <set>
#include <algorithm>

class WordFrequencyCounter
{
	std::map<std::string, int> word_freqs;
public:
	EventManager& _em;

	WordFrequencyCounter(EventManager& em);
	void increment_count(std::string);
	void print_freqs();
};
#endif
