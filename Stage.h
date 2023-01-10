#pragma once
#include "Scene.h"
#include "Trigger.h"
class Stage : public Scene
{
	private:
		Trigger* trigger;
		CImage* m_backGround;
		CImage* m_backGround2;
		CImage* m_backGround3;
		CImage* m_backGround4;
		CImage* m_backGround5;
		CImage* m_backGround6;
		CImage* m_backGround7;
		CImage* m_backGround8;
		CImage* m_cloude;
		CImage* m_cloude2;
		CImage* m_cloude3;
		CImage* m_cloude4;
		CImage* m_ChandelierBack;
		CImage* m_ChandelierBack2;
		CImage* m_castle;
		CImage* m_castle2;
		CImage* m_Demoncastle;
		CImage* m_moon;
		bool isFade;
		bool isStart = false;
		float m_speed;
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



