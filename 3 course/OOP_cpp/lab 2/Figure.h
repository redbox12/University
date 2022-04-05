#pragma once
class Figure
{

	int c; // ����
	bool visible;//��������� �������������

	protected:
	int x, y; // ������� �����
	virtual void draw() const = 0; //������ ������

	public:
	Figure(int c, int x, int y);
	virtual ~Figure();
	void move(int dx, int dy); // �������� ������ �� (dx,dy) � ������ �������
	virtual void setBorderColor(int c); // ���������� ���� ������ � ������ �������
	int getBorderColor() const ; // �������� ����
	void setVisible(bool isVisible = true);    // ��������/�������� ������
	bool isVisible() const; // ������� ���������
	
	virtual void calcParams(float& perimeter, float& area) const = 0;
	// ��������� �������� � ������� ������
   



};

