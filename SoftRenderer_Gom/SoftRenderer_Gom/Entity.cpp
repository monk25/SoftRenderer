#include "pch.h"
#include "Entity.h"


Entity::Entity()
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
	static Matrix3x3 MatrixT, MatrixR, MatrixS;
	if (!visible) return;
	

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
