#include "PmergeMe.hpp"

PMergeMeVector::PMergeMeVector()
{
	this->total_vector = 0;
}

PMergeMeVector::~PMergeMeVector() {}

PMergeMeMap::PMergeMeMap()
{
	this->total_map = 0;
}

PMergeMeMap::~PMergeMeMap() {}

void	PMergeMeVector::addVector(char **argv, std::vector<int> *pvector)
{
	int i = 0;
	while (argv[i])
	{
		if (std::stoi(argv[i]) < 0)
		{
			std::cerr << "(-)Error" << std::endl;
			exit(1);
		}
		else
		{
			pvector->push_back(std::stoi(argv[i]));
			this->total_vector++;
		}
		i++;
	}
}

void	PMergeMeMap::addMap(char **argv, std::map<int, int> *pmap)
{
	int i = 0;
	while (argv[i])
	{
		if (std::stoi(argv[i]) < 0)
		{
			std::cerr << "(-)Error" << std::endl;
			exit(1);
		}
		else
		{
			pmap->insert(std::pair<int, int>(i, std::stoi(argv[i])));
			this->total_map++;
		}
		i++;
	}
}

void	PMergeMeMap::printMap(std::map<int, int> &pmap)
{
	std::map<int, int>::iterator it;

	it = pmap.begin();
	while (it != pmap.end())
	{
		//it->first indis, it->second value.
		std::cout << it->second << " ";
		++it;
	}
	std::cout << std::endl;
}

void	PMergeMeVector::printVec(std::vector<int> &pvector)
{
	std::vector<int>::iterator it;

	it = pvector.begin();
	while (it != pvector.end())
	{
		std::cout << *it << " ";
		++it;
	}
	std::cout << std::endl;
}
