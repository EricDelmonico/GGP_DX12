#pragma once

#include "Mesh.h"
#include "Transform.h"
#include "Material.h"
#include <memory>

class GameEntity
{
public:
    GameEntity(std::shared_ptr<Mesh> mesh, std::unique_ptr<Transform> transform);
    ~GameEntity() {}

    Mesh* GetMesh() { return mesh.get(); }
    Transform* GetTransform() { return transform.get(); }
    Material* GetMaterial() { return material.get(); }

    void SetMaterial(std::shared_ptr<Material> material) { this->material = material; }

private:
    std::shared_ptr<Mesh> mesh;
    std::unique_ptr<Transform> transform;
    std::shared_ptr<Material> material;
};