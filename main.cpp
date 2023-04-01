/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysensoy <ysensoy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 22:36:13 by yasinsensoy       #+#    #+#             */
/*   Updated: 2023/04/01 13:54:08 by ysensoy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
//Algoritmanın "n log n" zaman karmaşıklığı,
//sıralanacak eleman sayısına (n) bağlı olarak logaritmik olarak büyüyen
//bir süreksizlikle artar.
//Bu, eleman sayısı n arttıkça, sıralama işleminin büyüklüğünün logaritmik bir oranda arttığı anlamına gelir.

//Örneğin, 8 elemanlı bir diziyi sıralamak için mergesort kullanırsanız,
//sıralama işlemi 8 x log2(8) = 24 adım sürer.
//Ancak, 16 elemanlı bir dizi için bu sayı 16 x log2(16) = 64 adım olur.

//Bu nedenle, mergesort gibi "n log n" zaman karmaşıklığına sahip algoritmalar,
//eleman sayısının büyüklüğü arttıkça daha verimli çalışır
//Ve diğer sıralama algoritmalarına göre daha iyi performans gösterir.

//Logaritma tabanının seçimi,
//matematiksel olarak herhangi bir taban seçilebilir,
//ancak bilgisayarlar genellikle 2'nin katları üzerinde çalıştıklarından
//logaritma tabanı genellikle 2 olarak seçilir.

void merge_deque(std::deque<int> &pdeque, int left, int mid, int right)
{
	int n1 = mid - left + 1; // sol alt dizi boyutu
	int n2 = right - mid; // sağ alt dizi boyutu
	int tempL[n1];
	int tempR[n2];

	for (int i = 0; i < n1; i++)
		tempL[i] = pdeque[left + i];
	for (int j = 0; j < n2; j++)
		tempR[j] = pdeque[mid + j + 1];

	int i = 0;
	int j = 0;
	int k = left;

	while (i < n1 && j < n2) // sol ve sağdan daha küçüğünü ana diziye kopyala
	{
		if (tempL[i] <= tempR[j])
		{
			pdeque[k] = tempL[i];
			i++;
		}
		else
		{
			pdeque[k] = tempR[j];
			j++;
		}
		k++;
	}

	while (i < n1) //sol alt dizideki elemanları ana diziye kopyala.
	{
		pdeque[k] = tempL[i];
		i++;
		k++;
	}

	while (j < n2) // sağ alt dizideki elemanları ana diziye kopyala
	{
		pdeque[k] = tempR[j];
		j++;
		k++;
	}
}

void	merge_vec(std::vector<int> &pvec, int left, int mid, int right)
{
	int n1 = mid - left + 1; // sol alt dizi boyutu
	int n2 = right - mid; // sağ alt dizi boyutu
	int tempL[n1];
	int tempR[n2];

	for (int i = 0; i < n1; i++)
		tempL[i] = pvec[left + i];
	for (int j = 0; j < n2; j++)
		tempR[j] = pvec[mid + j + 1];

	int i = 0;
	int j = 0;
	int k = left;

	while (i < n1 && j < n2) // sol ve sağdan daha küçüğünü ana diziye kopyala
	{
		if (tempL[i] <= tempR[j])
		{
			pvec[k] = tempL[i];
			i++;
		}
		else
		{
			pvec[k] = tempR[j];
			j++;
		}
		k++;
	}

	while (i < n1) //sol alt dizideki elemanları ana diziye kopyala.
	{
		pvec[k] = tempL[i];
		i++;
		k++;
	}

	while (j < n2) // sağ alt dizideki elemanları ana diziye kopyala
	{
		pvec[k] = tempR[j];
		j++;
		k++;
	}
}

void	mergesortDeque(std::deque<int> &pdeque, int left, int right)
{
	if (left >= right)
		return;
	int	mid = left + (right - left) / 2;
	mergesortDeque(pdeque, left, mid);
	mergesortDeque(pdeque, mid + 1, right);
	merge_deque(pdeque, left, mid, right);
}

void	mergesortVec(std::vector<int> &pvector, int left, int right)
{
	if (left >= right)
		return;
	int	mid = left + (right - left) / 2;
	mergesortVec(pvector, left, mid);
	mergesortVec(pvector, mid + 1, right);
	merge_vec(pvector, left, mid , right);
}

template <typename T>
T	add(int left, int right)
{
	return (left + right);
}

int main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cerr << "Arg Error" << std::endl;
		return (1);
	}

	int i = 1;
	int j = 0;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] < 48 || argv[i][j] > 57)
			{
				std::cerr << "You should enter Just number" << std::endl;
				exit (1);
			}
			j++;
		}
		i++;
	}

	clock_t t1 = clock();
	PMergeMeVector obj1;

	obj1.addVector(&argv[1], &obj1.vector);
	std::cout << "Before:	"; obj1.printVec(obj1.vector);
	mergesortVec(obj1.vector, 0, obj1.total_vector - 1);
	std::cout << "After:	"; obj1.printVec(obj1.vector);
	//std::cout << "Vector size:	" << pvector.total_vector << std::endl;
	clock_t t2 = clock();

	double	time_1 = double(t2 - t1) / CLOCKS_PER_SEC;
	std::cout << "Time to process a range of " << obj1.total_vector << " elements with std::[..] : " << std::fixed << time_1 << " us" << std::endl;
	//std::cout << "Vector mergesort Time: " << std::fixed << time_1 << std::endl;

	std::cout << "--------------------------" << std::endl;

	clock_t t3 = clock();
	PMergeMeDeque obj2;
	obj2.addDeque(&argv[1], &obj2.deque);
	mergesortDeque(obj2.deque, 0, obj2.total_deque - 1);
	clock_t t4 = clock();
	//std::cout << "Map size:	" << pmap.total_map << std::endl;
	double	time_2 = double(t4 - t3) / CLOCKS_PER_SEC;

	std::cout << "Time to process a range of " << obj2.total_deque << " elements with std::[..] : " << std::fixed << time_2 << " us" << std::endl;
	//std::cout << "Deque mergesort Time: " << std::fixed << time_2 << std::endl;

	return(0);
}
