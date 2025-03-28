#include <iostream>
//#include "config.h"
#include "CreatePwd.hpp"

int main(int argc, char **argv) {
	//std::cout << "Hello World" << std::endl;
	//std::cout << "Version " << GenPwd_VERSION_MAJOR << "." << GenPwd_VERSION_MINOR << std::endl;
	createpwd::GetInstance();
	return 0;
}
