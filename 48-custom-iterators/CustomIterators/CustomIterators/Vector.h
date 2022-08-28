#pragma once

template<typename Vector>
class VectorIterator
{
public:
	using ValueType = typename Vector::ValueType;
	using PointerType = ValueType*;
	using ReferenceType = ValueType&;
private:
	PointerType m_Ptr;
public:
	VectorIterator(PointerType ptr) : m_Ptr(ptr) {}
	VectorIterator& operator++()
	{
		m_Ptr++;
		return *this;
	}
	VectorIterator operator++(int)
	{
		VectorIterator iterator = *this;
		++(*this);
		return iterator;
	}

	VectorIterator& operator--()
	{
		m_Ptr++;
		return *this;
	}
	VectorIterator operator--(int)
	{
		VectorIterator iterator = *this;
		++(*this);
		return iterator;
	}

	ReferenceType operator[](int index)
	{
		return *(m_Ptr + index);
	}

	PointerType operator->()
	{
		return m_Ptr;
	}

	ReferenceType operator*()
	{
		return *m_Ptr;
	}

	bool operator==(const VectorIterator& other) const
	{
		return m_Ptr == other.m_Ptr;
	}

	bool operator!=(const VectorIterator& other) const
	{
		return !(*this==other);
	}
};

template <typename T>
class Vector
{
private:
	T* m_Data = nullptr;
	size_t m_Size = 0;
	size_t m_Capacity = 0;

public:
	using ValueType = T;
	using Iterator = VectorIterator<Vector<T>>;

private:
	void ReAlloc(size_t newCapacity)
	{
		T* newBlock = (T*) :: operator new (newCapacity * sizeof(T));

		if (newCapacity < m_Size)
			m_Size = newCapacity; //to handle the case where this function needs to downsize the vector object

		for (size_t i = 0; i < m_Size; i++)
			new(&newBlock[i]) T(std::move(m_Data[i])); //not using memcpy so that copy constructor gets triggered and performs the correct copy

		for (size_t i = 0; i < m_Size; i++)
			m_Data[i].~T();

		::operator delete(m_Data, m_Capacity * sizeof(T));
		m_Data = newBlock;
		m_Capacity = newCapacity;
	}
public:
	Vector()
	{
		ReAlloc(2);
	}

	~Vector()
	{
		Clear();
		
		delete[] m_Data;
	}

	void PushBack(const T& value)
	{
		if (m_Size >= m_Capacity)
			ReAlloc(m_Capacity + m_Capacity / 2);

		m_Data[m_Size] = value;
		m_Size++;
	}

	void PushBack(T&& value)
	{
		if (m_Size >= m_Capacity)
			ReAlloc(m_Capacity + m_Capacity / 2);

		m_Data[m_Size] = std::move(value);
		m_Size++;
	}

	void PopBack()
	{
		if (m_Size > 0)
		{
			m_Size--;
			m_Data[m_Size].~T();
		}
	}

	void Clear()
	{
		for (size_t i = 0; i < m_Size; i++)
			m_Data[i].~T();
		
		m_Size = 0;
	}

	template<typename... Args>
	T& EmplaceBack(Args&&... args)
	{
		if (m_Size >= m_Capacity)
			ReAlloc(m_Capacity + m_Capacity / 2);

		new(&m_Data[m_Size]) T(std::forward<Args>(args)...); //constructing object right in memory instead of creating and then moving.

//		m_Data[m_Size] = T(std::forward<Args>(args)...);

		return m_Data[m_Size++];
	}

	const T& operator[] (int index) const
	{
		return m_Data[index];
	}

	T& operator[] (int index)
	{
		return m_Data[index];
	}

	size_t Size() const
	{
		return m_Size;
	}

	Iterator begin()
	{
		return Iterator(m_Data);
	}

	Iterator end()
	{
		return Iterator(m_Data + m_Size);
	}
};