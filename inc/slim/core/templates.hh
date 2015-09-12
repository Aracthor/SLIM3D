//
// templates.hh for SLIM3D in /home/aracthor/programs/projects/SLIM3D
// 
// Made by Aracthor
// 
// Started on  Sat Sep 12 16:52:39 2015 Aracthor
// Last Update Sat Sep 12 17:09:22 2015 Aracthor
//

#ifndef SLIM_CORE_TEMPLATES_HH_
# define SLIM_CORE_TEMPLATES_HH_

namespace slim
{
namespace core
{

// Thanks to Kirill V. Lyadvinsky for this magic code.
// http://stackoverflow.com/questions/1412737/templated-class-function-t-how-to-find-out-if-t-is-a-pointer?#1412769 for code origin.
template <typename T>
struct data_details
{
    static const bool isPointer = false;
};
template <typename T>
struct data_details<T*>
{
    static const bool isPointer = false;
};

}
}

#endif // !SLIM_CORE_TEMPLATES_HH_
