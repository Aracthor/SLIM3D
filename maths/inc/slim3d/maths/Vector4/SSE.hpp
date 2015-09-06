//
// SSE.hpp<2> for SLIM3D in /home/aracthor/programs/projects/SLIM3D/maths
// 
// Made by Aracthor
// 
// Started on  Sun Sep  6 00:31:17 2015 Aracthor
// Last Update Sun Sep  6 00:34:26 2015 Aracthor
//

namespace slim
{
namespace maths
{

template <typename T>
Vector4<T>::Vector4(__m128 data)
{
    this->set(data);
}


template <typename T>
__m128
Vector4<T>::asSSE() const
{
    return _mm_load_ps(reinterpret_cast<const float*>(this));
}


template <typename T>
Vector4<T>&
Vector4<T>::set(__m128 data)
{
    _mm_store_ps(reinterpret_cast<float*>(this), data);
    return *this;
}


template <typename T>
Vector4<T>&
Vector4<T>::operator=(__m128 data)
{
    return this->set(data);
}


}
}
