// 4_1_template_square

#include <iostream>
#include <algorithm>
#include <vector>

template <class T>
T square(T num) 
{
	return num * num;
}

template <class T>
std::vector<T> square(std::vector<T> vec) 
{
	for (int i = 0; i < vec.size(); ++i) 
	{
		vec[i] *= vec[i];
	}
	return vec;
}

template <class T>
void print(std::vector<T> vec) 
{
	std::for_each(vec.begin(), vec.end(), [](int num) 
		{
		std::cout << num << " ";
		});
}

int main() {
	int num = 4;
	std::vector<int> vec = { -1, 4, 8 };

	std::cout << "[IN]: " << num << std::endl;
	std::cout << "[OUT]: " << square(num) << std::endl;
	std::cout << num << std::endl;
	std::cout << "[IN]: ";
	print(vec);
//	std::for_each(vec.begin(), vec.end(), [](int num) {	std::cout << num << " "; });

	std::cout << std::endl;

	std::cout << "[OUT]: ";
	print(square(vec));

//	std::for_each(vec.begin(), vec.end(), [square(vec)](int num) {	std::cout << num << " "; });

//	for (int i = 0; i < vec.size(); ++i) { std::cout << vec[i] << " "; }

}