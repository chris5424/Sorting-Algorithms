#pragma once

template <typename T>
void maxheap(T tab[], int rozmiar, int parentInd)
{
	int maxIndex = parentInd;
	int leftChild = parentInd * 2 + 1;
	int rightChild = parentInd * 2 + 2;

	if (leftChild < rozmiar && tab[leftChild] > tab[maxIndex]) {
		maxIndex = leftChild;
	}
	if (rightChild < rozmiar && tab[rightChild] > tab[maxIndex]) {
		maxIndex = rightChild;
	}
	if (maxIndex != parentInd) {
		T temp;
		temp = tab[maxIndex];
		tab[maxIndex] = tab[parentInd];
		tab[parentInd] = temp;
		maxheap(tab, rozmiar, maxIndex);
	}
}

template <typename T>
void heapsort(T tab[], int rozmiar)
{
	if (rozmiar == 0) {
		return;
	}
	int do_posortowania = rozmiar;
	for (int i = do_posortowania / 2 - 1; i >= 0; i--) {
		maxheap(tab, rozmiar, i);
	}

	for (int i = do_posortowania - 1; i > 0; i--) {
		T temp;
		temp = tab[0];
		tab[0] = tab[i];
		tab[i] = temp;
		do_posortowania--;
		maxheap(tab, do_posortowania, 0);
	}
}





template <typename T>
void maxheap_intro(T tab[], int rozmiar, int parentInd)
{
	int maxIndex = parentInd;
	int leftChild = parentInd * 2 + 1;
	int rightChild = parentInd * 2 + 2;

	if (leftChild < rozmiar && tab[leftChild] > tab[maxIndex]) {
		maxIndex = leftChild;
	}
	if (rightChild < rozmiar && tab[rightChild] > tab[maxIndex]) {
		maxIndex = rightChild;
	}
	if (maxIndex != parentInd) {
		T temp;
		temp = tab[maxIndex];
		tab[maxIndex] = tab[parentInd];
		tab[parentInd] = temp;
		maxheap(tab, rozmiar, maxIndex);
	}
}
template <typename T>
void heapsort_intro(T tab[],int l, int rozmiar)
{
	if ((rozmiar-l) == 0) {
		return;
	}
	int do_posortowania = rozmiar-l;
	for (int i = do_posortowania / 2 - 1; i >= l; i--) {
		maxheap(tab, rozmiar, i);
	}

	for (int i = do_posortowania - 1; i > l; i--) {
		T temp;
		temp = tab[l];
		tab[l] = tab[i];
		tab[i] = temp;
		do_posortowania--;
		maxheap(tab, do_posortowania, l);
	}
}