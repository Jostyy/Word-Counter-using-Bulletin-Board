#include "EventManager.h"


void EventManager::subscribe(std::string const& event_type, ScriptFunction handler) {
	subscriptions[event_type].push_back(handler);
}


void EventManager::publish(std::string event, std::string data) {
	auto it = this->subscriptions.find(event);
	for (auto func : it->second) {
		func(data);
	}
}

void EventManager::publish(std::string event) {
	auto it = this->subscriptions.find(event);
	for (auto func : it->second) {
		func("");
	}
}