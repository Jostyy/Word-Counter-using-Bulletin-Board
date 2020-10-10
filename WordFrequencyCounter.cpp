#include "WordFrequencyCounter.h"


WordFrequencyCounter::WordFrequencyCounter(EventManager& em) :_em(em) {
	_em.subscribe("valid_word", [this](std::string const& str) { return this->increment_count(str); });
	_em.subscribe("print", [this](std::string const& str) { return this->print_freqs(); });
};
void WordFrequencyCounter::increment_count(std::string word) {
	word_freqs[word]++;
}

template<typename K, typename V>
std::multimap<V, K> invertMap(std::map<K, V> const& map)
{
	std::multimap<V, K> multimap;

	for (auto const& pair : map) {
		multimap.insert(std::make_pair(pair.second, pair.first));
	}

	return multimap;
}

void WordFrequencyCounter::print_freqs() {
	
	std::multimap<int, std::string> multimap = invertMap(word_freqs);

	for (auto const& pair : multimap) {
		std::cout <<  pair.second << " - " << pair.first << '\n';
	}
}