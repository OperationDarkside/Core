#include "BoAttribute.h"



BoAttribute::BoAttribute () {}


BoAttribute::~BoAttribute () {}

int BoAttribute::getBoAttributeMetaID () {
	return boAttributeMeta;
}

void BoAttribute::setBoAttributeMetaID (int attrId) {
	this->boAttributeMeta = attrId;
}

BoAttributeType BoAttribute::getType () {
	return type;
}

void BoAttribute::setType (BoAttributeType _type) {
	type = _type;
}

BoValue & BoAttribute::getValue () {
	return val;
}

void BoAttribute::setValue (BoValue _value) {
	val = _value;
}
