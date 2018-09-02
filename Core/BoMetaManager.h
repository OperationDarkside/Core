#pragma once
#ifndef BOMETAMANAGER_H
#define BOMETAMANAGER_H

#include "BoMeta.h"

#include <vector>
#include <unordered_map>

class BoMetaManager {
public:
	BoMetaManager ();
	~BoMetaManager ();

	bool exists (int boMetaID);

	BoMeta& getBoMeta (int boMetaID);

private:
	std::vector<BoMeta> boMetas;
	std::unordered_map<int, int> boMeta_index;
};

#endif // !BOMETAMANAGER_H