#ifndef SLIM_SCENE_TRANSFORMABLE_HPP_
# define SLIM_SCENE_TRANSFORMABLE_HPP_

# include "slim/maths/Vector3.hpp"
# include "slim/maths/Matrix4x4.hpp"

namespace slim
{
namespace scene
{

class	Transformable
{
public:
    Transformable();
    Transformable(const Transformable& reference);
    virtual ~Transformable();

public:
    inline const Vector3&	getPosition() const;
    inline const Vector3&	getRotation() const;
    inline const Vector3&	getScale() const;
    inline bool			isUpdated() const;
    inline const Matrix4x4&	getTransformationMatrix() const;

public:
    void			translate(const Vector3& translation);
    void			addRotation(const Vector3& rotation);
    void			scale(const Vector3& scale);
    void			setPosition(const Vector3& position);
    void			setRotation(const Vector3& rotation);
    void			setScale(const Vector3& scale);

protected:
    void			calcMatrix();
    void			calcMatrix(const Matrix4x4& parentMatrix);

private:
    void			applyTransformationsToMatrix();	

private:
    Vector3			m_position;
    Vector3			m_rotation;
    Vector3			m_scale;
    bool			m_updated;
    Matrix4x4			m_matrix;
};

}
}

# include "Transformable.ipp"

#endif // !SLIM_SCENE_TRANSFORMABLE_HPP_
