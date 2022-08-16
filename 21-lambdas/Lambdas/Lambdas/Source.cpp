#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

// Lambdas are anonymous functions - quick and disposable functions, which can be treated more like variables.
// lambdas can be used at all places where function pointers are used.

void ForEach(const std::vector<int>& values, void(*func)(int v))
{
	for (int value : values)
		func(value);
}

void ForEachWithCapture(const std::vector<int>& values, const std::function <void(int)>& func)
{
	for (int value : values)
		func(value);
}

int main()
{
	std::vector<int> values = { 1,2,3,4,5 };

	auto lambda = [](int value) {std::cout << value << std::endl;};

	ForEach(values, lambda);

	int a = 10;
	auto lambdaWithCapture = [a](int value) {std::cout << "Captured value: " << a << "\nValue to be printed: " << value << std::endl; };
	ForEachWithCapture(values, lambdaWithCapture);

	//the values captured by value cannot be changed inside a lambda, unless marked as mutable
	auto lambdaWithMutable = 
		[a](int value) mutable {a = 9;  std::cout << "Captured value: " << a << "\nValue to be printed: " << value << std::endl; };
	ForEachWithCapture(values, lambdaWithMutable);


	//example of using lambda
	std::vector<int> val = { 1,2,3,4,5,6,7,8,9,10,11,12 };
	auto it = std::find_if(val.begin(), val.end(), [](int value) {return value > 11; });
	std::cout << *it << std::endl;
	std::cin.get();
	return 0;
}