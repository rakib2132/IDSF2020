/* Rakib Hossain ID# 1001514252 */
#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include<map>
#include<cstring>
#include<stdio.h>
#include<string.h>
#include<chrono>
#include<thread>
#include "TrickOrTreater.h"   
#include "House.h"

int TrickOrTreater::ImDone=0;

TrickOrTreater::TrickOrTreater(std::string ToTName, std::vector<House*>HousePtr)
:name{ToTName},ListOfHouses{HousePtr}
{

}


std::string TrickOrTreater::getName()
{
	return name;
}

void TrickOrTreater::startThread()
{
	TOTThreadPtr = new std::thread(&TrickOrTreater::GoTrickOrTreating, this);
}

void TrickOrTreater::joinThread()
{
	this->TOTThreadPtr->join();
	delete this->TOTThreadPtr;
}

void TrickOrTreater::Walk(int speed )
{
	for(int i=0; i<10;i++)
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(speed));
		path<<".";


	}
}

void TrickOrTreater::GoTrickOrTreating()
{
	std::string captureName;
	for(auto it: ListOfHouses)
	{
		int speed=rand()%((500)+1);
		Walk(speed);
		captureName=it->ringDoorbell(path);
		Bucket[captureName]++;

	}

	ImDone++;

}


std::string TrickOrTreater::getPath()
{
	return path.str();
}



std::ostream& operator<<(std::ostream& input, TrickOrTreater& TOT)
{
	std::cout<<TOT.name<<"----";
	for(auto it: TOT.Bucket)
	{
		input<<it.first<<" ";
		input<<it.second<<",";
		
	}
	input<<std::endl;
}

