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

std::string & BoAttributeMeta::getName () {
	return name;
}

void BoAttributeMeta::setName (std::string _name) {
	name = _name;
}
