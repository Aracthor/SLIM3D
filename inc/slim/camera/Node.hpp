#ifndef SLIM_CAMERA_NODE_HPP_
# define SLIM_CAMERA_NODE_HPP_

# include "slim/camera/Camera.hpp"
# include "slim/scene/Node.hpp"

namespace slim
{
namespace camera
{

class	Node : public scene::Node
{
public:
    Node(memory::Chunk& memory, const char* name, scene::Node* parent, Camera* camera = nullptr);
    ~Node();

public:
    template <class CAMERA, typename ...Args> // CAMERA must inherit from slim::camera::Camera.
    void	createCamera(Args&& ...args);
    inline void	destroyCamera();

public:
    inline const Camera*	getCamera() const;
    inline Camera*		getCamera();

protected:
    void        updateData(time::Clock::time elapsedTime) override;

private:
    Camera*	m_camera;
};

}
}

# include "Node.ipp"

#endif // !SLIM_CAMERA_NODE_HPP_
