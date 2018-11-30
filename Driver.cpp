#include "Hash.h"
#include <stdlib.h>
#include <iostream>
#include <set>
#include <algorithm>
#include <fstream>
//using namespace std;

int findNonUnq(vector<int> v){
	return v.size()- ( set<int>(v.begin(), v.end()).size() );
}
int main(int argc, char **argv)
{
	srand(time(NULL));
	
	//load factor = >75%
	ofstream myfile;
	myfile.open("data.csv", ios::out | ios::app);
	std::cout << "********* TABLE SIZE 29 *********" << std::endl;
	std::cout << "----------- load factor >75% -----------" << std::endl;
	
	Hash h1 = Hash(29);
	Hash h2 = Hash(29);
	Hash h3 = Hash(29);
	std::vector<int> v1;
	for(int i=0; i<23; i++)
	{
		int r = rand() % 300 + 1;
		v1.push_back(r);
		//std::cout << r << std::endl;
	}	
	for(unsigned int i=0; i<v1.size(); i++)
	{
		h1.insert(v1[i], 0);
		h2.insert(v1[i], 1);
		h3.insert(v1[i], 2, 23);
	}
	auto minmax= std::minmax_element(v1.begin(), v1.end());
	std::cout << "Range: " << *minmax.second - *minmax.first << std::endl;
	std::cout << "Number of non unqiue int : " << findNonUnq(v1) << std::endl;
	std::cout << "linear probing # of collisions: " << h1.getCollision() << std::endl;
	std::cout << "quadratic probing # of collisions: " << h2.getCollision() << std::endl;
	std::cout << "double hashing # of collisions: " << h3.getCollision() << std::endl;
	
	//load factor = 50-75%
	std::cout << "----------- load factor 50-75% -----------" << std::endl;
	
	Hash h4 = Hash(29);
	Hash h5 = Hash(29);
	Hash h6 = Hash(29);
	std::vector<int> v2;
	int r2;
	for(int i=0; i<18; i++)
	{
		r2 = rand() % 300 + 1;
		v2.push_back(r2);
		//std::cout << r2 << std::endl;
	}
	for(unsigned int i=0; i<v2.size(); i++)
	{
		h4.insert(v2[i], 0);
		h5.insert(v2[i], 1);
		h6.insert(v2[i], 2, 23);
	}
	minmax= std::minmax_element(v2.begin(), v2.end());
	std::cout << "Range: " << *minmax.second - *minmax.first << std::endl;
	std::cout << "Number of non unqiue int : " << findNonUnq(v2) << std::endl;
	std::cout << "linear probing # of collisions: " << h4.getCollision() << std::endl;
	std::cout << "quadratic probing # of collisions: " << h5.getCollision() << std::endl;
	std::cout << "double hashing # of collisions: " << h6.getCollision() << std::endl;
	
	//load factor = <50%
	std::cout << "----------- load factor <50% -----------" << std::endl;
	Hash h7 = Hash(29);
	Hash h8 = Hash(29);
	Hash h9 = Hash(29);
	std::vector<int> v3;
	int r3;
	for(int i=0; i<12; i++)
	{
		r3 = rand() % 300 + 1;
		v3.push_back(r3);
		//std::cout << r3 << std::endl;
	}
	for(unsigned int i=0; i<v3.size(); i++)
	{
		h7.insert(v3[i], 0);
		h8.insert(v3[i], 1);
		h9.insert(v3[i], 2, 23);
	}
	minmax= std::minmax_element(v3.begin(), v3.end());
	std::cout << "Range: " << *minmax.second - *minmax.first << std::endl;
	std::cout << "Number of non unqiue int : " << findNonUnq(v3) << std::endl;
	std::cout << "linear probing # of collisions: " << h7.getCollision() << std::endl;
	std::cout << "quadratic probing # of collisions: " << h8.getCollision() << std::endl;
	std::cout << "double hashing # of collisions: " << h9.getCollision() << std::endl;


	std::cout << "\n********* TABLE SIZE 11 *********" << std::endl;
	std::vector<Hash> linearHash(3, Hash(11));
	std::vector<Hash> quadraticHash(3, Hash(11));
	std::vector<Hash> doubleHash(3, Hash(11));
	std::vector< vector<int> > randomNum(3);
	int j = 9; // make randomNum[i][j] of size 8 6 4 for different load factors
	for(int i = 0; i<3; i++){
			for(int k = 0; k<j; k++){
				//std::cout << j << std::endl;
				randomNum[i].push_back(rand() % 100 + 1);
				linearHash[i].insert(randomNum[i][k],0);
				quadraticHash[i].insert(randomNum[i][k],1);
				doubleHash[i].insert(randomNum[i][k],2,7);
			}
			minmax= std::minmax_element(randomNum[i].begin(), randomNum[i].end());
			std::cout << "----------- load factor " << (j/11.0)*100 << "% -----------" << std::endl;
			std::cout << "Range: " << *minmax.second - *minmax.first << std::endl;
			std::cout << "Number of non unqiue int : " << findNonUnq(randomNum[i]) << std::endl;
			std::cout << "linear probing # of collisions: " << linearHash[i].getCollision() << std::endl;
			//linearHash[i].printHash();
			std::cout << "quadratic probing # of collisions: " << quadraticHash[i].getCollision() << std::endl;
			//quadraticHash[i].printHash();
			std::cout << "double hashing # of collisions: " << doubleHash[i].getCollision() << std::endl;
			//doubleHash[i].printHash();
		j-=2;
	}
 
	std::cout << "\n********* TABLE SIZE 101 *********" << std::endl;
	std::vector<Hash> linearHash1(3, Hash(101));
	std::vector<Hash> quadraticHash1(3, Hash(101));
	std::vector<Hash> doubleHash1(3, Hash(101));
	std::vector< vector<int> > randomNum1(3);
	int j1 = 80; // make randomNum[i][j] of size 8 make6 4 for different load factors
	for(int i = 0; i<3; i++){
			for(int k = 0; k<j1; k++){
				randomNum1[i].push_back(rand() % 1000 + 1);
				linearHash1[i].insert(randomNum1[i][k],0);
				quadraticHash1[i].insert(randomNum1[i][k],1);
				doubleHash1[i].insert(randomNum1[i][k],2,97);
			}
			minmax= std::minmax_element(randomNum1[i].begin(), randomNum1[i].end());
			std::cout << "----------- load factor " << (j1/101.0)*100 << "% -----------" << std::endl;
			std::cout << "Range: " << *minmax.second - *minmax.first << std::endl;
			std::cout << "Number of non unqiue int : " << findNonUnq(randomNum1[i]) << std::endl;
			std::cout << "linear probing # of collisions: " << linearHash1[i].getCollision() << std::endl;
			std::cout << "quadratic probing # of collisions: " << quadraticHash1[i].getCollision() << std::endl;
			std::cout << "double hashing # of collisions: " << doubleHash1[i].getCollision() << std::endl;
		j1-=20;
	}
	myfile << h1.getCollision() << ", " << h2.getCollision() << ", " << h3.getCollision()<<", "
		<< h4.getCollision() << ", " << h5.getCollision() << ", " << h6.getCollision()<<", "
		<< h7.getCollision() << ", " << h8.getCollision() << ", " << h9.getCollision();
	for(int i =0; i<3; i++){
		myfile <<", " << linearHash[i].getCollision() << ", " << quadraticHash[i].getCollision() <<", " << doubleHash[i].getCollision();
	}
	for(int i =0; i<3; i++){
		
		myfile <<", " << linearHash1[i].getCollision() << ", " << quadraticHash1[i].getCollision() <<", " << doubleHash1[i].getCollision();
	}
	myfile << endl;
	myfile.close();

	//print demo slides
	std::cout << "Linear Probing: h(k)= (k+i) %" << " size" <<  std::endl;
	std::cout << "Keys inserted " << randomNum[1].size() << " : { " << randomNum[1][0];
	for(int i = 1 ; i < randomNum[1].size(); i++){
		std::cout <<", " << randomNum[1][i];
	}
	std::cout << "}" << std::endl;
	linearHash[1].printHash();
	std::cout << "linear probing # of collisions: " << linearHash[1].getCollision() << std::endl;

	std::cout << "Quadratic Probing: h(k)= (k+(i^2)) %" << " size" << std::endl;
	std::cout << "Keys inserted " << randomNum[1].size() << " : { " << randomNum[1][0];
	for(int i = 1 ; i < randomNum[1].size(); i++){
		std::cout <<", " << randomNum[1][i];
	}
	std::cout << "}" << std::endl;
	quadraticHash[1].printHash();
	std::cout << "Quadratic probing # of collisions: " << quadraticHash[1].getCollision() << std::endl;

	std::cout << "Double Probing: h(k)= k % (h2*i) %" << " size. where h2(k) = 7 - (k % 7)" << std::endl;
	std::cout << "Keys inserted " << randomNum[1].size() << " : { " << randomNum[1][0];
	for(int i = 1 ; i < randomNum[1].size(); i++){
		std::cout <<", " << randomNum[1][i];
	}
	std::cout << "}" << std::endl;
	doubleHash[1].printHash();
	std::cout << "Double probing # of collisions: " << doubleHash[1].getCollision() << std::endl;


	
	return 0;
}
