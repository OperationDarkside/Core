#pragma once
#ifndef BOATTRIBUTEMETA_H
#define BOATTRIBUTEMETA_H

#include "BoAttributeType.h"

#include <string>

class BoAttributeMeta {
public:
	BoAttributeMeta ();
	~BoAttributeMeta ();

	int getID ();
	void setID (int id);

	int getBoMetaID ();
	void setBoMetaID (int metaId);

	BoAttributeType getType ();
	void setType (BoAttributeType _type);

	std::string& getName ();
	void setName (std::string _name);

private:
	int id = 0;
	int boMetaId = 0;

	std::string name;
	BoAttributeType type;
};

#endif // !BOATTRIBUTEMETA_H