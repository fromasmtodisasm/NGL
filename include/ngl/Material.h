/*
  Copyright (C) 2009 Jon Macey

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef MATERIAL_H_
#define MATERIAL_H_
// must include types.h first for Real and GLEW if required
#include "Types.h"
#include "Vec4.h"
#include <string>

/// @file Material.h
/// @brief a simple Ambient Diffuse, Specular type GL material this will fill in the
/// following glsl shader structure when a shader is passed
/// @verbatim
/// struct Material
/// {
///  vec4 ambient;
///  vec4 diffuse;
///  vec4 specular;
///  float shininess;
/// };


namespace ngl
{
//----------------------------------------------------------------------------------------------------------------------
/// @class Material "include/Material.h"
/// @brief a simple OpenGL material class and set the parameters
/// @author Jonathan Macey
/// @version 5.0
/// @date 18/08/11 removed deprecated GL stuff and added new structures for glsl
/// Last Revision 29/10/09 Updated to meet NCCA coding standard
/// @todo add better file read and write support and make it support mtl file format used with obj files
/// @todo add GL_FRONT, GL_BACK and GL_FRONT_AND_BACK support as part of the  ctor
/// @example Materials/Material.cpp
//----------------------------------------------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------------------------------------
/// @enum used to give offset into materials array for some standard matertial values
/// the actual values are taken from the Hill Book
//----------------------------------------------------------------------------------------------------------------------

enum class STDMAT : int { BLACKPLASTIC,BRASS,BRONZE,CHROME,COPPER,GOLD,PEWTER,SILVER,POLISHEDSILVER};

//----------------------------------------------------------------------------------------------------------------------
/// @brief material values for some standard material values taken from the Hill Book
//----------------------------------------------------------------------------------------------------------------------
const static Real s_materials [9][10]=
  {
    { 0.0f,0.0f,0.0f,0.01f,0.01f,0.01f,0.50f,0.50f,0.50f,32.0f}, //Black plastic
    { 0.329412f,0.223529f,0.027451f,0.780392f,0.568627f,0.113725f,0.992157f,
      0.941176f,0.807843f,27.8974f}, //Brass
    { 0.2125f,0.1275f,0.054f,0.714f,0.4284f,0.18144f,0.393548f,0.271906f,
      0.166721f,25.6f}, // Bronze
    { 0.25f,0.25f,0.25f,0.4f,0.4f,0.4f,0.774597f,0.774597f,0.774597f,76.8f}, //Chrome
    { 0.19125f,0.0735f,0.0225f,0.7038f,0.27048f,0.0828f,0.256777f,0.137622f,
      0.086014f,12.8f}, // Copper
    { 0.274725f,0.1995f,0.0745f,0.75164f,0.60648f,0.22648f,0.628281f,
      0.555802f,0.3666065f,51.2f}, // Gold
    { 0.10588f,0.058824f,0.113725f,0.427451f,0.470588f,0.541176f,
      0.3333f,0.3333f,0.521569f,9.84615f}, // Pewter
    { 0.19225f,0.19225f,0.19225f,0.50754f,0.50754f,0.50754f,0.508273f,
      0.508273f,0.508273f,51.2f}, // Silver
    { 0.23125f,0.23125f,0.23125f,0.2775f,0.2775f,0.2775f,0.77391f,
      0.77391f,0.77391f,89.6f} // PolishedSilver
  };
//----------------------------------------------------------------------------------------------------------------------


class NGL_DLLEXPORT Material
{
public :

  //----------------------------------------------------------------------------------------------------------------------
  /// @brief set the default material properties
  //----------------------------------------------------------------------------------------------------------------------
  void setDefault() noexcept;
  //----------------------------------------------------------------------------------------------------------------------
  ///  @brief set the material properties based on another matherial
  ///  @param[in]  _m the material to use
  //----------------------------------------------------------------------------------------------------------------------
  void set( const Material &_m ) noexcept;

  //----------------------------------------------------------------------------------------------------------------------
  /// @brief change the material to one of the standard materials
  /// @param[in] _mat the material to use
  //----------------------------------------------------------------------------------------------------------------------
  void change( const STDMAT _mat ) noexcept;
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief Constructor for material
  /// @param[in]  _amb the ambient Vec4
  /// @param[in]  _dif the diffuse Vec4
  /// @param[in]  _spec the specular Vec4
  /// @param[in]  _emis the emimissive Vec4
  //----------------------------------------------------------------------------------------------------------------------
  Material( Vec4 _amb=0.0f,  Vec4 _dif=0.5f, Vec4 _spec=1.0f )  noexcept:
            m_ambient(_amb),
            m_diffuse(_dif),
            m_specular(_spec)
            {;}

  //----------------------------------------------------------------------------------------------------------------------
  /// @brief Constructor using a STDMAT for the coulour
  /// @param[in]  _mat the standard material to set
  //----------------------------------------------------------------------------------------------------------------------
  Material(STDMAT _mat) noexcept;

  //----------------------------------------------------------------------------------------------------------------------
  /// @brief Constructor using an index into the default Vec4 array from sdtmat for the coulour
  /// @param[in] _mat the  index
  //----------------------------------------------------------------------------------------------------------------------
  Material( int _mat ) noexcept;

  //----------------------------------------------------------------------------------------------------------------------
  /// @brief ctor to load material from a file, need implimenting properly
  /// @param[in] _fName the name of the file to load the material from
  //----------------------------------------------------------------------------------------------------------------------
  Material( const std::string &_fName ) noexcept;
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief load a material from a file needs work
  /// @param[in] _fName  the name of the file to load
  //----------------------------------------------------------------------------------------------------------------------
  void load(  const std::string &_fName  ) noexcept;
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief mutator to set the Ambient Vec4 value
  /// @param[in] _c  Vec4 values to be set
  //----------------------------------------------------------------------------------------------------------------------
  void setAmbient(const Vec4 &_c) noexcept{ m_ambient = _c;}
  Vec4 getAmbient() const noexcept {return m_ambient;}
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief mutator to set the Diffuse Vec4 value
  /// @param[in] _c  Vec4 values to be set
  //----------------------------------------------------------------------------------------------------------------------
  void setDiffuse(const Vec4 &_c) noexcept{ m_diffuse = _c;}
  Vec4 getDiffuse() const noexcept {return m_diffuse;}
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief mutator to set the Specular Vec4 value
  /// @param[in] _c  Vec4 values to be set
  //----------------------------------------------------------------------------------------------------------------------
  void setSpecular(const Vec4 &_c) noexcept{ m_specular = _c;}
  Vec4 getSpecular() const  noexcept{return m_specular;}
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief mutator to set the specular exponent Vec4 value
  /// @param[in] _s  specular exponent value smaller = larger highlights
  //----------------------------------------------------------------------------------------------------------------------
  void setSpecularExponent(Real _s) noexcept{ m_specularExponent=_s;}
  Real getSpecularExponent()const  noexcept{ return m_specularExponent;}

  Real getTransparency()const  noexcept{ return m_transparency;}

  //----------------------------------------------------------------------------------------------------------------------
  /// @brief mutator to set the surface roughness, will effect the spread in shading
  /// @param[in] _r  value to set
  //----------------------------------------------------------------------------------------------------------------------
  void setRoughness(Real _r) noexcept{m_surfaceRoughness=_r;}
  Real getRoughness()const  noexcept{return m_surfaceRoughness;}

  //----------------------------------------------------------------------------------------------------------------------
  /// @brief load the material values to the currently active shader passed this will set the following glsl shader parameters
  /// struct Material
  /// {
  ///  vec4 ambient;
  ///  vec4 diffuse;
  ///  vec4 specular;
  ///  float shininess;
  /// };
  /// @param[in] _uniformName
  //----------------------------------------------------------------------------------------------------------------------
  void loadToShader( std::string _uniformName )const noexcept;

protected :
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief ambient component of the material
  //----------------------------------------------------------------------------------------------------------------------
  Vec4 m_ambient;
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief diffuse component of the material
  //----------------------------------------------------------------------------------------------------------------------
  Vec4 m_diffuse;
  //----------------------------------------------------------------------------------------------------------------------
  ///  @brief specular component of the material
  //----------------------------------------------------------------------------------------------------------------------
  Vec4 m_specular;
  //----------------------------------------------------------------------------------------------------------------------
  /// @brief specular exponent used for OpenGL material
  //----------------------------------------------------------------------------------------------------------------------
  Real m_specularExponent;
  //----------------------------------------------------------------------------------------------------------------------
  ///  @brief used for setting alpha values
  //----------------------------------------------------------------------------------------------------------------------
  Real m_transparency;
  //----------------------------------------------------------------------------------------------------------------------
  ///  @brief roughness used for specular spread
  //----------------------------------------------------------------------------------------------------------------------
  Real m_surfaceRoughness;

}; // end of Material


}

#endif // MATERIAL
//----------------------------------------------------------------------------------------------------------------------

