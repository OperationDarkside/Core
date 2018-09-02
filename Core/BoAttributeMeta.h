#pragma once
#ifndef BOATTRIBUTEMETA_H
#define BOATTRIBUTEMETA_H

#include <string>

class BoAttributeMeta {
public:
	BoAttributeMeta ();
	~BoAttributeMeta ();

	int getID ();
	void setID (int id);

	int getBoMetaID ();
	void setBoMetaID (int metaId);

	std::string& getName ();
	void setName (std::string _name);

private:
	int id = 0;

	int boMetaId = 0;

	std::string name;
};

#endif // !BOATTRIBUTEMETA_H