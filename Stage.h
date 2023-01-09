#pragma once
#include "Scene.h"
#include "Trigger.h"
class Stage : public Scene
{
	private:
		Trigger* trigger;
		bool isStart = false;
		CImage* m_backGround;
		CImage* m_cloude;
		CImage* m_cloude2;
		float m_speed;
		CImage* m_castle;
		CImage* m_moon;
		vector<StructureData*> m_sturctDatas;
		vector<StructureData*> m_objectDatas;
	public:
		Stage() {}
		~Stage() {}
		// Scene을(를) 통해 상속됨
		virtual void Init() override;
		virtual void Update() override;
		virtual void Render() override;
		virtual void Release() override;
		virtual void UIRender() override;
	};



