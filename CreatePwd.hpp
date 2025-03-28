/**
 * @file CreatePwd.cpp
 * @brief the file implements the class CreatePwd
 * @author Salvatore Muoio
 *
 */

#ifndef __CREATEPWD__
#define __CREATEPWD__
#include <fstream>
#include "Typedef.hpp"

namespace _createpwd_
{

/**
 * @struct t_createpwd
 * @brief structure used to store the data
 */
typedef struct
{
	std::string pwd;
	std::string base_word = "PCHasler";
	_typedef_::UINT64 seed;
	_typedef_::UINT64 counter;
	std::ofstream Pwdfile;
	//_typedef_::CHAR8 pwd[_typedef_::MAX_SIZE_PWD];

}t_createpwd;

}

/**
 * @class createpwd
 * @brief the class is a singleton and
 *
 */

class createpwd
{    private:

	/**
	 * @brief Constructor for createpwd class
	*/
	createpwd();

	/**
	 * @brief Virtual destructor for createpwd class
	*/
	virtual ~createpwd(){};
	/**
		 * @brief createpwd
	*/
	_typedef_::UINT64 createwpwd();

	/**
		 * @brief increments the counter used to compute the rest of pwd
	*/

	void incrementcounter();
	/**
		 * @brief createfile
	*/
	_typedef_::UINT64 createfile();

	/**
		 * @brief writefile
	*/
	_typedef_::UINT64 writefile(std::string pwd);


public:

	/**
	 * @brief Static method that gets the instance of the class
	 */
	static createpwd &GetInstance();
};



#endif
