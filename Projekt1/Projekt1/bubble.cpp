#include "bubble.hpp"
template <typename T1>
bool bubble(T1 tab[], int s)
{
	bool zamiana = 0;
	do
	{
		zamiana = 0;
		for (int i = 0; i < s - 1; i++)
		{

			if (tab[i] > tab[i + 1])
			{
				T1 temp;
				temp = tab[i];
				tab[i] = tab[i + 1];
				tab[i + 1] = temp;
				zamiana = 1;
			}
		}

	} while (zamiana);
	return 1;
}