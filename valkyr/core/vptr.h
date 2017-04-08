#include "vplatform.h"
#include <memory>
/*
template <typename T>
class vshared_ptr{
public:
	vshared_ptr(T* target):mPtr(target){
	}

	vshared_ptr(std::shared_ptr<T> target) :mPtr(target) {
	}

	vshared_ptr(vshared_ptr& otherPtr):mPtr(otherPtr.mPtr){

	}

	T& operator *()  
	{
		return *mPtr;
	}

	T** operator **()
	{
		return &mPtr;
	}

	T* operator -> (){
		return mPtr;
	}

	void reset() {
		mPtr.reset();
	}

	void release() {
		mPtr.release();
	}

	T*  get() {
		return mPtr.get();
	}

	vbool operator !() {
		return !mPtr;
	}

	operator bool() {
		return mPtr==nullptr;
	}

	template<typename T2>
	vshared_ptr<T2> cast() {
		return vshared_ptr(std::static_pointer_cast<T2>(mPtr));
	}

protected:
	std::shared_ptr<T> mPtr;
};
*/
#define vshared_ptr std::shared_ptr

#define vptr vshared_ptr

#define vnew_ptr std::make_shared