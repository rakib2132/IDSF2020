/* Rakib Hossain ID# 1001514252 */
#include<cstring>
#include<stdio.h>
#include<chrono>
#include<thread>
#include "House.h" 

House::House(std::string NameOfHouse, std::map<int, std::string> PassMap)
: houseName{NameOfHouse}, CandyRankingMap{PassMap}
{

}

std::string House::ringDoorbell(std::ostringstream &totpath)
{

}

House::~House()
{
	std::cout << "HOUSE\n";
}