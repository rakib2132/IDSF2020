/* Rakib Hossain ID# 1001514252 */

#include "House.h"

#ifndef _TOOTHBRUSH_HOUSE_H
#define _TOOTHBRUSH_HOUSE_H

class ToothbrushHouse : public House
{
	public:	
		ToothbrushHouse(std::string, std::map<int, std::string>);
		std::string ringDoorbell(std::ostringstream &path);
		~ToothbrushHouse();
};


#endif
