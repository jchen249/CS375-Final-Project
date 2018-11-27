#include "Hash.h"
#include <stdlib.h>
#include <iostream>

int main(int argc, char **argv)
{
	Hash h1 = Hash(17);
	Hash h2 = Hash(17);
	Hash h3 = Hash(17);
	std::vector<int> v1;
	for(int i=0; i<13; i++)
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
	return 0;
}
