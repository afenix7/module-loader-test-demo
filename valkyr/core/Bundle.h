#pragma once
#include "vcommon.h"
#include "vmath.h"
#include <map>

using namespace std;

class Bundle
{
public:
	Bundle()
	{
	}

	~Bundle()
	{
	}

	void putInt(vstr id, vint item)
	{
		intMap[id] = item;
	}
	void putCStr(vstr id, vcstr item)
	{
		cstrMap[id] = item;
	}
	void putDouble(vstr id, vdouble item)
	{
		doubleMap[id] = item;
	}
	void putFloat3(vstr id, vfloat3 item)
	{
		float3Map[id] = item;
	}

	vint getInt(vstr id)
	{
		return intMap[id];
	}

	double getDouble(vstr id)
	{
		return doubleMap[id];
	}

	vcstr getCstr(vstr id)
	{
		return cstrMap[id];
	}

	float3 getFloat3(vstr id)
	{
		return float3Map[id];
	}

	void clear()
	{
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
