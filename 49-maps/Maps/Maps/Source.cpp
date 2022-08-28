#include <iostream>
#include <unordered_map> // unordered map is a hash map
#include <map> // ordered map is a self-balancing binary search tree

struct CityRecord
{
	std::string Name;
	uint64_t Population;
	double Latitude, Longitude;
};

namespace std
{
	template<>
	struct hash<CityRecord>
	{
		size_t operator()(const CityRecord& key)
		{
			return hash<std::string>()(key.Name);
		}
	};
}

void PrintCityData(const CityRecord& record)
{
	std::cout << "City Name: " << record.Name << std::endl;
	std::cout << "City Population: " << record.Population << std::endl;
	std::cout << "City Longitude: " << record.Longitude << std::endl;
	std::cout << "City Latitude: " << record.Latitude << std::endl;
}

int main()
{
	//Key used in a map should be hashable.
	std::unordered_map<std::string, CityRecord> cityMap;
	cityMap["Islamabad"] = CityRecord{ "Islamabad", 2000000, 33.33, 34.33 };
	cityMap["Berlin"] = CityRecord{ "Berlin", 1800000, 89.33, 23.33 };
	cityMap["Tokyo"] = CityRecord{ "Tokyo", 5400000, 66.33, 89.33 };
	cityMap["Bangkok"] = CityRecord{ "Bangkok", 3000000, 13.33, 24.33 };
	cityMap["London"] = CityRecord{ "London", 4000000, 25.33, 34.33 };

	CityRecord& berlinData = cityMap["Berlin"];
	PrintCityData(berlinData);

	//If a structure is used as a key, it needs to be made hashable.
	std::unordered_map<CityRecord, uint32_t> foundedMap;
	//foundedMap[CityRecord{ "Melbourne", 500000,2.4,9.4 }] = 1850;
	//uint32_t melbourneFounded = foundedMap[CityRecord{ "Melbourne", 500000,2.4,9.4 }];

	//When accessing a value using [], data is inserted / created if not already present.
	CityRecord& tokyoData = cityMap.at("Berlin"); // needs also to be used if you have a const version of map

	//to find data in a map
	if (cityMap.find("Berlin") != cityMap.end())
	{
		const CityRecord& berlineData2 = cityMap.at("Berlin");
	}

	//iterating through map
	std::cout << "\n\nUsing iterator" << std::endl;
	for (auto& [key, value] : cityMap)
	{
		std::cout << key << " :\n";
		PrintCityData(value);
	}

	cityMap.erase("Berlin"); //to remove an entry using a key

	std::cout << "\n\nUsing iterator" << std::endl;
	for (auto& [key, value] : cityMap)
	{
		std::cout << key << " :\n";
		PrintCityData(value);
	}

	std::cin.get();
	return 0;
}