#include "map.h"

Map::Map()		//맵 생성자
{
	element = { {"E", "R", "M", "M", "R", "E", "M", "M"},
				{"M", "E", "R", "E", "M", "R", "E", "R"},
				{"R", "M", "E", "E", "M", "E", "M", "M"},
				{"M", "E", "R", "S", "M", "M", "E", "R"},
				{"M", "M", "E", "R", "E", "R", "M", "E"},
				{"E", "R", "M", "E", "M", "E", "E", "R"},
				{"M", "E", "R", "M", "M", "E", "R", "M"},
				{"E", "E", "M", "E", "R", "M", "E", "B"} };							//맵 구조 설정

	condition = { {"You", " ? ", " ? ", " ? "," ? ", " ? "," ? ", " ? "},
				  {" ? ", " ? ", " ? ", " ? ", " ? ", " ? ", " ? ", " ? "},
				  {" ? ", " ? ", " ? ", " ? ", " ? ", " ? ", " ? ", " ? "},
				  {" ? ", " ? ", " ? ", " ? ", " ? ", " ? ", " ? ", " ? "},
				  {" ? ", " ? ", " ? ", " ? ", " ? ", " ? ", " ? ", " ? "},
				  {" ? ", " ? ", " ? ", " ? ", " ? ", " ? ", " ? ", " ? "},
				  {" ? ", " ? ", " ? ", " ? ", " ? ", " ? ", " ? ", " ? "},
				  {" ? ", " ? ", " ? ", " ? ", " ? ", " ? ", " ? ", " ? "}, };		//초기 맵 설정
	char_row = 0;	//캐릭터의 위치(row)
	char_col = 0;	//캐릭터의 위치(column)
}

void Map::show()	//맵을 보여주는 메서드
{
	std::cout << "┌───┬───┬───┬───┬───┬───┬───┬───┐" << std::endl;
	std::cout << "│" << condition[0][0] << "│" << condition[0][1] << "│" << condition[0][2] << "│" << condition[0][3] << "│" << condition[0][4] << "│" << condition[0][5] << "│" << condition[0][6] << "│" << condition[0][7] << "│" << std::endl;
	std::cout << "├───┼───┼───┼───┼───┼───┼───┼───┤" << std::endl;
	std::cout << "│" << condition[1][0] << "│" << condition[1][1] << "│" << condition[1][2] << "│" << condition[1][3] << "│" << condition[1][4] << "│" << condition[1][5] << "│" << condition[1][6] << "│" << condition[1][7] << "│" << std::endl;
	std::cout << "├───┼───┼───┼───┼───┼───┼───┼───┤" << std::endl;
	std::cout << "│" << condition[2][0] << "│" << condition[2][1] << "│" << condition[2][2] << "│" << condition[2][3] << "│" << condition[2][4] << "│" << condition[2][5] << "│" << condition[2][6] << "│" << condition[2][7] << "│" << std::endl;
	std::cout << "├───┼───┼───┼───┼───┼───┼───┼───┤" << std::endl;
	std::cout << "│" << condition[3][0] << "│" << condition[3][1] << "│" << condition[3][2] << "│" << condition[3][3] << "│" << condition[3][4] << "│" << condition[3][5] << "│" << condition[3][6] << "│" << condition[3][7] << "│" << std::endl;
	std::cout << "├───┼───┼───┼───┼───┼───┼───┼───┤" << std::endl;
	std::cout << "│" << condition[4][0] << "│" << condition[4][1] << "│" << condition[4][2] << "│" << condition[4][3] << "│" << condition[4][4] << "│" << condition[4][5] << "│" << condition[4][6] << "│" << condition[4][7] << "│" << std::endl;
	std::cout << "├───┼───┼───┼───┼───┼───┼───┼───┤" << std::endl;
	std::cout << "│" << condition[5][0] << "│" << condition[5][1] << "│" << condition[5][2] << "│" << condition[5][3] << "│" << condition[5][4] << "│" << condition[5][5] << "│" << condition[5][6] << "│" << condition[5][7] << "│" << std::endl;
	std::cout << "├───┼───┼───┼───┼───┼───┼───┼───┤" << std::endl;
	std::cout << "│" << condition[6][0] << "│" << condition[6][1] << "│" << condition[6][2] << "│" << condition[6][3] << "│" << condition[6][4] << "│" << condition[6][5] << "│" << condition[6][6] << "│" << condition[6][7] << "│" << std::endl;
	std::cout << "├───┼───┼───┼───┼───┼───┼───┼───┤" << std::endl;
	std::cout << "│" << condition[7][0] << "│" << condition[7][1] << "│" << condition[7][2] << "│" << condition[7][3] << "│" << condition[7][4] << "│" << condition[7][5] << "│" << condition[7][6] << "│" << condition[7][7] << "│" << std::endl;
	std::cout << "└───┴───┴───┴───┴───┴───┴───┴───┘" << std::endl;
}

int Map::w_move()		//위로 캐릭터가 이동할 수 있는지 확인하는 메서드
{
	if (char_row == 0) return 1;	//불가능
	else							//가능
	{
		condition[char_row][char_col] = "   ";
		char_row -= 1;
		condition[char_row][char_col] = "You";
		return 0;
	}
}

int Map::a_move()		//왼쪽으로 캐릭터가 이동할 수 있는지 확인하는 메서드
{
	if (char_col == 0) return 1;	//불가능
	else							//가능
	{
		condition[char_row][char_col] = "   ";
		char_col -= 1;
		condition[char_row][char_col] = "You";
		return 0;
	}
}

int Map::s_move()		//아래로 캐릭터가 이동할 수 있는지 확인하는 메서드
{
	if (char_row == 7) return 1;	//불가능
	else							//가능
	{
		condition[char_row][char_col] = "   ";
		char_row += 1;
		condition[char_row][char_col] = "You";
		return 0;
	}
}
int Map::d_move()	//오른쪽로 캐릭터가 이동할 수 있는지 확인하는 메서드
{
	if (char_col == 7) return 1;	//불가능
	else							//가능
	{
		condition[char_row][char_col] = "   ";
		char_col += 1;
		condition[char_row][char_col] = "You";
		return 0;
	}
}

int Map::check_map()	//이동 칸의 이벤트를 확인하는 메서드
{
	if (element[char_row][char_col] == "E") return 1;
	else if (element[char_row][char_col] == "R") return 2;
	else if (element[char_row][char_col] == "M") return 3;
	else if (element[char_row][char_col] == "S") return 4;
	else return 5;
}

void Map::make_empty()	//빈칸으로 만드는 메서드
{
	element[char_row][char_col] = "E";
}

int Map::manhattan_dist()	//출발점으로부터 거리를 출력하는 메서드
{
	return (char_row + char_col);
}