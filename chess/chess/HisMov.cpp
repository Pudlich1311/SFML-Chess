#include"HisMov.h"


void HisMov::sv()
{
	whitesize = whitePieces.size();
	blacksize = blackPieces.size();


	std::ofstream out("State.txt");
	if (out.is_open())
	{
		for (auto& i : cells)
		{
			for (auto& j : i)
			{
				out << j.is_attacked;
			}
			out << std::endl;
		}
		
		
		for (auto& i : cells)
		{
			for (auto& j : i)
			{
				out << j.occupied_color;
			}
			out << std::endl;
		}

		

		for (auto& i : cells)
		{
			for (auto& j : i)
			{
				out << j.occupied_value;
			}
			out << std::endl;
		}

		out << whitesize << std::endl;
		out << blacksize << std::endl;
		

		for (auto& i : whitePieces)
		{
			out << i->isAlive << i->isWhite << i->x <<  i->y << i->occupied_value << std::endl;
		}
		

		for (auto& j : blackPieces)
		{
			out << j->isAlive << j->isWhite <<  j->x  << j->y <<  j->occupied_value << std::endl;
		}
	

		std::string a = mov.getString();
		std::string b = player1.getString();
		std::string c = player2.getString();
		//out << a;
		out << a << std::endl<<"..." << std::endl;
		out << b << std::endl;
		out << c << std::endl;
		out << performed_passant << std::endl;
		out << turn << std::endl;
		out << number_of_moves << std::endl;
		out << gameStatus << std::endl;
		out << whiteTurn << std::endl;



		out.close();
	}
	
	
}


void HisMov::ld()
{
	std::ifstream in;
	std::string s;


	cells.resize(8, vector<Square>(8));

	w_king = new King(1);
	whitePieces.push_back(w_king);

	w_queen = new Queen(1);
	whitePieces.push_back(w_queen);

	b_king = new King(0);
	blackPieces.push_back(b_king);

	b_queen = new Queen(0);
	blackPieces.push_back(b_queen);

	

	for (int i = 0; i < 8; i++)
	{
		b_pawn[i] = new Pawn(0);
		blackPieces.push_back(b_pawn[i]);
		w_pawn[i] = new Pawn(1);
		whitePieces.push_back(w_pawn[i]);

	}
	for (int i = 0; i < 2; i++)
	{
		w_bishop[i] = new Bishop(1);
		whitePieces.push_back(w_bishop[i]);
		w_rook[i] = new Rook(1);
		whitePieces.push_back(w_rook[i]);
		w_knight[i] = new Knight(1);
		whitePieces.push_back(w_knight[i]);
		b_bishop[i] = new Bishop(0);
		blackPieces.push_back(b_bishop[i]);
		b_rook[i] = new Rook(0);
		blackPieces.push_back(b_rook[i]);
		b_knight[i] = new Knight(0);
		blackPieces.push_back(b_knight[i]);

	}
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			cells[i][j].x = i;
			cells[i][j].y = j;
		}
	}


	in.open("State.txt");
	if (!in)
	{
		std::cout << "error";
	}
	else
	{
		bool flag = false;



		for (int i =0; i<8; i++)
		{
			std::getline(in, s, '\n');

			for (int j =0; j<8;j++)
			{
				
				cells[i][j].is_attacked = s[j];
			}
		}

		for (int i = 0; i < 8; i++)
		{
			std::getline(in, s, '\n');
			int t = 0;

			for (int j = 0; j < s.size(); j++)
			{
				int a = (int)s[j] - 48;
				if (s[j] == '-')
				{
					flag = true;
					continue;
				}
				if (flag == true)
				{
					flag = false;
					a = a * (-1);
				}
				cells[i][t].occupied_color = a;
				t++;
			}
		}

		for (int i = 0; i < 8; i++)
		{
			std::getline(in, s, '\n');
			int t = 0;

			for (int j = 0; j < s.size(); j++)
			{
				int a = (int)s[j] - 48;
				if (s[j] == '-')
				{
					flag = true;
					continue;
				}
				if (flag == true)
				{
					flag = false;
					a = a * (-1);
				}
				cells[i][t].occupied_value = a;
				t++;
			}
		}

		std::getline(in, s, '\n');
		whitesize = atoi(s.c_str());

		std::getline(in, s, '\n');
		blacksize = atoi(s.c_str());


		int k = 0;
		int l = 0;
		int u = 0;
		int o = 0;

		for (int i = 0; i < whitesize; i++)
		{
			

			std::getline(in, s, '\n');
			
			int a = (int)s[0] - 48;
			int b = (int)s[1] - 48;
			int c = (int)s[2] - 48;
			int d = (int)s[3] - 48;
			int f = (int)s[4] - 48;

			
			if (i > 15)
			{
				if ( s[4] == '2')
				{
					
						w_p_queen[k] = new Queen(1);
						whitePieces.push_back(w_p_queen[k]);
						k++;
					
				}
				if (s[4] == '-' && s[5] == '2')
				{
					
						w_p_bishop[l] = new Bishop(1);
						whitePieces.push_back(w_p_bishop[l]);
						l++;
				}
				if (s[4] == '1')
				{
					
						w_p_rook[u] = new Rook(1);
						whitePieces.push_back(w_p_rook[u]);
						u++;
				}
				if (s[4] == '-' && s[5] == '1')
				{
	
						w_p_knight[o] = new Knight(1);
						whitePieces.push_back(w_p_knight[o]);
						o++;
				}
			}
			whitePieces[i]->isAlive = a;
			whitePieces[i]->isWhite = b;
			whitePieces[i]->x = c;
			whitePieces[i]->y = d;

	

			
		}

		k = 0;
		l = 0;
		u = 0;
		o = 0;

		for (int i = 0; i < blacksize; i++)
		{
			std::getline(in, s, '\n');

			int a = (int)s[0] - 48;
			int b = (int)s[1] - 48;
			int c = (int)s[2] - 48;
			int d = (int)s[3] - 48;

		

			

			if (i > 15)
			{
				if (s[4] == '2')
				{
					
					b_p_queen[k] = new Queen(1);
					blackPieces.push_back(b_p_queen[k]);
					k++;
				}
				if (s[4] == '-' && s[5] == '2')
				{
					b_p_bishop[l] = new Bishop(1);
					blackPieces.push_back(b_p_bishop[l]);
					l++;
				}
				if (s[4] == '1')
				{
					b_p_rook[u] = new Rook(1);
					blackPieces.push_back(b_p_rook[u]);
					u++;
				}
				if (s[4] == '-' && s[5] == '1')
				{
					b_p_knight[o] = new Knight(1);
					blackPieces.push_back(b_p_knight[o]);
					o++;
				}
			}

			blackPieces[i]->isAlive = a;
			blackPieces[i]->isWhite = b;
			blackPieces[i]->x = c;
			blackPieces[i]->y = d;

		}

		std::string mv;
		while (std::getline(in, s) && s != "...")
		{
			mv += s;
		

			mv += '\n';
			
		}
		mv = mv.substr(0, mv.length() - 1);
		mov.setString(mv);

		std::getline(in, s);
		player1.setString(s);

		std::getline(in, s);
		player2.setString(s);

		std::getline(in, s);
		int a = (int)s[0] - 48;
		performed_passant =a ;

		std::getline(in, s);
		a = (int)s[0] - 48;
		turn = a;

		std::getline(in, s);
		a = (int)s[0] - 48;
		number_of_moves = a;

		std::getline(in, s);
		a = (int)s[0] - 48;
		gameStatus = a;

		std::getline(in, s);
		a = (int)s[0] - 48;
		whiteTurn = a;


		in.close();
	}
}

HisMov::~HisMov()
{
	delete w_king;
	delete b_king;
	delete w_queen;
	delete b_queen;
	for (int i = 0; i < 2; i++)
	{
		delete w_knight[i];
		delete b_knight[i];
		delete w_bishop[i];
		delete b_bishop[i];
		delete w_rook[i];
		delete b_rook[i];
	}
	for (int i = 0; i < 8; i++)
	{
		delete w_pawn[i];
		delete b_pawn[i];
		delete w_p_bishop[i];
		delete w_p_queen[i];
		delete w_p_knight[i];
		delete w_p_rook[i];

		delete b_p_bishop[i];
		delete b_p_queen[i];
		delete b_p_knight[i];
		delete b_p_rook[i];
	}

	
}