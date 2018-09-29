#include "QueryBuilder.h"



QueryBuilder::QueryBuilder () {}


QueryBuilder::~QueryBuilder () {}

std::string QueryBuilder::getBoQuery (BoRequest & req, BoMeta& boMeta) {
	std::list<std::string> stringbuilder;

	int boMetaId = req.getBoMetaID ();
	auto& attrIds = req.getBoAttrMetaIDs ();

	stringbuilder.push_back ("SELECT ");

	auto& attributes = boMeta.getAttributes ();
	auto& attrIndex = boMeta.getAttributeIndex ();

	for (int attrID : attrIds) {
		int attrInd = attrIndex[attrID];
		BoAttributeMeta& metaAttr = attributes[attrInd];

		stringbuilder.push_back (metaAttr.getName());
		stringbuilder.push_back (", ");
	}
	stringbuilder.pop_back ();

	stringbuilder.push_back (" FROM ");
	stringbuilder.push_back (boMeta.getName ());
	stringbuilder.push_back (" WHERE BoID=");
	stringbuilder.push_back (std::to_string(req.getBoID()));
	stringbuilder.push_back (";");

	size_t len = 0;
	for (auto& ele : stringbuilder) {
		len += ele.size ();
	}

	std::string res;
	res.resize (len);

	for (auto& ele : stringbuilder) {
		res += ele;
	}

	return res;
}

std::string QueryBuilder::getBoListQuery (BoListRequest & req, BoMeta & boMeta) {
	std::list<std::string> stringbuilder;

	int boMetaId = req.getBoMetaID ();
	auto& attrIds = req.getBoAttrMetaIDs ();

	stringbuilder.push_back ("SELECT ");

	auto& attributes = boMeta.getAttributes ();
	auto& attrIndex = boMeta.getAttributeIndex ();

	for (int attrID : attrIds) {
		int attrInd = attrIndex[attrID];
		BoAttributeMeta& metaAttr = attributes[attrInd];

		stringbuilder.push_back (metaAttr.getName ());
		stringbuilder.push_back (", ");
	}
	stringbuilder.pop_back ();

	stringbuilder.push_back (" FROM ");
	stringbuilder.push_back (boMeta.getName ());
	stringbuilder.push_back (" WHERE BoStatus in (");

	for (int statusID : req.getAllowedStatuses ()) {
		stringbuilder.push_back (std::to_string (statusID));
		stringbuilder.push_back (",");
	}
	stringbuilder.pop_back ();

	stringbuilder.push_back (");");

	size_t len = 0;
	for (auto& ele : stringbuilder) {
		len += ele.size ();
	}

	std::string res;
	res.resize (len);

	for (auto& ele : stringbuilder) {
		res += ele;
	}

	return res;
}
