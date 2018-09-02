#pragma once
#ifndef BOMETA_H
#define BOMETA_H

#include "BoAttributeMeta.h"

#include <string>
#include <vector>

class BoMeta {
public:
	BoMeta ();
	~BoMeta ();

	int getID ();
	void setID (int id);

	std::string& getName ();
	void setName (std::string _name);

	std::vector<BoAttributeMeta>& getAttributes ();

private:
	int id = 0;

	std::string name;

	std::vector<BoAttributeMeta> attributes;
};

#endif // !BOMETA_H