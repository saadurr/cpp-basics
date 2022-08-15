#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

std::string GetString()
{
	return "Saad";
}

class Device
{};

class DeviceManager
{
private:
	std::unordered_map<std::string, std::vector<Device*>> m_Devices;
public:
	const std::unordered_map<std::string, std::vector<Device*>>& GetDevices() const
	{
		return m_Devices;
	}
};

int main()
{
	auto name = GetString();
	std::cout << name << std::endl;

	std::vector<std::string> strings;
	strings.push_back("String-One");
	strings.push_back("String-Two");

	//std::vector<std::string>::iterator it has been replaced with auto
	for (auto it = strings.begin(); it != strings.end(); it++)
	{
		std::cout << *it << std::endl;
	}

	DeviceManager dm;
	const std::unordered_map<std::string, std::vector<Device*>>& device = dm.GetDevices();
	// this long name can be replaced with two things:
	// using DeviceMap = const std::unordered_map<std::string, std::vector<Device*>>&
	// typedef const std::unordered_map<std::string, std::vector<Device*>>& DeviceMap

	const auto& device2 = dm.GetDevices();

	std::cin.get();
	return 0;
}