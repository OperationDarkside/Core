#pragma once
#ifndef QUERYBUILDER_H
#define QUERYBUILDER_H

#include "BoRequest.h"
#include "BoListRequest.h"

#include "BoMeta.h"

#include <string>
#include <list>

class QueryBuilder {
public:
	QueryBuilder ();
	~QueryBuilder ();

	static std::string getBoQuery (BoRequest& req, BoMeta& boMetaManager);
	static std::string getBoListQuery (BoListRequest& req, BoMeta& boMetaManager);

private:
};

#endif // !QUERYBUILDER_H