#include "LayoutManager.h"



LayoutManager::LayoutManager () {}


LayoutManager::~LayoutManager () {}

int LayoutManager::getIndex (int layoutID) {
	auto layout_index_find = layout_index.find (layoutID);
	if (layout_index_find == layout_index.end ()) {
		return -1;
	}
	return layout_index_find->second;
}

Layout & LayoutManager::getLayout (int index) {
	//auto layout_index_find = layout_index.find (layoutID);

	return layouts[index/*layout_index_find->second*/];
}
