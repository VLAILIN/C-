#pragma once
class MyString
{
    char* m_pStr;	//строка-член класса
public:
	MyString(); //конструктор по умолчанию
	MyString(const char*); //конструктор с параметром
	MyString(const MyString &obj); // конструктор копирования
	MyString(MyString&&); //move конструктор копирования
	const char* GetString() const; // метод получения строки
	void SetNewString(const char*); //метод замены строки на новую
	~MyString();//деструктор класса
};

MyString Сoncat_str(const char *, ...);
