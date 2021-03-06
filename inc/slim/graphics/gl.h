#ifndef SLIM_GRAPHICS_GL_H_
# define SLIM_GRAPHICS_GL_H_

# include "slim/system.h"

# if SLIM_SYSTEM_IS_APPLE
#  include <OpenGLES/ES3/gl.h>
# else
#  include <EGL/egl.h>
#  include <EGL/eglext.h>
#  include <GLES3/gl3.h>
# endif

#endif // !SLIM_GRAPHICS_GL_H_
