#include "LayoutManager.h"



LayoutManager::LayoutManager () {}


LayoutManager::~LayoutManager () {}

bool LayoutManager::exists (int layoutID) {
	auto layout_index_find = layout_index.find (layoutID);
	if (layout_index_find == layout_index.end ()) {
		return false;
	}
	return true;
}

Layout & LayoutManager::getLayout (int layoutID) {
	auto layout_index_find = layout_index.find (layoutID);

	return layouts[layout_index_find->second];
}
