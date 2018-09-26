#pragma once
#ifndef LAYOUTMANAGER_H
#define LAYOUTMANAGER_H

#include "Layout.h"

#include <vector>
#include <unordered_map>

class LayoutManager {
public:
	LayoutManager ();
	~LayoutManager ();

	int getIndex (int layoutID);

	Layout& getLayout (int index);

private:
	std::vector<Layout> layouts;
	std::unordered_map<int, int> layout_index;
};

#endif // !LAYOUTMANAGER_H