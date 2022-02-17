#include "GameEntity.h"

GameEntity::GameEntity(std::shared_ptr<Mesh> mesh, std::unique_ptr<Transform> transform) : mesh(mesh), transform(std::move(transform))
{
}
