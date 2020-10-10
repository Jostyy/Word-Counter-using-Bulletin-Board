#ifndef StopWordFilter_h
#define StopWordFilter_h
#include "EventManager.h"
#include <fstream>
#include <algorithm>
#include <sstream>
#include <istream>
#include <iterator>

class StopWordFilter
{
	std::vector<std::string> sw;
	
public:
	EventManager& _em;

	StopWordFilter(EventManager &em);
	void load();
	void is_stop_word(std::string);
};
#endif
