#ifndef WordFrequencyApplication_h
#define WordFrequencyApplication_h
#include "EventManager.h"

class WordFrequencyApplication
{
	EventManager& _em;
public:
	WordFrequencyApplication(EventManager& em);
	void run(std::string);
	void stop();
};
#endif
