#include "Hash.h"
#include <stdlib.h>
#include <iostream>

int main(int argc, char **argv)
{
	//srand(time(null));
	
	//load factor = >75%
	
	Hash h1 = Hash(29);
	Hash h2 = Hash(29);
	Hash h3 = Hash(29);
	std::vector<int> v1;
	for(int i=0; i<22; i++)
	{
		int r = rand() % 100 + 1;
		v1.push_back(r);
		std::cout << r << std::endl;
	}	
	for(unsigned int i=0; i<v1.size(); i++)
	{
		h1.insert(v1[i], 0);
	}
	std::cout << "linear probing # of collisions: " << h1.getCollision() << std::endl;
	for(unsigned int i=0; i<v1.size(); i++)
	{
		h2.insert(v1[i], 1);
	}
	std::cout << "quadratic probing # of collisions: " << h2.getCollision() << std::endl;
	for(unsigned int i=0; i<v1.size(); i++)
	{
		h3.insert(v1[i], 2);
		
	}
	std::cout << "double hashing # of collisions: " << h3.getCollision() << std::endl;
	
	//load factor = 50-75%
	
	Hash h4 = Hash(47);
	Hash h5 = Hash(47);
	Hash h6 = Hash(47);
	std::vector<int> v2;
	int r2;
	for(int i=0; i<30; i++)
	{
		r2 = rand() % 100 + 1;
		v2.push_back(r2);
		std::cout << r2 << std::endl;
	}
	for(unsigned int i=0; i<v2.size(); i++)
	{
		h4.insert(v2[i], 0);
	}
	std::cout << "linear probing # of collisions: " << h4.getCollision() << std::endl;
	for(unsigned int i=0; i<v2.size(); i++)
	{
		h5.insert(v2[i], 1);
	}
	std::cout << "quadratic probing # of collisions: " << h5.getCollision() << std::endl;
	for(unsigned int i=0; i<v2.size(); i++)
	{
		h6.insert(v2[i], 2);
	}
	std::cout << "double hashing # of collisions: " << h6.getCollision() << std::endl;
	
	//load factor = <50%
	
	Hash h7 = Hash(71);
	Hash h8 = Hash(71);
	Hash h9 = Hash(71);
	std::vector<int> v3;
	int r3;
	for(int i=0; i<25; i++)
	{
		r3 = rand() % 100 + 1;
		v3.push_back(r3);
		std::cout << r3 << std::endl;
	}
	for(unsigned int i=0; i<v3.size(); i++)
	{
		h7.insert(v3[i], 0);
	}
	std::cout << "linear probing # of collisions: " << h7.getCollision() << std::endl;
	for(unsigned int i=0; i<v3.size(); i++)
	{
		h8.insert(v3[i], 1);
	}
	std::cout << "quadratic probing # of collisions: " << h8.getCollision() << std::endl;
	for(unsigned int i=0; i<v3.size(); i++)
	{
		h9.insert(v3[i], 2);
	}
	std::cout << "double hashing # of collisions: " << h9.getCollision() << std::endl;
	
	
	return 0;
}
