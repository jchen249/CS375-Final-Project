#include "Hash.h"
#include <vector>
#include <utility>
#include <iostream>
#include <string>
#include <ostream>
#include <typeinfo>
using namespace std;

Hash::Hash(unsigned int size){
	//vector<pair<int, int> > hash(size);
	hash.reserve(size);
	int obj = -1;
	for(int i =0; i < this->size(); i++){
		//cerr<< i << endl;
		hash.push_back(obj);
		//cerr<<hash[i].first<<endl;
	}
	//cerr << hash[2] << endl;
	this->count = 0;
	this->collision = 0;

};
bool Hash::insert(int key, int hashType, int prime){
	int obj = key;
	//cout << "hi" << endl;
	int index = -1;
	if(count < size()){
		if(hashType == 0) // linearProbing
		{
			index = linearProbing(key);
		}
		else if(hashType == 1) 	// quadraticProbing
		{
			index = quadraticProbing(key);
		}
		else if(hashType == 2) // doubleHashing
		{
			index = doubleHashing(key, prime);
		}
		else
		{
			cerr<<"invalid hash type (must be 0, 1 or 2)"<<endl;
		}
		//move to individual hashTypes
		// while (hash[index].first != -1){	
		// 	index++;

		//  }
		//cerr<<"inserted"<<endl;
		hash.at(index) = obj;
		count++;
	}else{
		return false;

	}
	return true;
};
bool Hash::remove(int key){
	int inc=0;
	int c=0;
	for(auto i = hash.begin(); i<hash.end();i++){
		if(hash[c] == -1){
			hash.erase(i);
		}
		c++;
	}
	for(auto i=hash.begin(); i<hash.end(); i++){
		if((hash[inc]) == key){
			hash.erase(i);
			return true;
		}
		inc++;
	}
	return false;
};

int Hash::find(int key){
	for(int i=0; i<(signed int)hash.size(); i++){
		if((hash.at(i)) == key){
			return hash.at(i);
		}
	}
	return -1;

};
bool Hash::empty(){
	return hash.empty();
};
int Hash::size(){
	return (hash.capacity());
};
void Hash::printHash(){
	for(int i=0; i<size(); i++){
		cout<<"Index:" << i <<"\t Key:"<< hash.at(i) <<endl;
	}
};

int Hash::linearProbing(int key){
	int index = key % (size()-1);
	while(hash.at(index) != -1){
		index++;
		index %= (size()-1);
		collision++;
	}
	return index;
};

int Hash::quadraticProbing(int key){
	int index = key % (size()-1);
	int i = 0;
	while(hash.at(index) != -1 && i < (size()-1)){
		index = (index + (7*i) + (3*i^2)) % (size()-1);
		collision++;
		i++;
	}
	return index;
};

int Hash::doubleHashing(int key, int prime){
	/*code*/
	//cout << prime << endl;
	int i = 0;
	int hash1 = key%(size()-1);
	int hash2 = prime - (key % prime);
	//int hash2 = 1 + ((key/size()-1) %size()-1-1);
	int index = hash1;
	while(hash.at(index) != -1 && i < (size()-1)){
		
		collision++;
		index = ((index + hash2) % (size()-1));
		//cout << index << endl;
		i ++;
	}
	return index;
};

int Hash::getCollision(){
	return this->collision;
};
