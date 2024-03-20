// 4_3_functor 

#include <iostream>
#include <algorithm>
#include <vector>

class Functor {
private:
	int sum = 0;
	int count = 0;

public:
	int get_sum() const
	{
		return sum;
	}

	int get_count() const
	{
		return count;
	}

	void operator()(int num)
	{
		if (!(num % 3))
		{
			sum += num;
			++count;
		}
	}
};

int main()
{
	std::vector<int> vec = { 4, 1, 3, 6, 25, 54 };

	Functor func;

	func = std::for_each(vec.begin(), vec.end(), func);

	std::cout << "[OUT]: get_sum() = " << func.get_sum() << std::endl;
	std::cout << "[OUT]: get_count() = " << func.get_count() << std::endl;
}
