
#ifndef NAMESPACE_KINGDOM_H
#define NAMESPACE_KINGDOM_H


#include <iostream>
using namespace std;
namespace sict
{
	struct Kingdom
	{
		char m_name[32];
		int m_population;
	};
	void display(const Kingdom*);
}
#endif // !NAMESPACE_KINGDOM_H
