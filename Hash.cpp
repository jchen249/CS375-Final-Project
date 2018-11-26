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
	pair<int, int> obj = make_pair(-1,-1);
	for(int i =0; i < this->size(); i++){
		cerr<< i << endl;
		hash.push_back(obj);
		//cerr<<hash[i].first<<endl;
	}
	//cerr << hash[2] << endl;
	this->count = 0;
	this->collison = 0;

};
bool Hash::insert(int key, int value, int hashType){
	pair<int, int> obj = make_pair(key,value);
	//cout << "hi" << endl;
	int index = -1;
	if(hashType == 0)
		index = linearProbing(key,);

	if(count < size()){
		//move to individual hashTypes
		// while (hash[index].first != -1){	
		// 	index++;

		//  }
		cerr<<"inserted"<<endl;
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
		if(hash[c].first == -1){
			hash.erase(i);
		}
		c++;
	}
	for(auto i=hash.begin(); i<hash.end(); i++){
		if(get<0>(hash[inc]) == key){
			hash.erase(i);
			return true;
		}
		inc++;
	}
	return false;
};

int Hash::find(int key){
	for(int i=0; i<(signed int)hash.size(); i++){
		if(get<0>(hash.at(i)) == key){
			return get<1>(hash.at(i));
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
		cout<<"Index:" << i <<"\t Key:"<< get<0>(hash.at(i)) << "\t Value:" << find(get<0>(hash.at(i))) <<endl;
	}
};
int Hash::hasher(int key){
	int index;
	int siz = key.length()-1;
	index = siz % (size()-1);
	//cerr<< index << endl;
	//cerr<< (hash.at(index)) << endl;
	// int i=0;
	// while(get<1>(hash[index]) != ""){
	// 	cerr<<"HI" << endl;
	// 	//index++;
	// 	i++;
	// 	index = siz+i % (size()-1);
	// }
	//cerr<< index << endl;
	return index;
	

};
int Hash::linearProbing(int key){
	/*CODE*/
};
int Hash::quadraticProbing(int key){
	/*code*/
};
int Hash::doubleHashing(int key){
	/*code*/
	int hash1 = key%size()-1;
	int hash2 = (key*(2/3)) % size()-1;
	int index = hash1 + hash2;
	while(hash[index].first != -1){
		collison++;
		index += hash2;
	}
	return index;
	

};