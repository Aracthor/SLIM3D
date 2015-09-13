//
// templates.hpp for SLIM3D in /home/aracthor/programs/projects/SLIM3D
// 
// Made by Aracthor
// 
// Started on  Sun Sep 13 08:57:37 2015 Aracthor
// Last Update Sun Sep 13 09:09:02 2015 Aracthor
//

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
