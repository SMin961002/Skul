#include "stdafx.h"
#include "DivineImpact.h"
#include "Player.h"
void DivineImpact::Init()
{
	img = IMAGEMANAGER->AddImageVectorCopy("Phase2_DivineImpact_Effect");
	img->Setting(0.06, false);
	m_obj->x = OBJECTMANAGER->m_player->GetplayerX();
	m_obj->y = OBJECTMANAGER->m_player->GetplayerY();

}

void DivineImpact::Update()
{
	if (img->GetIsImageEnded() == true)
	{
		m_obj->ObjectDestroyed();
	}
}

void DivineImpact::Render()
{
	img->CenterRender(m_obj->x, m_obj->y, 1.5, 1.5, 0, 0);
}

void DivineImpact::Release()
{
}
