#include<string>
#include<iostream>
using namespace std;


class CGobang
{	
private :
	char chSort;//棋子的类别
public:
	int nWin;//赢棋次数
	int nLose;//输棋次数
	static int SpotsOnBoard;//下棋步数
	static int nDraw;//平局次数，公用数据，所以用静态
	static char board[4][4];//用数组来定义一个4*4的棋盘,静态元素，公用
	static int nSize;//棋盘的尺寸nSize^nSize
	CGobang(char chSort);//构造函数，决定一方棋子类别
	void PlayTrue(void);//走一步棋
	int Judge();//判断有没有三子连线，是返回1，否则0
	void Win();//赢棋
	void Lose();//输棋
	static void Draw();//平局
	void PrintInfo();//打印总体信息
	void PrintBoard();//打印棋盘
	int GetFull();//判断棋盘有没有布满
	void IntitalBoard();//初始化棋盘
	void Clear_but_reserve_score();//不清除分数

};	
//---1初始化静态变量
char CGobang::board[4][4] = { {' ',' ',' ',' '},{' ',' ',' ',' '} ,{' ',' ',' ',' '},{' ',' ',' ',' '} };
int CGobang::nDraw = 0;
int CGobang::nSize = 16;
int CGobang::SpotsOnBoard = 0;
//--2

CGobang::CGobang(char m_chSort)

{

	chSort = m_chSort;
	nWin = 0;
	nLose = 0;

}
void CGobang::Clear_but_reserve_score()
{
	SpotsOnBoard = 0;//初始步数为0
	///清空棋盘，棋盘初始化
	for (int i = 0; i <= 3; i++)
	{
		for (int j = 0; j <= 3; j++)
		{
			board[i][j] = ' ';
		}
	}
	///

}
void CGobang::IntitalBoard()
{
	SpotsOnBoard = 0;//初始步数为0
	nWin = 0;
	nLose = 0;
	///清空棋盘，棋盘初始化
	for (int i = 0; i <= 3; i++)
	{
		for (int j = 0; j <= 3; j++)
		{
			board[i][j] = ' ';
		}
	}
	///
}
void CGobang::Win()
{	
	cout << "玩家" << chSort << "胜利" << endl;
	nWin++;
}
void CGobang::Lose()
{
	cout << "玩家" << chSort << "失败" << endl;
	nLose++;
}
void CGobang::Draw()
{
	cout << "平局" << endl;
	nDraw++;

}
int CGobang::Judge()//判断是否三子连心
{
	int O_array[4][4];
	for (int i = 0; i <= 3; i++)
	{
		for (int j = 0; j <= 3; j++)
			if (board[i][j] == 'O')
				O_array[i][j] = 1;
			else
				O_array[i][j] = 0;

	}
	int X_array[4][4];
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
			if (board[i][j] == 'O')
				X_array[i][j] = 1;
			else
				X_array[i][j] = 0;

	}
	//横
	for (int i = 0; i <= 3; i++)
	{
		for (int j = 0; j <= 1; j++)
		{
			if ((O_array[i][j] & O_array[i][j + 1] & O_array[i][j + 2]) == 1)
			{
				
				return 1;

			}

			if ((X_array[i][j] & X_array[i][j + 1] & X_array[i][j + 2]) == 1)
			{

				return  2;
			}
		}


		
	}
	//竖
	for (int j = 0; j <= 3; j++)
	{
		for (int i = 0; i <= 1; i++)
		{
			if ((O_array[i][j] & O_array[i + 1][j] & O_array[i + 2][j]) == 1)
			{

				return 1;

			}

			if ((X_array[i][j] & X_array[i + 1][j] & X_array[i + 2][j]) == 1)
			{

				return  2;
			}
		}



	}
	//正斜
	for (int i = 0; i <= 1; i++)
	{
		for (int j = i; j <= 1; j++)
		{
			if ((O_array[i][j] & O_array[i + 1][j + 1] & O_array[i + 2][j + 2]) == 1)
				return	1;
			if ((X_array[i][j] & X_array[i + 1][j + 1] & X_array[i + 2][j + 2]) == 1)
				return	2;
		}

	}
	//反斜
	for (int i = 3; i >= 2; i--)
	{
		for (int j = i; j <= 1; j++)
		{
			if ((O_array[i][j] & O_array[i -1][j + 1] & O_array[i -2][j + 2]) == 1)
				return	1;
			if ((X_array[i][j] & X_array[i -1][j + 1] & X_array[i - 2][j + 2]) == 1)
				return	2;
		}

	}
	return 0;
}
void CGobang::PrintInfo()
{
	cout << "第一个玩家选择O棋子,第二个玩家选择X棋子." << endl;
	cout << "输入坐标(x,y)." << endl;
	cout << "敲击enter继续." << endl;
}
void CGobang::PlayTrue()
{	
	
	int x;
	int y;
	cout<< chSort << "玩家 " << endl;
	cout << "横坐标；" << endl;
	cin >> x;
	cout << "纵坐标；" << endl;
	cin >> y;
		while (x> 4 || x < 1|| y > 4 || y < 1 || (board[x - 1][y - 1] != ' '))
		{	
			cout << "输入错误: " << x << endl;
			cout << "横坐标；" << endl;
			cin>>x;
			cout << "纵坐标；" << endl;
			cin >> y;
		}

	board[x-1][y-1] = chSort;
	SpotsOnBoard++;
}
 void CGobang::PrintBoard()
{	
	 ////-4用for循环输出，而不是穷举输出，使代码更加简洁，便于升级
	 cout << endl;
	 cout << "  1  2  3  4" << endl;
	 for (int i = 0; i <=3; i++)
	 {
		 cout << i+1<<" ";
		 for (int j = 0; j <= 2; j++)
		 {
			 cout<<board[i][j] << " "  <<  "|";
		 }
		 cout << board[i][3] << endl;

	 }
	 cout << endl << endl;
}
int CGobang::GetFull()
{

	if (SpotsOnBoard == 16)
		return 1;
	else
		return 0;

}

void ChoiceOfChar(char&);//询问玩家是否继续下一局
void PrintStats(CGobang O_player, CGobang X_player);//打印比分
int main()
{	
	system("chcp 65001");

	char choice;
	choice = 'y';//初始选择，可以让循环进行下去

	CGobang O_player('O');//O玩家
	CGobang X_player('X');//X玩家
	O_player.PrintInfo();
	O_player.IntitalBoard();
	X_player.IntitalBoard();
	while (choice == 'y' ) //判断继续循环的条件
	{
	
		while (O_player.SpotsOnBoard < 16)//小循环
		{
			if (O_player.SpotsOnBoard == 0)//这是一局新游戏，还没下棋
			{
				O_player.IntitalBoard();//初始化棋盘
			}
			O_player.PlayTrue();
			O_player.PrintBoard();
			if (O_player.Judge() == 1)
			{
				O_player.Win();
				X_player.Lose();
				break;//跳出小循环
			}
			X_player.PlayTrue();
			X_player.PrintBoard();
			if (X_player.Judge() == 2)
			{
				X_player.Lose();
				X_player.Win();
				break;//跳出小循环 
			}
			if (CGobang::SpotsOnBoard == 16)
				CGobang::Draw();//平局

		}
		PrintStats(O_player, X_player);//打印比分
		ChoiceOfChar(choice);//一局结束，是否继续，如果是继续游戏
		O_player.Clear_but_reserve_score();//清除棋子和步数，保留分数
		X_player.Clear_but_reserve_score();
		
	}
	system("PAUSE");
	return 0;




}
void PrintStats(CGobang O_player, CGobang X_player)//打印比分
{
	cout << "O胜利场数:" << O_player.nWin<<endl;
	cout << "x胜利场数:" << X_player.nWin<<endl;
	cout << "O失败场数:" << O_player.nLose<<endl;
	cout << "X失败场数:" << X_player.nLose<<endl;
	cout << "平局场数:" << CGobang::nDraw<<endl;

}
void ChoiceOfChar(char& choice)//接收玩家输入是否继续下棋
{

	cout << endl;
	cout << "是否继续，是则按y，否则按其他任意键 " << endl;
	cin >> choice;


}
