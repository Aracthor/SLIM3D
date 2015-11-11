namespace slim
{
namespace camera
{

template <class CAMERA, typename ...Args>
void
Node::createCamera(Args&& ...args)
{
    if (m_camera)
    {
	this->destroyCamera();
    }
    m_camera = new CAMERA(args...);
}

void
Node::destroyCamera()
{
    m_chunk.destroy(m_camera);
}


const Camera*
Node::getCamera() const
{
    return m_camera;
}

Camera*
Node::getCamera()
{
    return m_camera;
}

}
}
