#pragma once

#include <vector>
#include <string>
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

#include "./Mesh.h"

class Model
{
protected:
    Model() { };

public:
    /*
    * @brief Loads a model from a supplied model file
    * 
    * @param path - path to the location of the model files
    * @param obj_file_name - name of the main object file
    */
    Model(std::string path, std::string obj_file_name) : path(path)
    {
        loadModel(path + obj_file_name);
    }
    void Render(Shader& shader);
protected:
    std::string path;

    std::vector<Mesh> meshes;
    std::string directory;
    // Store the allready loaded textures
    std::vector<Texture> textures_loaded;

    void loadModel(std::string path);
    void processNode(aiNode* node, const aiScene* scene);
    Mesh processMesh(aiMesh* mesh, const aiScene* scene);
    std::vector<Texture> loadMaterialTextures(aiMaterial* mat, aiTextureType type, string typeName);
};