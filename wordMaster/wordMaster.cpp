// wordMaster.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Dictionary.h"
#include <iostream>


int main()
{
	wordMaster::Dictionary *dictionary = new wordMaster::Dictionary();
	dictionary->AddWord("woda", "water");
	//dictionary->AddWord("maslo", "butter");
	std::string translation = dictionary->GetTranslation("woda");
	std::cout << "woda = " << translation << std::endl;

	std::string translation2 = dictionary->GetTranslation("water");
	std::cout << "water = " << translation2 << std::endl;
	std::string trans3 = dictionary->GetTranslation("domb");
	std::cin.get();
    return 0;
}

