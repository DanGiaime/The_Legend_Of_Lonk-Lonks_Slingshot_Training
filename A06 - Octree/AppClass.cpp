#include "AppClass.h"
using namespace Simplex;
void Application::InitVariables(void)
{
	//Set the position and target of the camera
	m_pCameraMngr->SetPositionTargetAndUpward(
		vector3(0.0f, 0.0f, 100.0f), //Position
		vector3(0.0f, 0.0f, 99.0f),	//Target
		AXIS_Y);					//Up

	m_pLightMngr->SetPosition(vector3(0.0f, 3.0f, 13.0f), 1); //set the position of first light (0 is reserved for ambient light)

#ifdef DEBUG
	uint uInstances = 900;
#else
	uint uInstances = 1849;
#endif
	crosshair = new Mesh();
	crosshair->GeneratePlane(.008f, C_WHITE);

	ground = new Mesh();
	ground->GeneratePlane(300, C_BROWN);

	int nSquare = static_cast<int>(std::sqrt(uInstances));
	m_uObjects = nSquare * nSquare;
	uint uIndex = -1;
	uIndex++;
	m_pEntityMngr->AddEntity("Legend Of Lonk\\Green Rupee.fbx");
	vector3 v3Position = vector3(0.0f, 0.0f, 85.0f);
	matrix4 m4Position = glm::translate(v3Position) * glm::rotate(IDENTITY_M4, glm::radians(90.0f), vector3(1.0f, 0.0f, 0.0f)) * glm::rotate(IDENTITY_M4, glm::radians(90.0f), vector3(0.0f, 0.0f, 1.0f));
	m_pEntityMngr->SetModelMatrix(m4Position);

	uIndex++;
	m_pEntityMngr->AddEntity("Legend Of Lonk\\Blue Rupee.fbx");
	v3Position = vector3(8.0f, 0.0f, 80.0f);
	m4Position = glm::translate(v3Position) * glm::rotate(IDENTITY_M4, glm::radians(90.0f), vector3(1.0f, 0.0f, 0.0f)) * glm::rotate(IDENTITY_M4, glm::radians(90.0f), vector3(0.0f, 0.0f, 1.0f));
	m_pEntityMngr->SetModelMatrix(m4Position);

	uIndex++;
	m_pEntityMngr->AddEntity("Legend Of Lonk\\Blue Rupee.fbx");
	v3Position = vector3(-8.0f, 0.0f, 80.0f);
	m4Position = glm::translate(v3Position) * glm::rotate(IDENTITY_M4, glm::radians(90.0f), vector3(1.0f, 0.0f, 0.0f)) * glm::rotate(IDENTITY_M4, glm::radians(90.0f), vector3(0.0f, 0.0f, 1.0f));
	m_pEntityMngr->SetModelMatrix(m4Position);

	uIndex++;
	m_pEntityMngr->AddEntity("Legend Of Lonk\\Blue Rupee.fbx");
	v3Position = vector3(2.0f, 5.0f, 80.0f);
	m4Position = glm::translate(v3Position) * glm::rotate(IDENTITY_M4, glm::radians(90.0f), vector3(1.0f, 0.0f, 0.0f)) * glm::rotate(IDENTITY_M4, glm::radians(90.0f), vector3(0.0f, 0.0f, 1.0f));
	m_pEntityMngr->SetModelMatrix(m4Position);

	uIndex++;
	m_pEntityMngr->AddEntity("Legend Of Lonk\\Blue Rupee.fbx");
	v3Position = vector3(-2.0f, 5.0f, 80.0f);
	m4Position = glm::translate(v3Position) * glm::rotate(IDENTITY_M4, glm::radians(90.0f), vector3(1.0f, 0.0f, 0.0f)) * glm::rotate(IDENTITY_M4, glm::radians(90.0f), vector3(0.0f, 0.0f, 1.0f));
	m_pEntityMngr->SetModelMatrix(m4Position);

	uIndex++;
	m_pEntityMngr->AddEntity("Legend Of Lonk\\Red Rupee.fbx");
	v3Position = vector3(8.0f, 8.0f, 70.0f);
	m4Position = glm::translate(v3Position) * glm::rotate(IDENTITY_M4, glm::radians(90.0f), vector3(1.0f, 0.0f, 0.0f)) * glm::rotate(IDENTITY_M4, glm::radians(90.0f), vector3(0.0f, 0.0f, 1.0f));
	m_pEntityMngr->SetModelMatrix(m4Position);

	uIndex++;
	m_pEntityMngr->AddEntity("Legend Of Lonk\\Red Rupee.fbx");
	v3Position = vector3(-8.0f, 8.0f, 70.0f);
	m4Position = glm::translate(v3Position) * glm::rotate(IDENTITY_M4, glm::radians(90.0f), vector3(1.0f, 0.0f, 0.0f)) * glm::rotate(IDENTITY_M4, glm::radians(90.0f), vector3(0.0f, 0.0f, 1.0f));
	m_pEntityMngr->SetModelMatrix(m4Position);

	uIndex++;
	m_pEntityMngr->AddEntity("Legend Of Lonk\\Purple Rupee.fbx");
	v3Position = vector3(0.0f, 16.0f, 60.0f);
	m4Position = glm::translate(v3Position) * glm::rotate(IDENTITY_M4, glm::radians(90.0f), vector3(1.0f, 0.0f, 0.0f)) * glm::rotate(IDENTITY_M4, glm::radians(90.0f), vector3(0.0f, 0.0f, 1.0f));
	m_pEntityMngr->SetModelMatrix(m4Position);

	/*
	for (int i = 0; i < nSquare; i++)
	{
		for (int j = 0; j < nSquare; j++)
		{
			uIndex++;
			m_pEntityMngr->AddEntity("Minecraft\\Cube.obj");
			vector3 v3Position = vector3(glm::sphericalRand(34.0f));
			matrix4 m4Position = glm::translate(v3Position);
			m_pEntityMngr->SetModelMatrix(m4Position);
		}
	}*/
	m_uOctantLevels = 1;
	m_pRoot = new MyOctant(m_uOctantLevels, 5);
	m_pEntityMngr->Update();
}
void Application::Update(void)
{
	//Update the system so it knows how much time has passed since the last call
	m_pSystem->Update();

	//Is the ArcBall active?
	ArcBall();

	//Is the first person camera active?
	CameraRotation();
	
	//Assign IDs to the dynamic entities
	m_pRoot->AssignIDtoOutEntity();

	//Update Entity Manager
	m_pEntityMngr->Update();
	MyDynamicEntityManager::GetInstance()->Update();

	//Add objects to render list
	m_pEntityMngr->AddEntityToRenderList(-1, true);
	MyDynamicEntityManager::GetInstance()->AddEntityToRenderList(-1, true);
}
void Application::Display(void)
{
	// Clear the screen
	ClearScreen();

	//display octree
	if (m_uOctantID == -1)
		m_pRoot->Display();
	else
		m_pRoot->Display(m_uOctantID);

	//render cursor on camera plane
	matrix4 cameraPlane = m_pCameraMngr->GetCameraPlane();
	cameraPlane = glm::scale(cameraPlane, vector3(9.0f/16.0f, 1, 1)); //divide the matrix by the aspect ratio to fix scaling on the x-axis
	crosshair->Render(m_pCameraMngr->GetProjectionMatrix(), m_pCameraMngr->GetViewMatrix(), cameraPlane);

	//render ground
	matrix4 m4Position = glm::rotate(glm::translate(vector3(0, -5, 0)), glm::radians(-90.0f), AXIS_X);
	ground->Render(m_pCameraMngr->GetProjectionMatrix(), m_pCameraMngr->GetViewMatrix(), m4Position);
	
	// draw a skybox
	m_pMeshMngr->AddSkyboxToRenderList();
	
	//render list call
	m_uRenderCallCount = m_pMeshMngr->Render();

	//clear the render list
	m_pMeshMngr->ClearRenderList();
	
	//draw gui,
	DrawGUI();
	
	//end the current frame (internally swaps the front and back buffers)
	m_pWindow->display();
}
void Application::Release(void)
{
	SafeDelete(m_pRoot);
	//release GUI
	ShutdownGUI();
}