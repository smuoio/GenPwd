/**
 * @file CreatePwd.cpp
 * @brief the file implements the methods declared in the class createpwd
 * @author salvatore muoio
 */
#include <iostream>
#include <cstdio>
#include <ctime>
#include <string>
#include "Util.hpp"
#include "CreatePwd.hpp"

static _createpwd_::t_createpwd *GetAccess2t_createpwd()
{
	static _createpwd_::t_createpwd screatpwd;
	return(&screatpwd);
}

_typedef_::UINT64 createpwd::createfile(void)
{
	_typedef_::UINT64 lret = 0x0U;
	GetAccess2t_createpwd()->Pwdfile.open("pwd.cvs", std::ios_base::app);
	return(lret);
}

_typedef_::UINT64 createpwd::writefile(std::string pwd)
{
	_typedef_::UINT64 lret = 0x0U;
    std::time_t t = std::time(0); // Get current time
    std::tm* now = std::localtime(&t);
	GetAccess2t_createpwd()->Pwdfile<<pwd;
	GetAccess2t_createpwd()->Pwdfile<<'\t';
	GetAccess2t_createpwd()->Pwdfile<<now->tm_year+1900<<"\\";
	GetAccess2t_createpwd()->Pwdfile<<now->tm_mon+1<<"\\";
	GetAccess2t_createpwd()->Pwdfile<<now->tm_mday<<std::endl;


	return(lret);
}

createpwd::createpwd()
{
	this->createfile();
	this->createwpwd();
}

createpwd & createpwd::GetInstance()
{
	static createpwd instance;
	return(instance);
}

void createpwd::incrementcounter()
{
	GetAccess2t_createpwd()->counter++;
}

_typedef_::UINT64 createpwd::createwpwd()
{
	_typedef_::UINT64 lret = 0x0U;
	_typedef_::UINT64 lcount = 0x0U;
	GetAccess2t_createpwd()->pwd = GetAccess2t_createpwd()->base_word;
	do{
		//GetAccess2t_createpwd()->seed = _util_::genrandnum();
		GetAccess2t_createpwd()->seed = _util_::genericrandnum<_typedef_::UINT64> ();
		std::cout<<GetAccess2t_createpwd()->seed<<std::endl;
		if(_util_::checkrange(GetAccess2t_createpwd()->seed) == _typedef_::TRUE)
		{
			std::cout<<"number in the range"<<std::endl;
			GetAccess2t_createpwd()->pwd.push_back(_typedef_::CHAR8(GetAccess2t_createpwd()->seed));
			std::cout<<GetAccess2t_createpwd()->pwd<<std::endl;
			incrementcounter();
		}
		else
			std::cout<<"number out the range"<<std::endl;


	}while(GetAccess2t_createpwd()->counter < _typedef_::MAX_SIZE_FILL);

	this->writefile(GetAccess2t_createpwd()->pwd);

	return(lret);
}
