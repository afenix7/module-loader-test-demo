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

	void putInt(vint id, vint item)
	{
		intMap[id] = item;
	}
	void putCStr(vint id, vcstr item) {
		cstrMap[id] = item;
	}
	void putDouble(vint id, vdouble item) {
		doubleMap[id] = item;
	}
	void putFloat3(vint id, vfloat3 item) {
		float3Map[id] = item;
	}

	vint getInt(vint id) {
		return intMap[id];
	}

	vdouble getDouble(vint id) {
		return doubleMap[id];
	}

	vcstr getCstr(vint id) {
		return cstrMap[id];
	}

	vfloat3 getFloat3(vint id) {
		return float3Map[id];
	}

	void clear() {
		intMap.clear();
		cstrMap.clear();
		doubleMap.clear();
		float3Map.clear();
	}

private:
	map<vint, vint> intMap;
	map<vint, vcstr> cstrMap;
	map<vint, vdouble> doubleMap;
	map<vint, vfloat3> float3Map;
};
