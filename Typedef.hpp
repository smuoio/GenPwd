/**
 * @file Typedef.hpp
 * @brief Declares the types used in the whole project
 * @author Hasler HMI Team
*/

#ifndef __TYPEDEF_H__
#define __TYPEDEF_H__

/**
 * @def Defines the length of PIXYMVB_Data array
*/
#define PIXYMVB_DATA_LENGTH 16

/**
 *  @brief This namespace contains the types defined in the project
 */
namespace _typedef_
{

    /**
     * @brief CHAR8
     */
    typedef char           CHAR8;

    /**
     * @brief UINT8
     */
    typedef unsigned char  UINT8;

    /**
     * @brief UINT16
     */
    typedef unsigned short UINT16;

    /**
     * @brief UINT64
     */
    typedef long int       UINT64;

    /**
	 * @enum e_numbool
	 * @brief Represents boolean values
	*/
    typedef enum
    {
    	FALSE,
		TRUE
    }e_numbool;


    typedef enum
    {
    	MIN_ASCII     = 33,
		MAX_ASCII     = 122,
    	MAX_SIZE_FILL = 8,
    	MAX_SIZE_PWD = 15,
    }e_maxsize;



};

#endif /* __TYPEDEF_H__ */
