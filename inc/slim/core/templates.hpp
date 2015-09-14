namespace slim
{
namespace core
{

template <template <class, class> class U, class T, class Allocator>
void
delete_content(U<T*, Allocator>& container)
{
    for (T* elem : container)
    {
	delete elem;
    }
}

}
}
