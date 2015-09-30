namespace slim
{
namespace maths
{

template <>
Vector4<float>&
Vector4<float>::set(__m128 data)
{
    _mm_store_ps(reinterpret_cast<float*>(this), data);
    return *this;
}


template <>
Vector4<float>::Vector4(__m128 data)
{
    this->set(data);
}



template <>
__m128
Vector4<float>::asSSE() const
{
    return _mm_load_ps(reinterpret_cast<const float*>(this));
}


template <>
Vector4<float>&
Vector4<float>::operator=(__m128 data)
{
    return this->set(data);
}


}
}
