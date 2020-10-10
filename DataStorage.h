#ifndef DataStorage_h
#define DataStorage_h
#include "EventManager.h"
#include <fstream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <istream>
#include <iterator>

class DataStorage
{
	std::vector<std::string> data;
	EventManager& _em;
public:


	DataStorage(EventManager& em);
	void load(std::string);
	void produce_words();
	

};
#endif
