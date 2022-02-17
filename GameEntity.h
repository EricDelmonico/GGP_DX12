#pragma once

#include "Mesh.h"
#include "Transform.h"
#include <memory>

class GameEntity
{
public:
    GameEntity(std::shared_ptr<Mesh> mesh, std::unique_ptr<Transform> transform);
    ~GameEntity() {}

    Mesh* GetMesh() { return mesh.get(); }
    Transform* GetTransform() { return transform.get(); }

private:
    std::shared_ptr<Mesh> mesh;
    std::unique_ptr<Transform> transform;
};