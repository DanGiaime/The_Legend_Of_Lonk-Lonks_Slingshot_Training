#include "MyDynamicEntity.h"



Simplex::MyDynamicEntity::MyDynamicEntity(vector3 a_v3Velocity, String a_sFileName, String a_sUniqueID) : MyEntity(a_sFileName, a_sUniqueID)
{
	m_v3Velocity = a_v3Velocity;
}

void Simplex::MyDynamicEntity::Update() {
	matrix4 modelMatrix = this->GetModelMatrix();
	modelMatrix += m_v3Velocity;
	this->SetModelMatrix(modelMatrix);
}

Simplex::MyDynamicEntity::~MyDynamicEntity()
{
}
