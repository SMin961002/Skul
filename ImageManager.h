#pragma once
#include "singleton.h"

class GImage
{
private:
public:
	enum IMAGE_LOAD_KIND
	{
		LOAD_RESOURCE = 0, LOAD_FILE,	//���ҽ��� �ε�, ���Ϸ� �ε�
		LOAD_EMPTY, LOAD_END		//�� ��Ʈ�� �ε�
	};

	typedef struct tagImage
	{
		DWORD		resID;			//���ҽ� ID
		HBITMAP		hBit;			//��Ʈ��
		HBITMAP		hOBit;			//�õ� ��Ʈ��
		int			width;			//�̹��� ����ũ��
		int			height;			//�̹��� ����ũ��
		BYTE		loadType;		//�̹��� �ε� Ÿ��
		HDC			hMemDC;
		tagImage()
		{
			resID = 0;
			hMemDC = nullptr;
			hBit = nullptr;
			hOBit = nullptr;
			width = 0;
			height = 0;
			loadType = LOAD_RESOURCE;
		}
	}IMAGE_INFO, * LPIMAGE_INFO;

private:
	char* _fileName;		//�̹��� �̸�
	bool			_isTrans;		//����
	COLORREF		_transColor;	//���� ���� RGB (RGB(255,0,255))

	BLENDFUNCTION _blendFunc;		//���� ���� ���
	LPIMAGE_INFO _blendImage;		//���� ���� �̹���

	LPIMAGE_INFO	_imageInfo;		//�̹��� ����

public:
	HRESULT init(const char* fileName, float width, float height);
	HDC GetMemDC() { return _imageInfo->hMemDC; }
	float GetWidth() { return _imageInfo->width; }
	float GetHight() { return _imageInfo->height; }
	void Release() { SAFE_DELETE(_imageInfo); }
};

class CImage
{
private:
	float alpha;
	int	  width;
	int	  height;
	float delay;
	ID2D1Bitmap* bitmap;
public:
	CImage(ID2D1Bitmap* bitmap, int width, int height) :
		bitmap(bitmap), width(width), height(height)
	{
	}

	~CImage()
	{
		bitmap->Release();
	}

	float GetAlpha() { return alpha; }
	int   GetWidth() { return width; }
	int   GetHeight() { return height; }
	float GetDelay() { return delay; }

	void SetAlpha(float a) { alpha = a; }
	void SetDelay(float t) { delay = t; }
	ID2D1Bitmap* GetBitMap() { return bitmap; }
};

class vImage;
class ImageManager : public Singleton<ImageManager>
{
private:
	struct sCamera
	{
		float x, y;
	};
	sCamera camera;

	std::map <string, CImage*> m_imageList;
	std::map <string, vImage*> m_vectorImageList;
	std::vector<CImage*> m_tileImages;
	std::map<string, CImage*> m_structureImages;
	std::map<string, GImage*> m_gimages;

	IWICImagingFactory* factory;
	ID2D1HwndRenderTarget* pRT = NULL;
	ID2D1Factory* pD2DFactory;
	IDWriteTextFormat* tf;
	ID2D1SolidColorBrush* m_brush;

	bool m_isViewCollision = false;

public:
	ImageManager();
	~ImageManager();
public:
	void Init();
	void LoadImages();
	void Render(CImage* img, float x, float y, float sizeX = 1, float sizeY = 1, float rot = 0);
	void CenterRender(CImage* img, float x, float y, float sizeX = 1, float sizeY = 1, float rot = 0, bool isReverse = false);

	void UIRender(CImage* img, float x, float y, float sizeX = 1, float sizeY = 1, float rot = 0);

	// CenterRender �� AlphaRender�� �߰��� ����
	ID2D1Bitmap* AddBitmap(std::wstring path, UINT* Width, UINT* Height);
	CImage* AddImage(const std::string key, std::wstring path);
	CImage* AddTileImage(std::wstring path);
	CImage* AddStructureImage(std::string key, std::wstring path);

	CImage* FindImage(const std::string key);

	vImage* AddImageVector(const std::string key, std::wstring path, int startIndex, int endIndex);
	vImage* FindImageVector(const std::string key);

	GImage* AddPixelmage(string strKey, const char* fileName, int width, int height);
	GImage* FindPixelImage(string strKey);

	void Begin() { pRT->BeginDraw(); }
	void End() { pRT->EndDraw(); }

	void DrawCircle(float x, float y, float width);
	void DrawRect(RECT rt);
	void DrawRectCenter(RECT rt, CImage* img);
	void DrawMapTile(vector<vector<int>> vec);
	void DrawMapStructureBack(vector<StructureData*> vec);
	void DrawMapStructureFoward(vector<StructureData*> vec);
	void DrawMapTilePixel(vector<vector<int>> vec);
	void DrawColorRender(CImage* img, float x, float y, float sizeX, float sizeY, float rot, bool isReverse, D2D1_COLOR_F colr);

	sCamera GetCameraPosition()
	{
		return camera;
	}

	void SetCameraPosition(float x, float y)
	{
		camera.x = x;
		camera.y = y;
	}

	void D2dTextOut(wstring str, float x, float y);

	vector<CImage*> GetTileImages()
	{
		return m_tileImages;
	}

	map<string, CImage*> GetStructureImages()
	{
		return m_structureImages;
	}

	void SetViewCollision(bool isView) { m_isViewCollision = isView; }
	bool GetViewCollision() { return m_isViewCollision; }
};

#define IMAGEMANAGER ImageManager::GetInstance()

class vImage // ���� �̹������ �� ���߿� Ÿ�̸� ���� ����� ���� ���� ����������
{
private:
	vector<CImage*> m_images;
	bool m_isEnd;
	float m_nowTimeDelay;

	float m_totalDelay;
	bool m_isLoop;
	int m_frame;
public:
	vImage() : m_isEnd(false) {}
	~vImage() {}
	bool IsImageEnded() { return m_isEnd; }	//�����
	vector<CImage*> GetImages() { return m_images; }
	int GetImageSize() { return m_images.size(); }
	float GetTotalDelay() { return m_totalDelay; }

	void Setting(float delayTime, bool isLoop)
	{
		vector<CImage*>::iterator iter;
		for (iter = m_images.begin(); iter != m_images.end(); iter++)
		{
			(*iter)->SetDelay(delayTime);
		}
		m_totalDelay = m_images.size() * delayTime;
		m_isLoop = isLoop;
		m_nowTimeDelay = 0;
		m_frame = 0;
	}

	//���Ϳ� �� CImage ���帶���� delay�� �����ϱ� ���� �Լ�
	//frame��° �̹��� delay�� delayTime���� ����
	void Setting(int frame, float delayTime)
	{
		m_totalDelay -= m_images[frame]->GetDelay();
		m_totalDelay += delayTime;
		m_images[frame]->SetDelay(delayTime);
		m_nowTimeDelay = 0;
		m_frame = 0;
	}

	void Reset()
	{
		m_nowTimeDelay = 0;
		m_frame = 0;
		m_isEnd = false;
	}

	void Render(float x, float y, float sizeX, float sizeY, float rot)
	{
		if (m_isEnd == false)
			m_nowTimeDelay += DELTA_TIME;

		if (m_nowTimeDelay >= m_images[m_frame]->GetDelay())
		{
			if (m_frame >= GetImageSize() - 1)
			{
				if (m_isLoop == true)
				{
					m_frame = 0;
				}
				else
				{
					m_isEnd = true;
				}
			}
			else
			{
				m_frame++;
			}
			m_nowTimeDelay = 0;
		}
		IMAGEMANAGER->Render(m_images[m_frame], x, y, sizeX, sizeY, rot);
	}

	void CenterRender(float x, float y, float sizeX, float sizeY, float rot, bool isReverse = false)
	{
		if (m_isEnd == false)
			m_nowTimeDelay += DELTA_TIME;

		if (m_nowTimeDelay >= m_images[m_frame]->GetDelay())
		{
			if (m_frame >= GetImageSize() - 1)
			{
				if (m_isLoop == true)
				{
					m_frame = 0;
				}
				else
				{
					m_isEnd = true;
				}
			}
			else
			{
				m_frame++;
			}
			m_nowTimeDelay = 0;
		}
		IMAGEMANAGER->CenterRender(m_images[m_frame], x, y, sizeX, sizeY, rot, isReverse);
	}

	void AddImage(CImage* image)
	{
		m_images.push_back(image);
	}
};
