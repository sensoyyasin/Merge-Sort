/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysensoy <ysensoy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 22:36:16 by yasinsensoy       #+#    #+#             */
/*   Updated: 2023/04/01 13:48:47 by ysensoy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PMergeMeVector::PMergeMeVector()
{
	this->total_vector = 0;
}

PMergeMeVector::~PMergeMeVector() {}

PMergeMeDeque::PMergeMeDeque()
{
	this->total_deque = 0;
}

PMergeMeDeque::~PMergeMeDeque() {}

void	PMergeMeVector::addVector(char **argv, std::vector<int> *pvector)
{
	int i = 0;
	while (argv[i])
	{
		pvector->push_back(std::stoi(argv[i]));
		this->total_vector++;
		i++;
	}
}

void	PMergeMeDeque::addDeque(char **argv, std::deque<int> *pdeque)
{
	int i = 0;
	while (argv[i])
	{
		pdeque->push_back(std::stoi(argv[i]));
		this->total_deque++;
		i++;
	}
}

void	PMergeMeDeque::printDeque(std::deque<int> &pdeque)
{
	std::deque<int>::iterator it;

	it = pdeque.begin();
	while (it != pdeque.end())
	{
		std::cout << *it << std::endl;
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
