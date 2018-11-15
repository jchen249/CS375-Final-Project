#include "Hash.h"
#include <vector>
#include <utility>
#include <iostream>
#include <string>
#include <ostream>
#include <typeinfo>
using namespace std;

Hash::Hash(unsigned int size){
	//vector<pair<string, string> > hash(size);
	hash.reserve(size);
	pair<string, string> obj = make_pair("","");
	for(int i =0; i < this->size(); i++){
		cerr<< i << endl;
		hash.push_back(obj);
		//cerr<<hash[i].first<<endl;
	}
	//cerr << hash[2] << endl;
	this->count = 0;

};
bool Hash::insert(string key, string value){
	pair<string, string> obj = make_pair(key,value);
	//cout << "hi" << endl;
	int index = hasher(key);
	if(count < size()){
		//cerr<< hasher(key)<< endl;
		//cerr <<get<0>(hash.at(index)) << endl;
		while (hash[index].first != ""){	
		// 	cerr <<"hi"<< endl;
			index++;
		 	//index= (index+1) % size()-1;
		 	cerr<<index<< endl;	
		 }
		cerr<<"inserted"<<endl;
		hash.at(index) = obj;
		count++;
	}else{
		return false;

	}
	return true;
};
bool Hash::remove(string key){
	int inc=0;
	int c=0;
	for(auto i = hash.begin(); i<hash.end();i++){
		if(hash[c].first == ""){
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

string Hash::find(string key){
	for(int i=0; i<(signed int)hash.size(); i++){
		if(get<0>(hash.at(i)) == key){
			return get<1>(hash.at(i));
		}
	}
	return "";

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
int Hash::hasher(string key){
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
