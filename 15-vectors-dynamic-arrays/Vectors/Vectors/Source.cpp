#include <iostream>
#include <vector>

struct Vertex
{
	float x, y, z;

	Vertex(int x, int y, int z)
		:x(x),y(y),z(z)
	{

	}
};

std::ostream& operator<<(std::ostream& stream, const Vertex& vertex)
{
	stream << vertex.x << ", " << vertex.y << ", " << vertex.z;
	return stream;
}

int main()
{
	std::vector<Vertex> vertices;
	vertices.push_back({ 1,2,3 });
	vertices.push_back({ 4,5,6 });

	for (int i = 0; i < vertices.size(); i++)
		std::cout << vertices[i] << std::endl;
	
	for (const Vertex& v : vertices)
		std::cout << v << std::endl;

	vertices.erase(vertices.begin() + 1);

	//Reserving memory is a way to optimize vectors if the number of vectors is already known
	std::vector<Vertex> vertices2;
	vertices2.reserve(3);
	vertices2.push_back(Vertex(10, 20, 30));
	vertices2.push_back(Vertex(40, 50, 60));

	//emplace_back can be used instead of push_back which can help avoid creating the vector in main and then copying it to constructor
	vertices2.emplace_back(70, 80, 90);

	std::cin.get();
	return 0;
}