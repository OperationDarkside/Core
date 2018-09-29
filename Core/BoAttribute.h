#pragma once
#ifndef BOATTRIBUTE_H
#define BOATTRIBUTE_H

// #include "Bo.h"
#include "BoAttributeType.h"
#include "BoReference.h"
#include "BoDateTime.h"

#include <string>
#include <variant>

using BoValue = std::variant<long, double, BoDateTime, std::string, BoReference>;

class BoAttribute {
public:
	BoAttribute ();
	~BoAttribute ();

	int getBoAttributeMetaID ();
	void setBoAttributeMetaID (int attrId);

	BoAttributeType getType ();
	void setType (BoAttributeType _type);

	BoValue& getValue ();
	void setValue (BoValue _value);

private:
	int boAttributeMeta = 0;
	BoAttributeType type = BoAttributeType::INTEGER;
	BoValue val;
};

#endif // !BOATTRIBUTE_H