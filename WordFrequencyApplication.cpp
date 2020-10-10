#include "WordFrequencyApplication.h"

WordFrequencyApplication::WordFrequencyApplication(EventManager& em) :_em(em) {
	_em.subscribe("run", [this](std::string const& str) { return this->run(str); });
	_em.subscribe("stop", [this](std::string const& str) { return this->stop(); });
};
void WordFrequencyApplication::run(std::string path) {
	
	_em.publish("load", path);
	_em.publish("start","");
}
void WordFrequencyApplication::stop() {
	_em.publish("print","");
}
