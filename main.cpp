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

void	merge_map(std::map<int, int> &pmap, int left, int mid, int right)
{
	int n1 = mid - left + 1; // sol alt dizi boyutu
	int n2 = right - mid; // sağ alt dizi boyutu
	int tempL[n1];
	int tempR[n2];

	for (int i = 0; i < n1; i++)
		tempL[i] = pmap[left + i];
	for (int j = 0; j < n2; j++)
		tempR[j] = pmap[mid + j + 1];

	int i = 0;
	int j = 0;
	int k = left;

	while (i < n1 && j < n2) // sol ve sağdan daha küçüğünü ana diziye kopyala
	{
		if (tempL[i] <= tempR[j])
		{
			pmap[k] = tempL[i];
			i++;
		}
		else
		{
			pmap[k] = tempR[j];
			j++;
		}
		k++;
	}

	while (i < n1) //sol alt dizideki elemanları ana diziye kopyala.
	{
		pmap[k] = tempL[i];
		i++;
		k++;
	}

	while (j < n2) // sağ alt dizideki elemanları ana diziye kopyala
	{
		pmap[k] = tempR[j];
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

void	mergesortMap(std::map<int, int> &pmap, int left, int right)
{
	if (left >= right)
		return;
	int	mid = left + (right - left) / 2;
	mergesortMap(pmap, left, mid);
	mergesortMap(pmap, mid + 1, right);
	merge_map(pmap, left, mid, right);
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
	//std::cout << "Before:	"; obj1.printVec(obj1.vector);
	mergesortVec(obj1.vector, 0, obj1.total_vector - 1);
	//std::cout << "After:	"; obj1.printVec(obj1.vector);
	//std::cout << "Vector size:	" << pvector.total_vector << std::endl;
	clock_t t2 = clock();

	double	time_1 = double(t2 - t1);
	std::cout << "Vector mergesort Time: " << time_1 << std::endl;

	std::cout << "--------------------------" << std::endl;

	clock_t t3 = clock();
	PMergeMeMap obj2;
	obj2.addMap(&argv[1], &obj2.map);
	//std::cout << "Before:	"; obj2.printMap(obj2.map);
	mergesortMap(obj2.map, 0, obj2.total_map - 1);
	//std::cout << "After:	"; obj2.printMap(obj2.map);
	clock_t t4 = clock();
	//std::cout << "Map size:	" << pmap.total_map << std::endl;
	double	time_2 = double(t4 - t3);

	std::cout << "Map mergesort Time: " << time_2 << std::endl;

	return(0);
}
