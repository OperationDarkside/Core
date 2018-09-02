#include "BoMetaManager.h"



BoMetaManager::BoMetaManager () {}


BoMetaManager::~BoMetaManager () {}

bool BoMetaManager::exists (int boMetaID) {
	auto boMeta_index_find = boMeta_index.find (boMetaID);
	if (boMeta_index_find == boMeta_index.end ()) {
		return false;
	}
	return true;
}

BoMeta & BoMetaManager::getBoMeta (int boMetaID) {
	auto boMeta_index_find = boMeta_index.find (boMetaID);

	return boMetas[boMeta_index_find->second];
}
