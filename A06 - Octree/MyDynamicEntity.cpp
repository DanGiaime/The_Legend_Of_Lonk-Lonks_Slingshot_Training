#include "MyDynamicEntity.h"
#include "MyDynamicEntityManager.h"


Simplex::MyDynamicEntity::MyDynamicEntity(vector3 a_v3Velocity, vector3 a_v3Position, quaternion a_qRotation, String a_sFileName, String a_sUniqueID) : MyEntity(a_sFileName, a_sUniqueID)
{
	m_v3Velocity = a_v3Velocity;
	m_v3Position = a_v3Position;
	m_qRotation = a_qRotation;
}

void Simplex::MyDynamicEntity::Update() {
	matrix4 modelMatrix = this->GetModelMatrix();
	vector3 v3Position = vector3(0.0f, 16.0f, 60.0f);
	matrix4 m4Position = glm::translate(v3Position) * glm::rotate(IDENTITY_M4, glm::radians(90.0f), vector3(1.0f, 0.0f, 0.0f)) * glm::rotate(IDENTITY_M4, glm::radians(90.0f), vector3(0.0f, 0.0f, 1.0f));
	MyDynamicEntityManager::GetInstance()->SetModelMatrix(m4Position);

	//modelMatrix += m_v3Velocity;
	this->SetModelMatrix(modelMatrix);
}

Simplex::MyDynamicEntity::~MyDynamicEntity()
{
}
