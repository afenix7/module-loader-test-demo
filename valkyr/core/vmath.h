#pragma once

#include "../../extern/hlslpp/include/hlsl++.h"

namespace valkyr
{
using vfloat2 = hlslpp::float2;
using vfloat3 = hlslpp::float3;
using vfloat4 = hlslpp::float4;
using vuv = hlslpp::float2;

using vint2 = hlslpp::int2;
using vint3 = hlslpp::int3;
using vint4 = hlslpp::int4;

using vfloat4x4 = hlslpp::float4x4;
} // namespace valkyr

/*
#ifdef _WINDOWS

#ifdef _WIN10
#include <DirectXMath.h>
#include <DirectXPackedVector.h>
#include <DirectXCollision.h>
#else
	#include <xnamath.h>
#endif

using namespace DirectX;

 //SIMD support,should not use directly because _m128 alignment
typedef XMVECTOR vVector;
typedef XMMATRIX vMatrix;

typedef XMFLOAT4 vfloat4;
typedef XMFLOAT4A vfloat4a;
typedef XMFLOAT3 vfloat3;
typedef XMFLOAT2 vfloat2;

#define vLoadFloat4 XMLoadFloat4
#define vLoadFloat4A XMLoadFloat4A
#define vLoadFloat3 XMLoadFloat3
#define vLoadFloat2 XMLoadFloat2
#define vVector4Transform XMVector4Transform
#define vVector3Transform XMVector3Transform
#define vVector2Transform XMVector2Transform
#define vMatrixIdentity XMMatrixIdentity
#define vMatrixTranspose XMMatrixTranspose
#define vMatrixInverse XMMatrixInverse

struct Vector2 : public XMFLOAT2 {

};

#endif
*/