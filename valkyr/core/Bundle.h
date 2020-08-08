#pragma once
#include "vcommon.h"
#include "vmath.h"
#include <map>

namespace valkyr
{
class Bundle
{
public:
	Bundle()
	{
	}

	~Bundle()
	{
	}

	void putInt(vcstr key, vint item)
	{
		intMap[key] = item;
	}
	void putCStr(vcstr key, vcstr item)
	{
		cstrMap[key] = item;
	}
	void putDouble(vcstr key, double item)
	{
		doubleMap[key] = item;
	}
	void putFloat3(vcstr key, vfloat3 item)
	{
		float3Map[key] = item;
	}

	vint getInt(vcstr key)
	{
		return intMap[key];
	}

	double getDouble(vcstr key)
	{
		return doubleMap[key];
	}

	vcstr getCstr(vcstr key)
	{
		return cstrMap[key];
	}

	vfloat3 getFloat3(vcstr key)
	{
		return float3Map[key];
	}

	void clear()
	{
		intMap.clear();
		cstrMap.clear();
		doubleMap.clear();
		float3Map.clear();
	}

private:
	std::map<vcstr, vint> intMap;
	std::map<vcstr, vcstr> cstrMap;
	std::map<vcstr, double> doubleMap;
	std::map<vcstr, vfloat3> float3Map;
};
} // namespace valkyr
