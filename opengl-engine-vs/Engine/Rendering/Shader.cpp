#include "Shader.h"

#include "../../Logging/Log.h"

#include <string>
#include <fstream>
#include <iostream>

/**
 * @brief Construct a new Shader:: Shader object
 *
 * @param vertexPath - path to the vertex shader file
 * @param fragmentPath - path to the fragment shader file
 */
Shader::Shader(const char* vertexPath, const char* fragmentPath)
{
    // Keep track of the shader name for debuging
    path = (char*)vertexPath;

    if (!compileShader(vertexPath, GL_VERTEX_SHADER))       return;
    if (!compileShader(fragmentPath, GL_FRAGMENT_SHADER))   return;

    // Shader program
    id = glCreateProgram();
    // Attach shaders
    for (std::vector<GLuint>::iterator it = shaderIds.begin(); it != shaderIds.end(); ++it)
    {
        glAttachShader(id, *it);
    }
    glLinkProgram(id); // link

    // check for errors
    GLint success;
    char infoLog[512];
    glGetProgramiv(id, GL_LINK_STATUS, &success);
    if (!success)
    {
        glGetProgramInfoLog(id, 512, NULL, infoLog);
        gl_log_error(infoLog);
    }

    cleanUp();
}

/**
 * @brief Compiles the shader from the given path
 *
 * @param path - location of the shader file
 * @param type - type of the shader
 * @return true on successfull compilation and false otherwise
 */
bool Shader::compileShader(const char* path, GLuint type)
{
    // Create shader
    GLuint shaderId = glCreateShader(type);

    // Get code from file
    std::string source = readFromFile(path);
    const char* cSource = source.c_str();
    glShaderSource(shaderId, 1, &cSource, NULL); // give code
    glCompileShader(shaderId); // compile

    // check for errors
    GLint success;
    char infoLog[512];
    glGetShaderiv(shaderId, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        std::string typeString = (type == GL_VERTEX_SHADER ? "vertex" : "fragment");
        glGetShaderInfoLog(shaderId, 512, NULL, infoLog);
        gl_log_error("Error from %s shader", typeString.c_str());
        gl_log_error(infoLog);
        cleanUp();
        return false;
    }

    shaderIds.push_back(shaderId);
    return true;
}

// TODO extract this function to an external file for general purpouse usage
std::string Shader::readFromFile(const char* path)
{
    std::ifstream file(path);
    std::string src;
    std::string line;

    while (std::getline(file, line))
    {
        src += line + "\n";
    }
    return src;
}

/**
 * @brief Returns the location of the uniform variable.
 * Checks if the uniform location is stored in memory, if not it searches for it and
 * stores it for furthure use.
 * @param uniformName Name of the uniform variable
 * @return Uniform location
 */
int Shader::getUniformLocation(const char* uniformName)
{
    std::map<const char*, int>::iterator it = uniforms.find(uniformName);
    if (it != uniforms.end())
    {
        return it->second;
    }
    else
    {
        GLint location = glGetUniformLocation(id, uniformName);
        if (location == -1)
        {
            gl_log_error("Uniform error '%s': '%s' is not a valid uniform name", path, uniformName);
            return -1;
        }
        // If found, put it in the map
        uniforms.insert(std::pair<const char*, int>(uniformName, location));
        return location;
    }
}

void Shader::setInt(const char* uniformName, int v0)
{
    GLint location = getUniformLocation(uniformName);

    if (location == -1) return;
    bind();
    glUniform1i(location, v0);
}

void Shader::setFloat(const char* uniformName, GLfloat v0)
{
    GLint location = getUniformLocation(uniformName);

    if (location == -1) return;
    bind();
    glUniform1f(location, v0);
}

void Shader::setVector3f(const char* uniformName, glm::vec3 vec)
{
    setVector3f(uniformName, vec.x, vec.y, vec.z);
}

void Shader::setVector3f(const char* uniformName, float v0, float v1, float v2)
{
    GLint location = getUniformLocation(uniformName);

    if (location == -1) return;
    bind();
    glUniform3f(location, v0, v1, v2);
}

void Shader::setVector4f(const char* uniformName, glm::vec4 vec)
{
    setVector4f(uniformName, vec.x, vec.y, vec.z, vec.w);
}

void Shader::setVector4f(const char* uniformName, float v0, float v1, float v2, float v3)
{
    GLint location = getUniformLocation(uniformName);

    if (location == -1) return;
    bind();
    glUniform4f(location, v0, v1, v2, v3);
}

void Shader::setMatrix4f(const char* uniformName, glm::mat4 mat)
{
    GLint location = getUniformLocation(uniformName);

    if (location == -1) return;
    bind();
    glUniformMatrix4fv(location, 1, GL_FALSE, glm::value_ptr(mat));
}

void Shader::cleanUp()
{
    for (std::vector<GLuint>::iterator it = shaderIds.begin(); it != shaderIds.end(); ++it)
    {
        glDeleteShader(*it);
    }
}