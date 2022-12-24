#pragma once
class LeftBottom
{
public:
	void TextO(HDC hdc) {
		SetTextAlign(hdc,TA_BOTTOM|TA_CENTER);
		char name[10] = "°­À¯Áø";
		for (int i = 0; i <=  WINSIZE_Y/40; i++)
		{
			TextOut(hdc, i * WINSIZE_X * 40 / (2 * WINSIZE_Y), WINSIZE_Y - (i - 1) * WINSIZE_Y / 50, name, strlen(name));
		}
		//SetTextAlign(hdc, TA_TOP | TA_LEFT);
	}
};

