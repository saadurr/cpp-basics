#include <iostream>
#include <thread>

static bool s_Finished = false;

void DoWork()
{
	using namespace std::literals::chrono_literals;

	std::cout << "Started worker thread with id = " << std::this_thread::get_id() << std::endl;

	while (!s_Finished)
	{
		std::cout << "Worker Thread: Working..." << std::endl;
		std::this_thread::sleep_for(1s);
	}
}

int main()
{
	std::cout << "Started main thread with id = " << std::this_thread::get_id() << std::endl;
	std::thread worker(DoWork);

	std::cin.get();
	s_Finished = true;

	worker.join(); // wait for worker thread to finish and join.
	std::cout << "Finished Working" << std::endl;

	std::cin.get();
	return 0;
}