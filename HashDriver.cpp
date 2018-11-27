#include "Hash.h"
#include "Hash.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cassert>

using namespace std;

int main(){


    Hash passwords(10);
    cerr<< passwords.size()<< endl;
    assert(passwords.size() == 10);


	return 0;

}
