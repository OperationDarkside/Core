#include "BoMetaManager.h"



BoMetaManager::BoMetaManager () {}


BoMetaManager::~BoMetaManager () {}

int BoMetaManager::getIndex (int boMetaID) {
	auto boMeta_index_find = boMeta_index.find (boMetaID);
	if (boMeta_index_find == boMeta_index.end ()) {
		return -1;
	}
	return boMeta_index_find->second;
}

BoMeta & BoMetaManager::getBoMeta (int index) {
	//auto boMeta_index_find = boMeta_index.find (boMetaID);

	return boMetas[index/*boMeta_index_find->second*/];
}
