
/**
* DLL Export Define
* - This is a define for building this library as a DLL or as a static library
* - The syntax and meaning of this will be covered in class when we are covering
*   building a math library
**/
#ifdef MATH_DLL_BUILD
#define DLLEXPORT __declspec(dllexport)
#elif MATH_DLL
#define DLLEXPORT __declspec(dllimport)
#else
#define DLLEXPORT 
#endif

#ifndef __MATH_LIB_H__
#define __MATH_LIB_H__

#pragma warning (disable : 4201 )


#include <string>
#include <math.h>
#include "Vector2.h"
#include "Vector3.h"
#include "Vector4.h"
#include "Matrix3.h"
#include "Matrix4.h"


#endif //__MATH_LIB_H__

// TODO: reference additional headers your program requires here
