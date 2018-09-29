#pragma once
#ifndef BOMETA_H
#define BOMETA_H

#include "BoAttributeMeta.h"

#include <string>
#include <vector>
#include <unordered_map>

class BoMeta {
public:
	BoMeta ();
	~BoMeta ();

	int getID ();
	void setID (int id);

	std::string& getName ();
	void setName (std::string _name);

	std::vector<BoAttributeMeta>& getAttributes ();
	std::unordered_map<int, int>& getAttributeIndex();

private:
	int id = 0;

	std::string name;

	std::vector<BoAttributeMeta> attributes;
	std::unordered_map<int, int> attrIndex;
};

#endif // !BOMETA_H