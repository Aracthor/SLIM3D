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
