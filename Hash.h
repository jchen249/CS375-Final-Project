#ifndef HASH_H
#define HASH_H
#include <vector>
#include <utility>
#include <string>
using namespace std;
class Hash{
	vector<pair<int, int> > hash;
	int count;
	int collison;
public:
	Hash(unsigned int size);
	bool insert(int key, int value, int hashType);
	bool remove(int key);
	int find(int key);
	bool empty();
	int size();
	void printHash();
	int hasher(int key);
	int linearProbing(int key);
	int quadraticProbing(int Key);
	int doubleHashing(int key);


};
#endif