#pragma once
#include "vcommon.h"
#include <map>

using namespace std;

class Config 
{
public:
	Config() {

	}

	~Config() {

	}

	void putInt(vcstr key, vint item)
	{
		intMap[key] = item;
	}
	void putCStr(vcstr key, vcstr item) {
		cstrMap[key] = item;
	}
	void putDouble(vcstr key, vdouble item) {
		doubleMap[key] = item;
	}

	vint getInt(vcstr key) {
		return intMap[key];
	}

	vdouble getDouble(vcstr key) {
		return doubleMap[key];
	}

	vcstr getCstr(vcstr key) {
		return cstrMap[key];
	}

	void clear() {
		intMap.clear();
		cstrMap.clear();
		doubleMap.clear();
	}

private:
	map<vcstr, vint> intMap;
	map<vcstr, vcstr> cstrMap;
	map<vcstr, vdouble> doubleMap;
};
