#include "pch.h"
#include <iostream>
#include <string>

int g, k;

std::string horizontal[8] = {
	"a","b","c","d","e","f","g","h"
};

int vertical[8] = {
	1,2,3,4,5,6,7,8
};

class Figure {
public:
	Figure(std::string initalHorizontal, int initialVertical, std::string initialColor);
	std::string GetColor() const;
	std::string GetHorizontalCor() const;
	int GetVerticalCor() const;
	void MakeAMove();
	void AvalibleMove();
	bool IsThereFigure(std::string initalHor, int initialVer);
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

std::string Figure::GetColor() const {
	return Color;
};

std::string Figure::GetHorizontalCor() const {
	return HorizontalCor;
};

int Figure::GetVerticalCor() const {
	return VerticalCor;
};

void initialWhiteFigure();
void initialBlackFigure();

std::string Name1, Name2;


int main()
{

	initialWhiteFigure();
	initialBlackFigure();


	/*
	for(int i = 1; i < 25; i++) {
		if (pFigure[i]->IsThereFigure("c", 3))
			std::cout << "Yes!" << '\n';
	}
	*/

//	std::cout << pFigure[11]->Check(4,"e");

	
	std::cout << 11 << ' ' << pFigure[11]->GetColor() << ' ' << pFigure[11]->GetVerticalCor() << pFigure[11]->GetHorizontalCor() << '\n';
	pFigure[11]->MakeAMove();
	std::cout << 11 << ' ' << pFigure[11]->GetColor() << ' ' << pFigure[11]->GetVerticalCor() << pFigure[11]->GetHorizontalCor() << '\n';
	pFigure[11]->MakeAMove();
	std::cout << 11 << ' ' << pFigure[11]->GetColor() << ' ' << pFigure[11]->GetVerticalCor() << pFigure[11]->GetHorizontalCor() << '\n';
	pFigure[11]->MakeAMove();
	std::cout << 11 << ' ' << pFigure[11]->GetColor() << ' ' << pFigure[11]->GetVerticalCor() << pFigure[11]->GetHorizontalCor() << '\n';
//	pFigure[11]->MakeAMove();
//	std::cout << 11 << ' ' << pFigure[11]->GetColor() << ' ' << pFigure[11]->GetVerticalCor() << pFigure[11]->GetHorizontalCor() << '\n';
//	pFigure[11]->MakeAMove();
	

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

void Figure::AvalibleMove() {
	int k;

	for (int i = 0;i < 8;i++) {
		if (horizontal[i] == HorizontalCor)
			k = i;
	};

	if (Color == "White")
	{
		VerticalCor += 1;

		if (k == 0)
		{
			k += 1;
			std::cout << "First avalible move is " << VerticalCor << ' ' << horizontal[k] << '\n';
			k -= 1;
		};

		if (k == 7)
		{
			k -= 1;
			std::cout << "First avalible move is " << VerticalCor << ' ' << horizontal[k] << '\n';
			k += 1;
		};

		if (k > 0 && k < 7)
		{
			k -= 1;
			std::cout << "First avalible move is " << VerticalCor << ' ' << horizontal[k] << '\n';
			k += 2;
			std::cout << "Second avalible move is " << VerticalCor << ' ' << horizontal[k] << '\n';
		};
	}
	else
	{
		VerticalCor -= 1;

		if (k == 0)
		{
			k += 1;
			std::cout << "First avalible move is " << VerticalCor << ' ' << horizontal[k] << '\n';
			k -= 1;
		};

		if (k == 7)
		{
			k -= 1;
			std::cout << "First avalible move is " << VerticalCor << ' ' << horizontal[k] << '\n';
			k += 1;
		};

		if (k > 0 && k < 7)
		{
			k -= 1;
			std::cout << "First avalible move is " << VerticalCor << ' ' << horizontal[k] << '\n';
			k += 2;
			std::cout << "Second avalible move is " << VerticalCor << ' ' << horizontal[k] << '\n';
		};
	};

};

void Figure::MakeAMove() {
	bool exit = false;
	std::string AvailFirstHorCor, AvailSecondHorCor;
	int AvailFirstVerCor, AvailSecondVerCor, IntermediateVer;

	int k, l = 0, Operation;

	for (int i = 0;i < 8;i++) {
		if (horizontal[i] == HorizontalCor)
			k = i;
	};


	if (Color == "White")
	{
		IntermediateVer = VerticalCor + 1;

		if (k == 0)
		{
			k += 1;
			AvailFirstVerCor = IntermediateVer;
			AvailFirstHorCor = horizontal[k];
			k -= 1;
			l += 1;

		};

		if (k == 7)
		{
			k -= 1;
			AvailFirstVerCor = IntermediateVer;
			AvailFirstHorCor = horizontal[k];
			k += 1;
			l += 1;

		};

		if (k > 0 && k < 7)
		{
			k -= 1;
			AvailFirstVerCor = IntermediateVer;
			AvailFirstHorCor = horizontal[k];
			k += 2;
			AvailSecondVerCor = IntermediateVer;
			AvailSecondHorCor = horizontal[k];
			l += 2;


		};
	}
	else
	{
		IntermediateVer = VerticalCor - 1;

		if (k == 0)
		{
			k += 1;
			AvailFirstVerCor = IntermediateVer;
			AvailFirstHorCor = horizontal[k];
			k -= 1;
			l += 1;
		};

		if (k == 7)
		{
			k -= 1;
			AvailFirstVerCor = IntermediateVer;
			AvailFirstHorCor = horizontal[k];
			k += 1;
			l += 1;
		};

		if (k > 0 && k < 7)
		{
			k -= 1;
			AvailFirstVerCor = IntermediateVer;
			AvailFirstHorCor = horizontal[k];
			k += 2;
			AvailSecondVerCor = IntermediateVer;
			AvailSecondHorCor = horizontal[k];
			l += 2;
		};
	};

	

	if (l == 1)
	{
		std::cout << "Choose a move: 1) " << AvailFirstVerCor << AvailFirstHorCor << '\n';
		std::cin >> Operation;
		int m = 0;

		while (exit == false) {
			switch (Operation)
			{
			case 1:
			{
				for (int i = 1; i < 25; i++) {
					if (pFigure[i]->IsThereFigure(AvailFirstHorCor, AvailFirstVerCor))
						m+=1;
				};

				if (m == 0) {
					HorizontalCor = AvailFirstHorCor;
					VerticalCor = AvailFirstVerCor;
					std::cout << "Successful move!" << '\n';
				}
				else
				{
					std::cout << "Unccessful move. Place occupied!" << '\n';
				};

				exit = true;
				break;
			}
			default:
				std::cerr << "error\n";
				std::cout << "Choose a move: 1) " << AvailFirstVerCor << AvailFirstHorCor << '\n';
				std::cin >> Operation;
				exit = false;
			}
		}
	};

	if (l == 2)
	{
		std::cout << "Choose a move: 1) " << AvailFirstVerCor << AvailFirstHorCor << " 2) " << AvailSecondVerCor << AvailSecondHorCor << '\n';
		std::cin >> Operation;
		int m = 0;

		while (exit == false) {
			switch (Operation)
			{
			case 1:
			{

				for (int i = 1; i < 25; i++) {
					if (pFigure[i]->IsThereFigure(AvailFirstHorCor, AvailFirstVerCor))
						m += 1;
				};


				if (m == 0) {
					HorizontalCor = AvailFirstHorCor;
					VerticalCor = AvailFirstVerCor;
					std::cout << "Successful move!" << '\n';
				}
				else
				{
					std::cout << "Unccessful move. Place occupied!" << '\n';
				};

				exit = true;
				break;
			}
			case 2:
			{

				for (int i = 1; i < 25; i++) {
					if (pFigure[i]->IsThereFigure(AvailSecondHorCor, AvailSecondVerCor))
						m += 1;
				};

				if (m == 0) {
					HorizontalCor = AvailSecondHorCor;
					VerticalCor = AvailSecondVerCor;
					std::cout << "Successful move!" << '\n';
				}
				else
				{
					std::cout << "Unccessful move. Place occupied!" << '\n';
				};


				exit = true;
				break;
			}
			default:
				std::cerr << "error\n";
				std::cout << "Choose a move: 1) " << AvailFirstVerCor << AvailFirstHorCor << " 2) " << AvailSecondVerCor << AvailSecondHorCor << '\n';
				std::cin >> Operation;
				exit = false;
			}
		}
	};

};

bool Figure::IsThereFigure(std::string initalHor, int initialVer) {
	return this->VerticalCor == initialVer && this->HorizontalCor == initalHor;
};