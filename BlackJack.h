#pragma once

class BlackJackCard;
class BlackJack:public Component
{
private:
	vector<BlackJackCard*> m_vCards;
	vector<BlackJackCard*>::iterator m_iterCards;

	bool m_shotOn;
	float m_startDelay;		//ī�� �յ� ���� �ð�
	int m_success;
	float m_shotDelay;		//ī�� �������� �߻� ������
	float m_shotNowDelay;

	bool* m_isLeft;

public:
	virtual void Init() override;
	virtual void Update() override;
	virtual void Release() override {};
	virtual void Render() override{};
	void Setting(int success);
};

