#ifndef EventManager_h
#define EventManager_h
#include "boost/any.hpp"
#include <unordered_map>
#include <vector>
#include <functional>
#include <iostream>


using ScriptFunction = std::function<void(std::string const&)>;
using Script_map = std::unordered_map<std::string, std::vector<ScriptFunction>>;

class EventManager
{
public:

	Script_map subscriptions;
	void subscribe(std::string const& event_type, ScriptFunction handler);
	void publish(std::string, std::string);
	void publish(std::string);

};

#endif