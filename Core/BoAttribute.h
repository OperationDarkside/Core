#pragma once
#ifndef BOATTRIBUTE_H
#define BOATTRIBUTE_H

#include "Bo.h"

class BoAttribute {
public:
	BoAttribute ();
	~BoAttribute ();

	int getBoAttributeMetaID ();
	void setBoAttributeMetaID (int attrId);

private:

	int boAttributeMeta = 0;
};

#endif // !BOATTRIBUTE_H