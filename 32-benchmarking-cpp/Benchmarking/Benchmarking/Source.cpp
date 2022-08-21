#include <iostream>
#include <array>
#include <memory>
#include <chrono>

class Timer
{
private:
	std::chrono::time_point<std::chrono::high_resolution_clock> m_StartTimepoint;
public:
	Timer()
	{
		m_StartTimepoint = std::chrono::high_resolution_clock::now();
	}
	
	~Timer()
	{
		Stop();
	}

	void Stop()
	{
		auto endTimepoint = std::chrono::high_resolution_clock::now();

		auto start = std::chrono::time_point_cast<std::chrono::microseconds>(m_StartTimepoint).time_since_epoch().count();
		auto end = std::chrono::time_point_cast<std::chrono::microseconds>(endTimepoint).time_since_epoch().count();

		float duration = end - start;
		double ms = duration * 0.001;

		std::cout << "Timer took " << duration << " us (" << ms << " )." << std::endl;
	}
};

struct Vector2
{
	float x, y;
};

int main()
{
	int value = 0;
	std::cout << "\n Timer For Loop:\n";
	{
		Timer timer;
		for (int i = 0; i < 1000000; i++)
		{
			value += 2;
		}
	}

	std::cout << value << std::endl;

	std::cout << "\n Timer For Make Shared:\n";
	{
		std::array<std::shared_ptr<Vector2>, 1000> sharedPtrs;

		Timer timer;

		for (int i = 0; i < sharedPtrs.size(); i++)
			sharedPtrs[i] = std::make_shared<Vector2>();
	}

	std::cout << "\n Timer For New Shared:\n";
	{
		std::array<std::shared_ptr<Vector2>, 1000> sharedPtrs;

		Timer timer;

		for (int i = 0; i < sharedPtrs.size(); i++)
			sharedPtrs[i] = std::shared_ptr<Vector2>(new Vector2());
	}

	std::cout << "\n Timer For Make Unique:\n";
	{
		std::array<std::unique_ptr<Vector2>, 1000> sharedPtrs;

		Timer timer;

		for (int i = 0; i < sharedPtrs.size(); i++)
			sharedPtrs[i] = std::make_unique<Vector2>();
	}

	__debugbreak();

	std::cin.get();
	return 0;
}