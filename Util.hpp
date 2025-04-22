/**
 * @file Util.hpp
 * @brief the file implements utilities methods
 * @author Salvatore Muoio
 */

#ifndef INCLUDE_UTIL_HPP_
#define INCLUDE_UTIL_HPP_

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Typedef.hpp"

namespace _util_
{
	/**
	 * @fn  _typedef_::UINT64 genrandnum()
	 * @brief generate the random number
	 * @return the seed generated
	 */
	_typedef_::UINT64 genrandnum()
	{
		static _typedef_::UINT64 oldseed = 0x0U;
		_typedef_::UINT64 lseed = 0x0U;
		srand((unsigned)time(NULL) + oldseed);
		lseed = std::rand()%125;
		oldseed = lseed;
		std::cout<<lseed<<std::endl;
		std::cout<<oldseed<<std::endl;
		return(lseed);
	}

	/**
	 * @fn _typedef_::e_numbool checkrange(_typedef_::UINT64 seed)
	 * @brief check if tyhe seed is in range
	 * @param _typedef_::UINT64 seed
	 * @return the seed generated
	 */

	_typedef_::e_numbool checkrange(_typedef_::UINT64 seed)
	{
		return (((seed >= _typedef_::MIN_ASCII) && (seed <= _typedef_::MAX_ASCII)) ? _typedef_::TRUE : _typedef_::FALSE);
	}
/**
	 * @fn  template <typename T> genericrandnum()
	 * @brief generate the random number, create template function
	 * @return the seed generated
	 */
	template <typename T>
	T genericrandnum()
	{
		static T oldseed = 0x0U;
		T lseed = 0x0U;
		srand((unsigned)time(NULL) + oldseed);
		lseed = std::rand()%125;
		oldseed = lseed;
		std::cout<<lseed<<std::endl;
		std::cout<<oldseed<<std::endl;
		return(lseed);
	}

}//namespace
//explicit instantiation definition
template _typedef_::UINT64 _util_::genericrandnum();








#endif /* INCLUDE_UTIL_HPP_ */
