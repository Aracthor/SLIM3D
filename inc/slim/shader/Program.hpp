#ifndef SLIM_SHADER_PROGRAM_HPP_
# define SLIM_SHADER_PROGRAM_HPP_

# include "slim/assets/Asset.hpp"
# include "slim/containers/StringMap.hpp"
# include "slim/containers/SingleWrap.hpp"
# include "slim/maths/Vector2.hpp"
# include "slim/maths/Vector3.hpp"
# include "slim/maths/Vector4.hpp"
# include "slim/maths/Matrix4x4.hpp"
# include "slim/memory/ArenaChunk.hpp"
# include "slim/shader/Shader.hpp"

# define SLIM_SHADER_PROGRAM_MEMORY_SIZE	0x1000

namespace slim
{
namespace shader
{

class	Program : public assets::Asset
{
private:
    typedef GLint	Uniform;

public:
    static const char* const	typeName;

private:
    static memory::ArenaChunk&	getMemoryChunk();

private:
    static containers::SingleWrap<memory::ArenaChunk>	s_memory;

public:
    Program(const char* name, const Shader* vertexShader, const Shader* fragmentShader);
    ~Program();

public:
    inline void	use() const;

public:
    void	setUniform(const char* name, bool value) const;
    void	setUniform(const char* name, int value) const;
    void	setUniform(const char* name, float value) const;
    void	setUniform(const char* name, const Vector2& value) const;
    void	setUniform(const char* name, const Vector3& value) const;
    void	setUniform(const char* name, const Vector4& value) const;
    void	setUniform(const char* name, const Matrix4x4& value) const;

protected:
    void	onAssetsReady() override;
    void	onAssetsUnloaded() override;

private:
    void	addUniform(const char* name) const;
    void	checkUniform(const char* name) const;

private:
    GLint					m_id;
    const Shader*				m_vertexShader;
    const Shader*				m_fragmentShader;
    mutable containers::StringMap<Uniform>	m_uniforms;
};

}
}

# include "Program.ipp"

#endif // !SLIM_SHADER_PROGRAM_HPP_
