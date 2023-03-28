#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <time.h>

class PMergeMeMap
{
public:
	int total_map;

	PMergeMeMap();
	~PMergeMeMap();

	std::map<int, int> map;

	void	addMap(char **argv, std::map<int, int> *pmap);
	void	printMap(std::map<int, int> &pmap);
};

class PMergeMeVector
{
public:
	int total_vector;

	PMergeMeVector();
	~PMergeMeVector();

	std::vector<int> vector;

	void	addVector(char **argv, std::vector<int> *pvector);
	void	printVec(std::vector<int> &pvector);
};

#endif
