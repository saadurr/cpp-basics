#include <iostream>
#include <memory>

struct AllocationMetrics
{
	uint32_t TotalAllocated = 0;
	uint32_t TotalReleased = 0;

	uint32_t CurrentUsage()
	{
		return TotalAllocated - TotalReleased;
	}
};

static AllocationMetrics s_AllocationMetrics;

void* operator new(size_t size)
{
	s_AllocationMetrics.TotalAllocated += size;

	std::cout << "Allocating " << size << " bytes of memory.\n";

	return malloc(size);
}

void operator delete(void* memory, size_t size)
{
	s_AllocationMetrics.TotalReleased += size;

	std::cout << "Releasing " << size << " bytes of memory.\n";

	free(memory);
}

static void PrintMemoryUsage()
{
	std::cout << "Current memory usage: " << s_AllocationMetrics.CurrentUsage() << std::endl;
}

int main()
{
	PrintMemoryUsage();
	std::string str = "Saad";
	PrintMemoryUsage();
	{
		std::unique_ptr<std::string> strPtr = std::make_unique<std::string>("Saad");
		PrintMemoryUsage();
	}
	PrintMemoryUsage();

	std::cin.get();
	return 0;
}