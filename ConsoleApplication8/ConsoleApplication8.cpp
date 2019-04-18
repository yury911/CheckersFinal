#include "pch.h"
#include <iostream>
#include <string>

std::string Name1, Name2;

class Figure {
public:
	Figure(std::string initalHorizontal, int initialVertical, std::string initialColor);
	std::string GetColor();
	std::string GetHorizontalCor();
	int GetVerticalCor();
private:
	std::string HorizontalCor;
	int VerticalCor;
	std::string Color;
	bool ItsMegaFigure = false;
};

Figure **pFigure = new Figure*[24];

Figure::Figure(std::string initalHorizontal, int initialVertical, std::string initialColor) {
	HorizontalCor = initalHorizontal;
	VerticalCor = initialVertical;
	Color = initialColor;
};

std::string Figure::GetColor() {
	return Color;
};

std::string Figure::GetHorizontalCor() {
	return HorizontalCor;
};

int Figure::GetVerticalCor() {
	return VerticalCor;
};

int g, k;
std::string horizontal[8] = {
	"a","b","c","d","e","f","g","h"
};

int vertical[8] = {
	1,2,3,4,5,6,7,8
};

void initialWhiteFigure();
void initialBlackFigure();




int main()
{

	initialWhiteFigure();
	initialBlackFigure();


	for (int k = 1; k < 25; k++) {
		std::cout << k << '\t' << pFigure[k]->GetColor() << '\t' << pFigure[k]->GetHorizontalCor() << '\t' << pFigure[k]->GetVerticalCor() << '\n';
	};



}


void initialWhiteFigure() {
	k = 1;
	while (k != 13) {

		for (int i = 1; i < 4; i++) {
			if (i % 2 != 0)
				g = 0;
			else
				g = 1;

			for (int j = 1; j < 5; j++) {

				if (i % 2 != 0)
				{
					Figure* pFigureWhite = new Figure(horizontal[g], i, "White");
					pFigure[k] = pFigureWhite;
					k = k + 1;
					g += 2;
				}
				else
				{
					Figure* pFigureWhite = new Figure(horizontal[g], i, "White");
					pFigure[k] = pFigureWhite;
					k = k + 1;
					g += 2;
				};
			};
		};

	};

};

void initialBlackFigure() {
	k = 13;
	while (k != 25) {

		for (int i = 6; i < 9; i++) {

			if (i % 2 != 0)
				g = 0;
			else
				g = 1;

			for (int j = 1; j < 5; j++) {
				if (i % 2 != 0)
				{
					Figure* pFigureBlack = new Figure(horizontal[g], i, "Black");
					pFigure[k] = pFigureBlack;
					k = k + 1;
					g += 2;
				}
				else
				{
					Figure* pFigureBlack = new Figure(horizontal[g], i, "Black");
					pFigure[k] = pFigureBlack;
					k = k + 1;
					g += 2;
				};

			};
		};
	};
};