#include "DataStorage.h"

DataStorage::DataStorage(EventManager& em) : _em(em) {
	_em.subscribe("load", [this](std::string const& str) { return this->load(str); });
	_em.subscribe("start",[this](std::string const& str) { return this->produce_words(); });
};

void DataStorage::load(std::string fname) {
	
	std::ifstream file(fname, std::ios::binary | std::ios::ate);
	if (file.fail()) {
		perror("File not Found!");
		exit(EXIT_FAILURE);
	}

	std::streamsize size = file.tellg();
	file.seekg(0, std::ios::beg);

	std::vector<char> buffer(size);
	file.read(buffer.data(), size);

	std::string aux(buffer.begin(), buffer.end());

	std::string str;
	str.reserve(aux.size());
	for (int i = 0; i < aux.size();i++) {
		if (aux[i] != ';' && aux[i] != ':' && aux[i] != '(' && aux[i] != ')' && aux[i] != '.' && aux[i] != ',' && aux[i] != '.' && aux[i] != '?' && aux[i] != '!' && aux[i] != '\"')
			str += tolower(aux[i]);
	}

	std::stringstream ss(str);
	std::istream_iterator<std::string> begin(ss);
	std::istream_iterator<std::string> end;
	std::vector<std::string> vstrings(begin, end);

	this->data = vstrings;
	
}

void DataStorage::produce_words() {
	for (auto it : this->data) {
		_em.publish("word",it);
	}
}
