#pragma once
#ifndef BO_H
#define BO_H

#include "BoMeta.h"
#include "BoAttribute.h"

#include <vector>
#include <memory>

class Bo {
public:
	Bo ();
	~Bo ();

	int getID ();
	void setID (int id);

	int getBoMetaId ();
	void setBoMetaId (int boMetaId);

	std::vector<BoAttribute>& getAttributes ();
	void setAttributes (std::vector<BoAttribute> _attributes);
private:
	int id = 0;

	int boMetaId = 0;

	std::vector<BoAttribute> attributes;
};

#endif // !BO_H