#include "StopWordFilter.h"

StopWordFilter::StopWordFilter(EventManager& em) :_em(em) {
	_em.subscribe("load", [this](std::string const& str) { return this->load(); });
	_em.subscribe("word", [this](std::string const& str) { return this->is_stop_word(str); });

};

void StopWordFilter::load() {
	std::ifstream file("stopwords.txt", std::ios::binary | std::ios::ate);
	if (file.fail()) {
		perror("File not Found!");
		exit(EXIT_FAILURE);
	}

	std::streamsize size = file.tellg();
	file.seekg(0, std::ios::beg);

	std::vector<char> buffer(size);
	file.read(buffer.data(), size);

	std::string str(buffer.begin(), buffer.end());
	std::for_each(str.begin(), str.end(), [](char& c) {
		c = ::tolower(c);
		});

	std::stringstream ss(str);
	std::istream_iterator<std::string> begin(ss);
	std::istream_iterator<std::string> end;
	std::vector<std::string> vstrings(begin, end);

	this->sw = vstrings;
}
void StopWordFilter::is_stop_word(std::string word) {
	if (std::find(sw.begin(), sw.end(), word) == sw.end())
		_em.publish("valid_word", word);
}