/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysensoy <ysensoy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 22:36:18 by yasinsensoy       #+#    #+#             */
/*   Updated: 2023/04/01 13:48:45 by ysensoy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <string>
#include <deque>
#include <vector>
#include <time.h>

class PMergeMeDeque
{
public:
	int total_deque;

	PMergeMeDeque();
	~PMergeMeDeque();

	std::deque<int> deque;

	void	addDeque(char **argv, std::deque<int> *pdeque);
	void	printDeque(std::deque<int> &pdeque);
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
