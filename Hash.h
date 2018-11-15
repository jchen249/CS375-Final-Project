#ifndef HASH_H
#define HASH_H
#include <vector>
#include <utility>
#include <string>
using namespace std;
class Hash{
	vector<pair<string, string> > hash;
	int count;
public:
	Hash(unsigned int size);
	bool insert(string key, string value);
	bool remove(string key);
	string find(string key);
	bool empty();
	int size();
	void printHash();
	int hasher(string key);


};
#endif