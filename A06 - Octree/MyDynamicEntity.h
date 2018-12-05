#pragma once
#include "MyEntity.h"

namespace Simplex {
	class MyDynamicEntity :
		public MyEntity
	{
	private:
		vector3 m_v3Velocity;
	public:
		MyDynamicEntity(vector3 a_v3Velocity, String a_sFileName, String a_sUniqueID = "NA");
		void Update();
		~MyDynamicEntity();
	};
}

