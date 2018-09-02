#include "BoAttribute.h"



BoAttribute::BoAttribute () {}


BoAttribute::~BoAttribute () {}

int BoAttribute::getBoAttributeMetaID () {
	return boAttributeMeta;
}

void BoAttribute::setBoAttributeMetaID (int attrId) {
	this->boAttributeMeta = attrId;
}
