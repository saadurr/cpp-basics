#include <iostream>
#include<cmath>
#include <chrono>

class Timer
{
private:
	std::chrono::time_point<std::chrono::high_resolution_clock> m_StartTimepoint;
	const char* m_Name;
	bool m_Stopped;

public:
	Timer(const char* name):m_Name(name),m_Stopped(false)
	{
		m_StartTimepoint = std::chrono::high_resolution_clock::now();
	}

	~Timer()
	{
		if (!m_Stopped)
			Stop();
	}

	void Stop()
	{
		auto endTimepoint = std::chrono::high_resolution_clock::now();

		auto start = std::chrono::time_point_cast<std::chrono::microseconds>(m_StartTimepoint).time_since_epoch().count();
		auto end = std::chrono::time_point_cast<std::chrono::microseconds>(endTimepoint).time_since_epoch().count();

		float duration = end - start;
		double ms = duration * 0.001;

		std::cout << m_Name <<" Timer took " << duration << " us (" << ms << " ms)." << std::endl;
		m_Stopped = true;
	}
};


void Function1()
{
	Timer timer("Function1");

	for (int i = 0; i < 1000; i++)
		std::cout << "Hello World - Line Number: " << i << std::endl;
}

void Function2()
{
	Timer timer("Function2");
	for (int i = 0; i < 1000; i++)
		std::cout << "Hello World - Line Number: " << sqrt(i) << std::endl;
}

int main()
{
	Function1();
	Function2();


	std::cin.get();
	return 0;
}