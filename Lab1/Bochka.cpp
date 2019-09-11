#include "Bochka.h"

Bochka::Bochka()
{
	c_water = 0;
	c_spirt = 0;
}

Bochka::Bochka(double water, double spirt)
{
	if (water < 0) c_water = 0;
	else c_water = water;

	if (spirt < 0) c_spirt = 0;
	else c_spirt = spirt;
}

Bochka::Bochka(const Bochka &B)
{
	c_water = B.c_water;
	c_spirt = B.c_spirt;
}

void Bochka::SetAll(double water, double spirt)
{
	if (water < 0) c_water = 0;
	else c_water = water;

	if (spirt < 0) c_spirt = 0;
	else c_spirt = spirt;
}

void Bochka::Print() const
{
	std::cout<<"Water = "<<c_water<<std::endl;
	std::cout << "Spirt = " << c_spirt << std::endl;
}

double Bochka::ProcentSpirt() const
{
	if ((c_spirt + c_water) == 0) return 0;
	double procent_spirta = (c_spirt / (c_spirt + c_water)) * 100;
	return procent_spirta;
}

void Bochka::Pereliv(Bochka &B, double v_krugka)
{
	if (v_krugka < 0) v_krugka = 1;
	double spirt_krugka = (B.c_spirt/(B.c_spirt+B.c_water))*v_krugka;
	double water_krugka = (B.c_water/(B.c_spirt + B.c_water))*v_krugka;
	B.c_spirt -= spirt_krugka;
	B.c_water -= water_krugka;
	c_spirt += spirt_krugka;
	c_water += water_krugka;
}