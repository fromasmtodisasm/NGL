#include <pybind11/pybind11.h>
#include <pybind11/operators.h>
#include <pybind11/stl.h>
#include <pybind11/cast.h>

#include "ShaderProgram.h"
namespace py = pybind11;
namespace ngl
{
  void pyInitShaderProgram(py::module & m)
  {
    py::class_<ShaderProgram>(m, "ShaderProgram")
        .def(py::init<std::string >())
        .def("use",&ShaderProgram::use)
        .def("unbind",&ShaderProgram::unbind)
        .def("attachShader",&ShaderProgram::attachShader)
        .def("bindAttribute",&ShaderProgram::bindAttribute)
    //    .def("bindFragDataLocation",(void(ShaderProgram::*)(GLuint,const std::string &)) &ShaderProgram::bindFragDataLocation)
        .def("link",&ShaderProgram::link)
        .def("getID",&ShaderProgram::getID)
        .def("getUniformLocation",&ShaderProgram::getUniformLocation)
        .def("printActiveUniforms",&ShaderProgram::printActiveUniforms)
        .def("printActiveAttributes",&ShaderProgram::printActiveAttributes)
        .def("printProperties",&ShaderProgram::printProperties)
    //    .def("setUniform1f",&ShaderProgram::setUniform1f)
        .def("setRegisteredUniform1f",&ShaderProgram::setRegisteredUniform1f)
      //  .def("setUniform2f",&ShaderProgram::setUniform2f)
        .def("setRegisteredUniform2f",&ShaderProgram::setRegisteredUniform2f)
        //.def("setUniform3f",&ShaderProgram::setUniform3f)
        .def("setRegisteredUniform3f",&ShaderProgram::setRegisteredUniform3f)
       // .def("setUniform4f",&ShaderProgram::setUniform4f)
        .def("setRegisteredUniform4f",&ShaderProgram::setRegisteredUniform4f)
       // .def("setUniform1fv",&ShaderProgram::setUniform1fv)
       // .def("setUniform2fv",&ShaderProgram::setUniform2fv)
       // .def("setUniform3fv",&ShaderProgram::setUniform3fv)
       // .def("setUniform4fv",&ShaderProgram::setUniform4fv)
       // .def("setUniform1i",&ShaderProgram::setUniform1i)
        .def("setRegisteredUniform1i",&ShaderProgram::setRegisteredUniform1i)
        .def("setRegisteredUniform2i",&ShaderProgram::setRegisteredUniform2i)
        .def("setRegisteredUniform3i",&ShaderProgram::setRegisteredUniform3i)
        .def("setRegisteredUniform4i",&ShaderProgram::setRegisteredUniform4i)
      //  .def("setUniform2i",&ShaderProgram::setUniform2i)
      //  .def("setUniform3i",&ShaderProgram::setUniform3i)
      //  .def("setUniform4i",&ShaderProgram::setUniform4i)
      //  .def("setUniform1iv",&ShaderProgram::setUniform1iv)
      //  .def("setUniform2iv",&ShaderProgram::setUniform2iv)
      //  .def("setUniform3iv",&ShaderProgram::setUniform3iv)
      //  .def("setUniform4iv",&ShaderProgram::setUniform4iv)
      //  .def("setUniformMatrix2fv",&ShaderProgram::setUniformMatrix2fv)
      //  .def("setUniformMatrix3fv",&ShaderProgram::setUniformMatrix3fv)
        .def("setRegisteredUniformMatrix3fv",&ShaderProgram::setRegisteredUniformMatrix3fv)
     //   .def("setUniformMatrix4fv",&ShaderProgram::setUniformMatrix4fv)
        .def("setRegisteredUniformMatrix4fv",&ShaderProgram::setRegisteredUniformMatrix4fv)
    //    .def("setUniformMatrix2x3fv",&ShaderProgram::setUniformMatrix2x3fv)
    //    .def("setUniformMatrix2x4fv",&ShaderProgram::setUniformMatrix2x4fv)
    //    .def("setUniformMatrix3x2fv",&ShaderProgram::setUniformMatrix3x2fv)
    //    .def("setUniformMatrix3x4fv",&ShaderProgram::setUniformMatrix3x4fv)
    //    .def("setUniformMatrix4x2fv",&ShaderProgram::setUniformMatrix4x2fv)
    //    .def("setUniformMatrix4x3fv",&ShaderProgram::setUniformMatrix4x3fv)
        .def("getUniformfv",&ShaderProgram::getUniformfv)
        .def("getUniformiv",&ShaderProgram::getUniformiv)
        .def("enableAttribArray",&ShaderProgram::enableAttribArray)
        .def("disableAttribArray",&ShaderProgram::disableAttribArray)
        .def("autoRegisterUniforms",&ShaderProgram::autoRegisterUniforms)
        .def("printRegisteredUniforms",&ShaderProgram::printRegisteredUniforms)
        .def("bindFragDataLocation",(void(ShaderProgram::*)(GLuint,const char *))&ShaderProgram::bindFragDataLocation)
        .def("getUniformBlockIndex",&ShaderProgram::getUniformBlockIndex)
        ;

  }


}
