#include <iostream>
#include <map>

int min(int first, int second, int third)
{
	if (first <= second and first <= third)
	{
		return first;
	}
	else if (second <= first and second <= third)
	{
		return second;
	}
	else
	{
		return third;
	}
}

int min(int first, int second)
{
	return (first < second) ? first : second;
}

int TabulatedApproach(int num)
{
	int* arr = new int[num];
	for (int i = 1; i <= num; i++)
	{
		int val_to_add;
		if (i == 1)
		{
			val_to_add = -1;
		}
		else if (i % 2 == 0 and i % 3 != 0)
		{
			val_to_add = min(arr[i / 2], arr[i - 1]);
		}
		else if (i % 2 != 0 and i % 3 == 0)
		{
			val_to_add = min(arr[i / 3], arr[i - 1]);
		}
		else if (i % 2 == 0 and i % 3 == 0)
		{
			val_to_add = min(arr[i / 2], arr[i / 3], arr[i - 1]);
		}
		else
		{
			val_to_add = arr[i - 1];
		}
		val_to_add++;
		arr[i] = val_to_add;
	}
	return arr[num];
	delete arr;
}

int main()
{
	int num = 300000000;
	std::map<int, int> cache;
	int steps = TabulatedApproach(num);
	std::cout << "Steps needed for " << num << " = " << steps << std::endl;
	return 0;
}

