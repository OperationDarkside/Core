#include "BoMeta.h"



BoMeta::BoMeta () {}


BoMeta::~BoMeta () {}

int BoMeta::getID () {
	return id;
}

void BoMeta::setID (int id) {
	this->id = id;
}

std::string & BoMeta::getName () {
	return name;
}

void BoMeta::setName (std::string _name) {
	name = _name;
}

std::vector<BoAttributeMeta>& BoMeta::getAttributes () {
	return attributes;
}

std::unordered_map<int, int>& BoMeta::getAttributeIndex () {
	return attrIndex;
}
