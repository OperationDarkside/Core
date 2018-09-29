#include "BoAttributeMeta.h"



BoAttributeMeta::BoAttributeMeta () {}


BoAttributeMeta::~BoAttributeMeta () {}

int BoAttributeMeta::getID () {
	return id;
}

void BoAttributeMeta::setID (int id) {
	this->id = id;
}

int BoAttributeMeta::getBoMetaID () {
	return boMetaId;
}

void BoAttributeMeta::setBoMetaID (int metaId) {
	this->boMetaId = boMetaId;
}

BoAttributeType BoAttributeMeta::getType () {
	return type;
}

void BoAttributeMeta::setType (BoAttributeType _type) {
	type = _type;
}

std::string & BoAttributeMeta::getName () {
	return name;
}

void BoAttributeMeta::setName (std::string _name) {
	name = _name;
}
