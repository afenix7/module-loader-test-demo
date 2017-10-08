#pragma once

#include "./vplatform.h"

#define _GLM

//#define _DXMATH

#ifdef  _DXMATH

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

	#define new_vec(x,y,z,w) {x,y,z,w}
	#define new_vec(x,y,z) {x,y,z}
	#define new_vec(x,y) {x,y}
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

#elif defined(_GLM)

	#include "../thirdparty/glm/vec2.hpp"
	#include "../thirdparty/glm/vec3.hpp"
	#include "../thirdparty/glm/vec4.hpp"
	#include "../thirdparty/glm/matrix.hpp"
	#include "../thirdparty/glm/mat4x4.hpp"
	#include "../thirdparty/glm/gtc/matrix_transform.hpp"
	//clear not necessary headers for reducing compile time
	
	typedef glm::vec4 vVector;
	typedef glm::mat4x4 vMatrix;
	typedef glm::vec4 vfloat4;
	typedef glm::vec4 vfloat4a;
	typedef glm::vec3 vfloat3;
	typedef glm::vec2 vfloat2;

	#define new_vec(x,y,z,w) (x,y,z,w)
	#define new_vec(x,y,z,w) (x,y,z)
	#define new_vec(x,y) (x,y)
	#define new_vec(vec3,w) (vec3,w)
	#define new_vec(vec2,z) (vec2,z)

	#define vVector3Transform glm::translate
	#define vMatrixTranspose glm::transpose
	#define vMatrixInverse glm::inverse
	#define vPerspectiveLH glm::perspectiveLH
	#define vPerspectiveRH glm::perspectiveRH
	#define vPerspectiveFovLH glm::perspectiveFovLH
	#define vPerspectiveFovRH glm::perspectiveFovRH
	#define vOrthoLH glm::orthoLH
	#define vOrthoRH glm::orthoRH
	#define vFrustumLH glm::frustumLH
	#define vFrustumRH glm::frustumRH
	#define vLookAtLH glm::lookAtLH
	#define vLookAtRH glm::lookAtRH
	#define vTranslate glm::translate
	#define vScale glm::scale
	#define vRotate glm::rotate
	#define vUnProject glm::unProject
	#define vPickMatrix glm::pickMatrix
	#define vCross glm::cross
	#define vDot glm::dot
	#define vLen glm::length
	#define vDistance glm::distance
	#define vNormalize glm::normalize
	#define vReflect glm::reflect
	#define vRefract glm::refract
	#define vAdd(x,y) x+y
	#define vSubtract(x,y) x-y
	#define vMultiply(x,y) x*y
#endif