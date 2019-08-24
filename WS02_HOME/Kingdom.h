

// TODO: header safeguards

#ifndef SICT_KINGDOM_H
#define SICT_KINGDOM_H


// TODO: sict namespace

namespace sict {

	// TODO: define the structure Kingdom in the sict namespace

	// TODO: declare the function display(...),
	//         also in the sict namespace
	
	struct Kingdom {

		char m_name[32];
		int m_population;
	};
	void display(const Kingdom&);
	void display(const Kingdom* Kingdom, int size);

}

#endif
