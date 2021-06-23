/* Rakib Hossain ID# 1001514252 */
#include "ToothbrushHouse.h"


ToothbrushHouse::ToothbrushHouse(std::string NameOfHouse, std::map<int, std::string> passMap)
: House(NameOfHouse, passMap)
{}

std::string ToothbrushHouse::ringDoorbell(std::ostringstream &totpath)
{
	//int random=rand()%CandyRankingMap.size()+1;
	door.lock();
	totpath<<"-";
	std::this_thread::sleep_for(std::chrono::seconds(3));
	door.unlock();

	return "TOOTHBRUSH";
}

ToothbrushHouse::~ToothbrushHouse()
{
	std::cout << "TOOTBRUSHHOUSE\n";
}