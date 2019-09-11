#include "Pair.h"

Pair::Pair(const char* k, const MyData& other):key(k), data(other) {}

Pair::Pair(const char* k, Sex s, size_t age, const char* job, float sal) : key(k), data(s, age, job, sal) {}

bool Pair::operator==(const char *k) const
{
	if (strcmp(key.GetString(), k) == 0) return true;
	else return false;
}

ostream& operator<<(ostream& os, const Pair& pair)
{
	os << "key: " << pair.key << "  " << pair.data;  // <<"\n";
	return os;
}



/*
Pair::Pair(const Pair& other):key(d.key), data(d.data){}

Pair& Pair::operator=(const Pair& other)
{
	if (this!=&other)
	{
		key = other.key;
		data = other.data;
	}
	return *this;
}
*/