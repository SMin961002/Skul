#pragma once
#include "Head.h" //94,64 BasicAttack_BasicSkul범위 x-30~x+42(중심점 x+6, 범위반지름 36). y-56~y+8(중심점 y-24, 범위반지름 32)
#include "Enemy.h"
#include "ProjectileHeadSkull.h"
class LittleBorn : public Head
{
private:
    vImage* img_headless[eActionTagNumber];
	ProjectileHeadSkull* m_projectileHead;	//머리던지기 투사체 구조체
    bool m_headThrow;
    bool m_attacksound;
    int count = 0;
    float m_tagAttackDelay;
    float m_tagAttackNowDelay;
public:
    void ImageSetting() override;
    void ParameterSetting() override;
    void CollisionSetting() override;

    void Release() override;

    void CoolDown() override;

    void ActionArrangement() override;
    void CollisionUpdate() override;

    void InputAttackKey() override;
    void InputSkillKey() override;

    void TagAction() override;
    virtual bool GetIsAttack()override;

    void DrawCharactor() override;
    void OnCollisionAutoAttack(Component* enemy, Object* obj, float dmg, float delay) override;
    void OnCollisionTagAttack(Component* enemy, Object* obj, float dmg, float delay) override;
	
	void SetReborn()
	{
		m_action = eReborn;
		nowImg = img[eReborn];
		nowImg->Setting(0, 10.0f);
		for (int i = 1; i < 15; i++)
		{
			nowImg->Setting(i, 0.15f);
		}
		for (int i = 15; i < 27; i++)
		{
			nowImg->Setting(i, 0.1f);
		}
		nowImg->Reset();

		m_nonCansleAction = true;
	}

	void PutOnHead()
	{
		m_headThrow = false;
		m_imageChange = true;
		m_skillNowCoolA = 0;
		m_projectileHead->Off();
	};
	virtual void ResetAll() override
	{
		Head::ResetAll();
		m_projectileHead->Off();
	}
};