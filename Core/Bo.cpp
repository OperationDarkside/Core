#include "Bo.h"



Bo::Bo () {}


Bo::~Bo () {}

int Bo::getID () {
	return id;
}

void Bo::setID (int id) {
	this->id = id;
}

int Bo::getBoMetaId () {
	return boMetaId;
}

void Bo::setBoMetaId (int boMetaId) {
	this->boMetaId = boMetaId;
}

std::vector<std::unique_ptr<BoAttribute>>& Bo::getAttributes () {
	return attributes;
}
