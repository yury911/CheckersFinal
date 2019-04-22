// Checkers.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.


#include "pch.h"
#include <iostream>
#include <string>

std::string Horizontal[8] = {
	"a","b","c","d","e","f","g","h"
};

int Vertical[8] = {
	1,2,3,4,5,6,7,8
};

class Checker {
public:
	Checker(std::string initalH, int initialV, std::string initialC);
	std::string GetColor() const;
	std::string GetHCor() const;
	int GetVCor() const;
private:
	std::string HCoordinate;
	int VCoordinate;
	std::string Color;
	bool ItsMegaFigure = false;
};

Checker **pChecker = new Checker*[24];

void initialWhiteFigure();
void initialBlackFigure();

int main()
{
	initialWhiteFigure();
	initialBlackFigure();

	for (int i = 1; i < 25; i++) {
		std::cout << i << " figure is " << ' ' << pChecker[i]->GetColor() << ' ' << pChecker[i]->GetVCor() << pChecker[i]->GetHCor() << '\n';
	}
}


Checker::Checker(std::string initalH, int initialV, std::string initialC) {
	HCoordinate = initalH;
	VCoordinate = initialV;
	Color = initialC;
};

void initialWhiteFigure() {
	int g,k = 1;
	while (k != 13) {

		for (int i = 1; i < 4; i++) {
			if (i % 2 != 0)
				g = 0;
			else
				g = 1;

			for (int j = 1; j < 5; j++) {

				if (i % 2 != 0)
				{
					Checker* pCheckerWhite = new Checker(Horizontal[g], i, "White");
					pChecker[k] = pCheckerWhite;
					k = k + 1;
					g += 2;
				}
				else
				{
					Checker* pCheckerWhite = new Checker(Horizontal[g], i, "White");
					pChecker[k] = pCheckerWhite;
					k = k + 1;
					g += 2;
				};
			};
		};

	};

};

void initialBlackFigure() {
	int g,k = 13;
	while (k != 25) {

		for (int i = 6; i < 9; i++) {
			if (i % 2 != 0)
				g = 0;
			else
				g = 1;

			for (int j = 1; j < 5; j++) {

				if (i % 2 != 0)
				{
					Checker* pCheckerBlack = new Checker(Horizontal[g], i, "White");
					pChecker[k] = pCheckerBlack;
					k = k + 1;
					g += 2;
				}
				else
				{
					Checker* pCheckerBlack = new Checker(Horizontal[g], i, "White");
					pChecker[k] = pCheckerBlack;
					k = k + 1;
					g += 2;
				};
			};
		};

	};

};

std::string Checker::GetColor() const {
	return Color;
};

std::string Checker::GetHCor() const {
	return HCoordinate;
};

int Checker::GetVCor() const {
	return VCoordinate;
};