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

	bool exists (int layoutID);

	Layout& getLayout (int layoutID);

private:
	std::vector<Layout> layouts;
	std::unordered_map<int, int> layout_index;
};

#endif // !LAYOUTMANAGER_H