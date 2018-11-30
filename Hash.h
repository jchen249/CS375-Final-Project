#ifndef HASH_H
#define HASH_H
#include <vector>
#include <utility>
#include <string>
using namespace std;
class Hash{
	vector<int> hash;
	int count;
	int collision;
public:
	Hash(unsigned int size);
	bool insert(int key, int hashType, int prime = 2);
	bool remove(int key);
	int find(int key);
	bool empty();
	int size();
	void printHash();
	int linearProbing(int key);
	int quadraticProbing(int Key);
	int doubleHashing(int key, int prime);
	int getCollision();

};
#endif
