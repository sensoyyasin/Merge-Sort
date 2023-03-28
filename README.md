# Merge Sort In C++

In computer science, merge sort (also commonly spelled as mergesort) is an efficient, general-purpose, and comparison-based sorting algorithm. Most implementations produce a stable sort, which means that the order of equal elements is the same in the input and output. Merge sort is a divide-and-conquer algorithm that was invented by John von Neumann in 1945.[2] A detailed description and analysis of bottom-up merge sort appeared in a report by Goldstine and von Neumann as early as 1948.

Algorithm
Conceptually, a merge sort works as follows:

Divide the unsorted list into n sublists, each containing one element (a list of one element is considered sorted).
Repeatedly merge sublists to produce new sorted sublists until there is only one sublist remaining. This will be the sorted list.


An example of merge sort. First, divide the list into the smallest unit (1 element), then compare each element with the adjacent list to sort and merge the two adjacent lists. Finally, all the elements are sorted and merged.
|----------------------------------------------------------------------------------------------------------------------------------|
|![Merge-sort-example-300px](https://user-images.githubusercontent.com/73845925/228335873-cd6487ae-e52d-4f43-af57-69d4981fe04c.gif)|

Average performance	: n(log(n))

I used different container types here. These were map and vector. I tried few numbers at first and map gave faster results. Then I realized that vector is much faster when I give 3000 or more numbers.

Here is the proof.

<img width="750" alt="Screenshot" src="https://user-images.githubusercontent.com/73845925/228335884-bae9c9d6-ab34-4c91-a4de-688a50e0506c.png">
