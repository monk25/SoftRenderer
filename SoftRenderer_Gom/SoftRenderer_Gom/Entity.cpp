#include "pch.h"
#include "Entity.h"


Entity::Entity() :
	parent{ nullptr },
	position{ 0.0f, 0.0f },
	scale{ 1.0f, 1.0f },
	rotation{ 0.0f },
	matrix{},
	visible{ true },
	removing{ false }
{
}


Entity::~Entity()
{
	for (auto* child : children)
		delete child;
}

void Entity::Update()
{
	for (auto* child : children)
		child->Update();

	children.erase(remove_if(
		children.begin(), children.end(),
		[](Entity* child) {
		if (child->removing) {
			delete child;
			return true;
		}
		return false;
	}), children.end());
}

void Entity::Render()
{
	static Matrix3x3 matrixT, matrixR, matrixS;
	if (!visible) return;
	
	MatrixIdentity(matrix);
	MatrixTranslation(matrixT, position.x, position.y);
	MatrixRotationDir(matrixR, rotation);
	MatrixScale(matrixS, scale.x, scale.y);
	matrix = matrixS * matrixR * matrixT;

	if (parent)
		matrix *= parent->matrix;

	for (auto* child : children)
		child->Render();
}

void Entity::AddChild(Entity * child)
{
	child->parent = this;
	children.push_back(child);
}

void Entity::Removing()
{
	removing = true;
}
