/* Rakib Hossain ID# 1001514252 */


#include "House.h"

#ifndef _CANDY_HOUSE_H
#define _CANDY_HOUSE_H

class CandyHouse : public House
{
	public:		
		CandyHouse(std::string, std::map<int, std::string>);
		std::string ringDoorbell(std::ostringstream &path);
		~CandyHouse();
};


#endif