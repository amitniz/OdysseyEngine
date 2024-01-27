#pragma once

#include <iostream>
#include <vector>
#include <GL/glew.h>
#include <glm/mat4x4.hpp>

// --------------------------------- Shader -----------------------------------

class Shader {
public:
  ~Shader();


  /**
   * @brief 
   * create a shader from a shader file
   * @param[in] path to shader file
   * @return a pointer to the instance
   */
  Shader* from_file(const std::string& path);

  /**
   * @brief 
   * compile the shader
   */
  void compile(void);

  /**
   * @brief 
   * getter to the shader id
   * @return the shader id
   */
  inline unsigned int id() const {return this->m_id;}

  /**
   * @brief 
   * getter to the shader source code
   * @return the shader source code
   */
  inline const std::string& code() const {return this->m_code;}

private:
  std::string m_code;
  unsigned int m_id;

protected:
  inline Shader(): m_code(),m_id(0){}
  unsigned int type;
};

class VertexShader : public Shader {
public:
  inline VertexShader(): Shader(){this->type = GL_VERTEX_SHADER;}
};
class FragmentShader : public Shader {
public:
  inline FragmentShader(): Shader(){this->type =GL_FRAGMENT_SHADER;}
};


// ------------------------------ ShaderProgram -------------------------------
class ShaderProgram{
public:
  ShaderProgram();

  ShaderProgram* add_shader(Shader* shader);


  /**
   * @brief 
   * compiles and links shaders and use the shader program
   */
  void use(void);

  /**
   * @brief 
   * getter to the program id
   * @return the program id
   */
  inline unsigned int id() const{return this->m_id;}

  /**
   * @brief 
   * getter to the model uniform
   * @return the model uniform
   */
  inline int get_model() const{ return glGetUniformLocation(this->m_id, "u_model"); }

  ShaderProgram* reset_model();
  ShaderProgram* scale(float x, float y, float z);
  ShaderProgram* translate(float x, float y, float z);

private:
  ShaderProgram* link_shaders(void);
  ShaderProgram* compile_shaders(void);

  unsigned int m_id;
  std::vector<Shader*> m_shaders;  
  bool compiled_and_linked;
  glm::mat4 m_model;
};
