#pragma once

#include "Mesh.h"
#include "Transform.h"
#include <memory>

class GameEntity
{
public:
    Mesh* GetMesh() { return mesh.get(); }
    Transform* GetTransform() { return transform.get(); }

private:
    std::unique_ptr<Mesh> mesh;
    std::unique_ptr<Transform> transform;
};