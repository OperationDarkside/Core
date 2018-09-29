#pragma once
#ifndef BOREFERENCE_H
#define BOREFERENCE_H

#include <string>

class BoReference {
public:
	BoReference ();
	~BoReference ();

	int getID ();
	void setID (int _id);

	std::string& getName ();
	void setName (std::string _name);

private:
	int id = 0;
	std::string name;
};

#endif // !BOREFERENCE_H